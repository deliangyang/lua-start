--
-- Created by IntelliJ IDEA.
-- User: ydl
-- Date: 2020/2/16
-- Time: 11:57 下午
-- To change this template use File | Settings | File Templates.
--

print('hello world')

--[[

luac -l bin/test.lua

main <../bin/test.lua:0,0> (4 instructions at 0x7f8557500b80)
0+ params, 2 slots, 1 upvalue, 0 locals, 2 constants, 0 functions
1       [9]     GETTABUP        0 0 -1  ; _ENV "print"
2       [9]     LOADK           1 -2    ; "hello world"
3       [9]     CALL            0 2 1
4       [9]     RETURN          0 1
--]]
