//
// Created by ydl on 2020/9/16.
//

#include <stdio.h>

int func(int a, int b) {
    return a + b;
}

int main(int argc, char *argv[]) {
    int(*tt)(int a, int b) = func;
    printf("%d\n", tt(1, 3));

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}