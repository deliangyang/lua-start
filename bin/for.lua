--
-- Created by IntelliJ IDEA.
-- User: ydl
-- Date: 2020/5/22
-- Time: 3:27 下午
-- To change this template use File | Settings | File Templates.
--

for i=1, 3 do
    print(i)
end


--[[
luac -l bin/for.lua

main <../bin/for.lua:0,0> (9 instructions at 0x7fe403500a90)
0+ params, 6 slots, 1 upvalue, 4 locals, 3 constants, 0 functions
        1       [9]     LOADK           0 -1    ; 1
        2       [9]     LOADK           1 -2    ; 3
        3       [9]     LOADK           2 -1    ; 1
        4       [9]     FORPREP         0 3     ; to 8
        5       [10]    GETTABUP        4 0 -3  ; _ENV "print"
        6       [10]    MOVE            5 3
        7       [10]    CALL            4 2 1
        8       [9]     FORLOOP         0 -4    ; to 5
        9       [11]    RETURN          0 1
--]]