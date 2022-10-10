/*
** $Id: ltm.c,v 2.38.1.1 2017/04/19 17:39:34 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
*/


#define ltestlib_c
#define LUA_LIB
#include "lua.h"
#include "lprefix.h"
#include "ltestlib.h"
#include <stdio.h>


static int printx(lua_State *L) {
  printf("result: %d\n", lua_compare(L, 1, 2, LUA_OPADD));
  return 0;
}

static const luaL_Reg test[] = {
  {"printx", printx},
  {NULL, NULL}
};

LUALIB_API int luaopen_test(lua_State *L) {
  luaL_newlib(L, test);
#if defined(LUA_COMPAT_UNPACK)
  /* _G.unpack = table.unpack */
  lua_getfield(L, -1, "unpack");
  lua_setglobal(L, "unpack");
#endif
  return 1;
}
