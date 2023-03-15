#include <stdio.h>
#include "lua.h"    /* lua header file */
#include "lauxlib.h"
#include "lualib.h" /* extra libraries (optional) */

int luaadd(lua_State *L, int x, int y);

int main(int argc, char *argv[])
{
  lua_State *L = luaL_newstate();
  luaL_openlibs(L); // 加载Lua通用扩展库

  if (luaL_dofile(L, "add.lua"))
  {
    printf("error pcall!: %s\n", lua_tostring(L, -1));
  }
  printf("sum = %d\n", luaadd(L, 3, 1330));

  lua_close(L);
}

int luaadd(lua_State *L, int x, int y) {
  int sum;
  int a = lua_getglobal(L, "add");
  if ( a == 0) {
    printf("error, a is zero: %d\n", a);
  }
  lua_pushnumber(L, x);
  lua_pushnumber(L, y);
  printf("x:%d, y:%d\n", x, y);
  // 开始调用函数，有2个参数，1一个返回值
  lua_call(L, 2, 1);

  sum = (int)lua_tonumber(L, -1);

  // PANIC: unprotected error in call to Lua API (attempt to call a nil value)
  // 所以 lua_tonumber 会弹出-1的值（栈顶？）
  //   printf("sum: %d\n", sum);

  //   lua_pop(L, 1);

  // sum = (int)lua_tonumber(L, -1);
  // printf("sum: %d\n", sum);

  lua_pop(L, 1);

  return sum;
}

/**
 * @brief
 *
 * cd src && mkdir -p /usr/local/bin /usr/local/include /usr/local/lib /usr/local/man/man1 /usr/local/share/lua/5.3 /usr/local/lib/lua/5.3
cd src && install -p -m 0755 lua luac /usr/local/bin
cd src && install -p -m 0644 lua.h luaconf.h lualib.h lauxlib.h lua.hpp /usr/local/include
cd src && install -p -m 0644 liblua.a /usr/local/lib
cd doc && install -p -m 0644 lua.1 luac.1 /usr/local/man/man1
 *
 */