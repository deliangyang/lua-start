//
// Created by ydl on 2020/5/22.
//
#define LUA_VERSION_MAJOR	"5"
#define LUA_VERSION_MINOR	"3"
#define LUA_VERSION_NUM		503
#define LUA_VERSION_RELEASE	"5"
#define MYINT(s)	(s[0]-'0')
#define LUAC_VERSION	(MYINT(LUA_VERSION_MAJOR)*16+MYINT(LUA_VERSION_MINOR))

#include <stdio.h>
int main(void) {
    printf("%d\n", LUAC_VERSION);
    return 0;
}