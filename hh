local scriptURL = "https://pastebin.com/raw/iXC0AiXQ"

-- قائمة الآيديات الممنوعة (للفحص الفوري في السيرفر الحالي)
local blacklistedIDs = {
    6153474909,
    10377092761
}

local Players = game:GetService("Players")
local LocalPlayer = Players.LocalPlayer

-- دالة الطرد الفوري
local function check()
    for _, id in ipairs(blacklistedIDs) do
        if LocalPlayer.UserId == id then
            LocalPlayer:Kick("Exploiting")
            return true
        end
    end
    return false
end

-- 1. فحص اللاعب فور تشغيل السكربت
check()

-- 2. إعداد الحماية للانتقال عبر التيليبورت كما طلبت
if syn and syn.queue_on_teleport then
    syn.queue_on_teleport('loadstring(game:HttpGet("' .. scriptURL .. '"))()')
elseif queue_on_teleport then
    queue_on_teleport('loadstring(game:HttpGet("' .. scriptURL .. '"))()')
elseif queueonteleport then
    queueonteleport('loadstring(game:HttpGet("' .. scriptURL .. '"))()')
end
