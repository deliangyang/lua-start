--
-- Created by IntelliJ IDEA.
-- User: ydl
-- Date: 2020/2/17
-- Time: 3:04 下午
-- To change this template use File | Settings | File Templates.
--
local socket = require('socket')
local host = '127.0.0.1'
local port = 8490

local server = socket.bind(host, port, 1024)
server:settimeout(0)

while true do
    local conn = server:accept()
    print(conn)
end

