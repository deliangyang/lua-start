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

    lua_getglobal(l, "test2");      // 获取函数，压入栈中
    lua_pushnumber(l, 1);           // 压入第一个参数
    lua_pushnumber(l, 2);           // 压入第二个 
    // 2-将两个参数出栈，0-函数出栈，-1-压入函数的放回结果
    lua_pcall(l, 2, 0, -1);

    lua_getglobal(l, "test3");
    lua_pushnumber(l, 1);
    lua_pushnumber(l, 2);
    lua_pcall(l, 2, 1, -1);
    int num = lua_tonumber(l, -1);
    printf("%d\n", num);

    lua_pushstring(l, "hello world");
    lua_pushnumber(l, 20);

    if (lua_isstring(l, 2)) {
        printf("is string: %s\n", lua_tostring(l, 2));
    }

    if (lua_isnumber(l, 3)) {
        printf("isnumber: %s\n", lua_tostring(l, 3));
    }

    lua_close(l);

    return 0;
}