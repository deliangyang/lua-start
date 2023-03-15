/*
** $Id: llex.h,v 1.79.1.1 2017/04/19 17:20:42 roberto Exp $
** Lexical Analyzer
** See Copyright Notice in lua.h
*/

#ifndef llex_h
#define llex_h

#include "lobject.h"
#include "lzio.h"

// 第一个保留
#define FIRST_RESERVED	257


#if !defined(LUA_ENV)
#define LUA_ENV		"_ENV"
#endif


/*
* WARNING: if you change the order of this enumeration,
* grep "ORDER RESERVED"       token
*/
enum RESERVED {
  /* terminal symbols denoted by reserved words */
  // and break
  TK_AND = FIRST_RESERVED, TK_BREAK,      
  // do else elseif end false for function
  TK_DO, TK_ELSE, TK_ELSEIF, TK_END, TK_FALSE, TK_FOR, TK_FUNCTION,
  // goto if in local nil not or repeat
  TK_GOTO, TK_IF, TK_IN, TK_LOCAL, TK_NIL, TK_NOT, TK_OR, TK_REPEAT,
  // return then true until while
  TK_RETURN, TK_THEN, TK_TRUE, TK_UNTIL, TK_WHILE,
  /* other terminal symbols */
  // idiv(/) concat(..) dots(.), eq(=), ge(>), le(<), ne(-)
  TK_IDIV, TK_CONCAT, TK_DOTS, TK_EQ, TK_GE, TK_LE, TK_NE,
  // 左移shl(<<) 右移shr(>>)
  TK_SHL, TK_SHR,
  // :, <>
  TK_DBCOLON, TK_EOS,
  // flt, int, name, string
  TK_FLT, TK_INT, TK_NAME, TK_STRING
};

/* number of reserved words */
#define NUM_RESERVED	(cast(int, TK_WHILE-FIRST_RESERVED+1))

// SemInfo 语义信息
typedef union {
  lua_Number r;
  lua_Integer i;
  TString *ts;
} SemInfo;  /* semantics information */


typedef struct Token {
  int token;
  SemInfo seminfo;
} Token;


/* state of the lexer plus state of the parser when shared by all
   functions */
// 词法分析
typedef struct LexState {
  int current;  /* current character (charint) 当前字符 */
  int linenumber;  /* input line counter 总行数 */
  int lastline;  /* line of last token 'consumed' 最后一行 */
  Token t;  /* current token 当前token */
  Token lookahead;  /* look ahead token 后面一个token */
  struct FuncState *fs;  /* current function (parser) 当前解析的函数 */
  struct lua_State *L;    // 状态
  ZIO *z;  /* input stream 输入流 */
  Mbuffer *buff;  /* buffer for tokens 缓冲区 */
  Table *h;  /* to avoid collection/reuse strings 避免被回收或者重新使用strings */
  struct Dyndata *dyd;  /* dynamic structures used by the parser 解析器使用的动态结构*/
  TString *source;  /* current source name 当前源码文件名？ */
  TString *envn;  /* environment variable name 环境变量名 */
} LexState;

// 初始化
LUAI_FUNC void luaX_init (lua_State *L);
// 设置输入
LUAI_FUNC void luaX_setinput (lua_State *L, LexState *ls, ZIO *z,
                              TString *source, int firstchar);
// 初始化字符串
LUAI_FUNC TString *luaX_newstring (LexState *ls, const char *str, size_t l);
// 下一个
LUAI_FUNC void luaX_next (LexState *ls);
// 获取下一个，但是当前指针不移动
LUAI_FUNC int luaX_lookahead (LexState *ls);
// 语法错误
LUAI_FUNC l_noret luaX_syntaxerror (LexState *ls, const char *s);
// token 转化为string
LUAI_FUNC const char *luaX_token2str (LexState *ls, int token);


#endif
