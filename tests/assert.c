//
// Created by ydl on 2020/5/22.
//
// useless?
#include <assert.h>
#define lua_assert(c)		((void)0)

int main(int argc, char *argv[]) {
    lua_assert(0);
    lua_assert(1);
    assert(0);      // assertion failed
    assert(1);
    return 0;
}