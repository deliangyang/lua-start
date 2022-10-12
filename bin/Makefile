
ext:
	rm -rf test.so
	gcc test.c -fPIC -shared -o test.so -I ../src -L ../src -llua
	lua testx.lua 

tt:
	gcc -o test1 test.c -llua  -ldl -lm -Wall
	./test1
	rm -rf test1