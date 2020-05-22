//
// Created by ydl on 2020/5/22.
//

// @link https://juejin.im/post/5dd62dca5188256ec8054944
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    lua_State *l = luaL_newstate();
    luaL_openlibs(l);
    luaL_dofile(l, "test2.lua");
    lua_getglobal(l, "test1");
    lua_pcall(l, 0, 0, -1);

    lua_getglobal(l, "test2");
    lua_pushnumber(l, 1);
    lua_pushnumber(l, 2);
    lua_pcall(l, 2, 0, -1);

    lua_getglobal(l, "test3");
    lua_pushnumber(l, 1);
    lua_pushnumber(l, 2);
    lua_pcall(l, 2, 1, -1);
    lua_close(l);
    int num = lua_tonumber(l, -1);
    printf("%d\n", num);
    return 0;
}