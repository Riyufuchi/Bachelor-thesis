local add = "git add ."
local commit = "git commit -m \"Update %d\""
local filename = "version.conf"
local push = "git push"

local function updateCommitMessage(filename, commitMessagePattern)
    -- Read the current number from the file
    local file = io.open(filename, "r")
    if not file then
        print("Failed to open file:", filename)
        return
    end
    local number = tonumber(file:read("*all")) or 0
    file:close()

    -- Increment the number
    number = number + 1

    -- Replace %d in the commit message pattern with the number
    local commitMessage = commitMessagePattern:gsub("%%d", tostring(number))

    -- Save the updated number back to the file
    file = io.open(filename, "w")
    if not file then
        print("Failed to open file for writing:", filename)
        return
    end
    file:write(tostring(number))
    file:close()

    -- Return the updated commit message
    return commitMessage
end

local commitMessage = updateCommitMessage(filename, commit)

os.execute("cd ..")
os.execute("cd ..")
os.execute(add)
os.execute(commitMessage)
local pipe = io.popen(push, "w")
pipe:write("krevelixtv@gmail.com")
pipe:close()



