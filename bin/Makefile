
ext:
	rm -rf test.so
	gcc test.c -fPIC -shared -o test.so -I ../src -L ../src -llua
	lua testx.lua 