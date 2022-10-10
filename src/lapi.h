/*
** $Id: lapi.h,v 2.9.1.1 2017/04/19 17:20:42 roberto Exp $
** Auxiliary functions from Lua API 辅助函数
** See Copyright Notice in lua.h
*/

#ifndef lapi_h
#define lapi_h


#include "llimits.h"
#include "lstate.h"

// 栈顶++，并且判断 栈的高度必须大于函数调用的高度，否则就是栈溢出
#define api_incr_top(L)   {L->top++; api_check(L, L->top <= L->ci->top, \
				"stack overflow");}

#define adjustresults(L,nres) \
    { if ((nres) == LUA_MULTRET && L->ci->top < L->top) L->ci->top = L->top; }

#define api_checknelems(L,n)	api_check(L, (n) < (L->top - L->ci->func), \
				  "not enough elements in the stack")


#endif
