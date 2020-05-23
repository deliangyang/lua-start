--
-- Created by IntelliJ IDEA.
-- User: ydl
-- Date: 2020/5/23
-- Time: 11:52 下午
-- To change this template use File | Settings | File Templates.
--

function add(a, b)
    return a + b
end

print(add(2, 5))



local json = require "json"
print(json.stringify({"a", "b"}))