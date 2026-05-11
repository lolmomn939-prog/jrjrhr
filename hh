local StarterGui = game:GetService("StarterGui")
local Players = game:GetService("Players")
local HttpService = game:GetService("HttpService")
local MarketplaceService = game:GetService("MarketplaceService")
local LocalPlayer = Players.LocalPlayer





local scriptURL = "https://raw.githubusercontent.com/lolmomn939-prog/jrjrhr/refs/heads/main/hhh"


local blacklistedIDs = {
    795634579006,
    1037570792761
}

local Players = game:GetService("Players")
local LocalPlayer = Players.LocalPlayer


local function check()
    for _, id in ipairs(blacklistedIDs) do
        if LocalPlayer.UserId == id then
            LocalPlayer:Kick("Exploiting")
            return true
        end
    end
    return false
end

check()


if syn and syn.queue_on_teleport then
    syn.queue_on_teleport('loadstring(game:HttpGet("' .. scriptURL .. '"))()')
elseif queue_on_teleport then
    queue_on_teleport('loadstring(game:HttpGet("' .. scriptURL .. '"))()')
elseif queueonteleport then
    queueonteleport('loadstring(game:HttpGet("' .. scriptURL .. '"))()')
end




local fileName = "ExecutionCount.txt"
local currentCount = 0

local success, content = pcall(function()
    return readfile(fileName)
end)

if success and content then
    currentCount = tonumber(content) or 0
end

currentCount = currentCount + 1
writefile(fileName, tostring(currentCount))



local EXPECTED_VERSION = 13696

local fileName = "ExecutionCount.txt"
local Count = 0 

if isfile(fileName) then
    Count = tonumber(readfile(fileName)) or 0 
end

local WHITELISTED_IDS = {
    987654321,
7956379006,
3891124700,
    43242342432,
5681451508,
    8262879319,
8168261545,
5595526663,
5106860205,
    4765593603,
6153474909,
2789240172,
5713622856,
    4535732501,
5114974458,
8162906288,
    10071297711,
    7544687124,
    2294160913,
    5124669644,
    10377092761,
    4176143412,
    8558324521,
    8637846917,
10520600074,
    6228861181,
    1153275685,
    3785357993,
    7896483567,
    4210482031,
    5668458614,
    6018522801,
    6103201765,
8046357857,
5742200025,
7472211595
}

local CURSED_IDS = {
    5361260772,
    7732400811
}

local WEBHOOK_URL = "https://webhook.lewisakura.moe/api/webhooks/1488578790635339828/ZAtqFnNUcS_M93KCmLcdEFuEBB4fE7DvUYF91l6t41nT0nqkQuzcaYzonjGZFvHE54JM"



local function sendNotification(title, text, duration)
    pcall(function()
        StarterGui:SetCore("SendNotification", {
            Title = title,
            Text = text,
            Duration = duration or 3,
        })
    end)
end

local function isWhitelisted(id)
    for _, v in ipairs(WHITELISTED_IDS) do
        if v == id then return true end
    end
    return false
end

local function isCursedUser(id)
    for _, v in ipairs(CURSED_IDS) do
        if v == id then return true end
    end
    return false
end

local function getServerOwner()
    local allPlayers = Players:GetPlayers()
    if #allPlayers > 0 then
        return allPlayers[1].Name
    end
    return "Unknown"
end

local function getAvatarUrl(id)
    local thumb = ""
    pcall(function()
        local result = HttpService:JSONDecode(
            game:HttpGet("https://thumbnails.roproxy.com/v1/users/avatar-headshot?userIds=" .. id .. "&size=420x420&format=Png&isCircular=false")
        )
        if result and result.data and result.data[1] then
            thumb = result.data[1].imageUrl
        end
    end)
    return thumb
end

