#include <stdio.h>


int add(int a, int b) {
  return a + b;
}

int main(int argc, char const *argv[])
{
  printf("hello world\n");
  printf("a + b = %d\n", add(1, 3));
  return 0;
}
