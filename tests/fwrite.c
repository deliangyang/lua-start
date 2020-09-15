//
// Created by ydl on 2020/9/15.
//
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char *s = "hello worold\n";
    fwrite(s, sizeof(char), strlen(s), stdout);
    return 0;
}