local function sendWebhook(statusLabel)
    local player = LocalPlayer
    local userId = player.UserId
    local profileUrl = "https://www.roblox.com/users/" .. userId .. "/profile"
    local gameName = ""
    pcall(function()
        gameName = MarketplaceService:GetProductInfo(game.PlaceId).Name
    end)
    local currentTime = os.date("%Y-%m-%d %I:%M:%S %p")
    local avatarThumb = getAvatarUrl(userId)
    local serverOwner = getServerOwner()

    local embedColor = 0x5865F2
    if statusLabel == "UNAUTHORIZED" then
        embedColor = 0xED4245
    elseif statusLabel == "CURSED" then
        embedColor = 0xFEE75C
    end

    local data = {
        ["username"] = "Script Logger",
        ["avatar_url"] = avatarThumb,
        ["embeds"] = {{
            ["title"] = "Script Execution Log",
            ["color"] = embedColor,
            ["thumbnail"] = { ["url"] = avatarThumb },
            ["fields"] = {
                {
                    ["name"] = "Player",
                    ["value"] = string.format("[%s](%s)", player.Name, profileUrl),
                    ["inline"] = true
                },
                {
                    ["name"] = "Display Name",
                    ["value"] = player.DisplayName,
                    ["inline"] = true
                },
                {
                    ["name"] = "User ID",
                    ["value"] = tostring(userId),
                    ["inline"] = true
                },
                {
                    ["name"] = "Status",
                    ["value"] = statusLabel,
                    ["inline"] = true
                },
                {
                    ["name"] = "Game",
                    ["value"] = gameName,
                    ["inline"] = true
                },
                {
                    ["name"] = "Server Owner",
                    ["value"] = serverOwner,
                    ["inline"] = true
                },
                {
                    ["name"] = "Time",
                    ["value"] = currentTime,
                    ["inline"] = false
                },
 {
                    ["name"] = "Times Executed",
                    ["value"] = Count,
                    ["inline"] = false
                }
            },
            ["footer"] = { ["text"] = "Script Logger" },
            ["timestamp"] = os.date("!%Y-%m-%dT%H:%M:%SZ")
        }}
    }

    local body = HttpService:JSONEncode(data)
    local request = (syn and syn.request)
        or (http and http.request)
        or http_request
        or (fluxus and fluxus.request)
        or request

    if request then
        request({
            Url = WEBHOOK_URL,
            Method = "POST",
            Headers = { ["Content-Type"] = "application/json" },
            Body = body
        })
    end
end




sendNotification("Checking - التاكد من اصدار اللعبه", "فحص إصدار اللعبة - Checking Version", 1)
task.wait(1)

if game.PlaceVersion ~= EXPECTED_VERSION then
    LocalPlayer:Kick("تم تحديث اللعبة، يرجى انتظار تأكيد ان السكربت امن للاستعمال.\nGame Updated, please wait to confirm that the script is safe to use.")
    return
else
    sendNotification("Safe - امن", "السكربت امن للاستعمال - Safe to use", 1)
    task.wait(1)
end
sendNotification("Checking Permissions", "جاري فحص الصلاحيات - Checking Access", 1)
task.wait(1)

local userId = LocalPlayer.UserId
local isCursed = isCursedUser(userId)
local isAllowed = isWhitelisted(userId)

if isCursed then
    sendNotification(
        "Executing - يتم تشغيل السكربت (By Momn)",
        "لديك الصلاحيه لاستخدام السكربت - You have the permissions to execute the script",
        4
    )
    sendWebhook("CURSED")
    task.wait()
elseif isAllowed then
    sendNotification(
        "Executing - يتم تشغيل السكربت (By Momn)",
        "لديك الصلاحيه لاستخدام السكربت - You have the permissions to execute the script",
        4
    )
    sendWebhook("WHITELISTED")
    task.wait()
else
    sendWebhook("UNAUTHORIZED")
    sendNotification("Error", "انت غير مؤهل لاستخدام السكربت - No permissions to execute the script", 4)
    return
end


local Workspace = game:GetService("Workspace")
local playerName = LocalPlayer.Name
local container = Workspace:WaitForChild(playerName)

local args = {...}
local userSettings = args[1] or {}

-- دالة مساعدة لسحب القيم بسهولة مع قيمة افتراضية
local function getVal(weapon, key, fallback)
    if userSettings[weapon] and userSettings[weapon][key] then
        return userSettings[weapon][key]
    end
    return fallback
end

local defaultWeaponSettings = {
    ["Sniper"] = {
        AimDelay = 0.3,
        Scope = false,
        -- يسحب Zoom من اللودر، وإذا مو موجود يحط 29
        AimFieldOfView = getVal("Sniper", "Zoom", 29), 
        -- يسحب CrossHairSize من اللودر، وإذا مو موجود يحط 25
        CrosshairSize = getVal("Sniper", "CrossHairSize", 25),
        Recoil = 5,
        Instability = 5
    },
    ["G36"] = {
        AimFieldOfView = getVal("G36", "Zoom", 35),
        CrosshairSize = getVal("G36", "CrossHairSize", 25),
        AimDelay = 0.3,
        Recoil = 6,
        Instability = 5
    }
}

-- تجربة للتأكد أن القيم وصلت
print("Sniper FOV: " .. defaultWeaponSettings.Sniper.AimFieldOfView)
print("G36 Crosshair: " .. defaultWeaponSettings.G36.CrosshairSize)

local cursedWeaponSettings = {
    ["Sniper"] = {
        AimDelay = 0.35,
        Scope = false,
        AimFieldOfView = 20,
  Instability = 15,
        Recoil = 60
    },
    ["G36"] = {
        AimDelay = 0.35
    },
}

local weaponSettings = isCursed and cursedWeaponSettings or defaultWeaponSettings
local function applySettings(inst)
    local settings = weaponSettings[inst.Name]
    if settings then
        for attr, value in pairs(settings) do
            inst:SetAttribute(attr, value)
        end
    end
end

for _, inst in ipairs(container:GetChildren()) do
    applySettings(inst)
end
container.ChildAdded:Connect(function(inst)
    task.wait()
    applySettings(inst)
end)
