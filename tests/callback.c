//
// Created by ydl on 2020/5/24.
//
#include <stdio.h>


int add(int a, int b, void(*print)(int result)) {
    int c = a + b;
    (*print)(c);
    return c;
}

void print(int c) {
    printf("%d\n", c);
}

#define to_lower(c)	((c) | ('A' ^ 'a'))

int main(int argc, char *argv[]) {
    add(1, 3, print);
    printf("%c\n", to_lower('C'));
    return 0;
}