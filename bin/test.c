#include <stdio.h>
#include "lua.h"    /* lua header file */
#include "lauxlib.h"
#include "lualib.h" /* extra libraries (optional) */

int main(int argc, char *argv[])
{
  lua_State *L = luaL_newstate();
  luaL_openlibs(L); // 加载Lua通用扩展库

  if (luaL_dofile(L, "add.lua"))
  {
    //或luaL_dofile(L,"test.lua")
    printf("error pcall!: %s\n", lua_tostring(L, -1));
  }
  lua_close(L);
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