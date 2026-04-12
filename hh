-- ╔══════════════════════════════════════════════╗
-- ║         OG-Sniper Script - Full UI           ║
-- ║         Made for Roblox Executor             ║
-- ╚══════════════════════════════════════════════╝

-- ══════════════════════════════════════
--         FUNCTIONS (ضع هنا)
-- ══════════════════════════════════════

local function OGSniper_045()
	-- OG-Sniper with 0.45 AimDelay
	print("OG Sniper 0.45 Activated")
end

local function OGSniper_065()
	-- OG-Sniper with 0.65 AimDelay
	print("OG Sniper 0.65 Activated")
end

local function NEWSniper_045()
	-- NEW-Sniper with better view with 0.45 AimDelay
	print("NEW Sniper 0.45 Activated")
end

local function NEWSniper_065()
	-- NEW-Sniper with better view with 0.65 AimDelay
	print("NEW Sniper 0.65 Activated")
end

-- ══════════════════════════════════════
--             UI BUILDER
-- ══════════════════════════════════════

local Players       = game:GetService("Players")
local TweenService  = game:GetService("TweenService")
local RunService    = game:GetService("RunService")
local UserInputService = game:GetService("UserInputService")

local LocalPlayer   = Players.LocalPlayer
local PlayerGui     = LocalPlayer:WaitForChild("PlayerGui")

-- Remove old UI if exists
local oldGui = PlayerGui:FindFirstChild("OGSniperUI")
if oldGui then oldGui:Destroy() end

-- ── MAIN GUI ──────────────────────────────────────────────────────────────────
local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name             = "OGSniperUI"
ScreenGui.ZIndexBehavior   = Enum.ZIndexBehavior.Sibling
ScreenGui.ResetOnSpawn     = false
ScreenGui.IgnoreGuiInset   = true
ScreenGui.Parent           = PlayerGui

-- ── MAIN FRAME ────────────────────────────────────────────────────────────────
local Main = Instance.new("Frame")
Main.Name              = "Main"
Main.Size              = UDim2.new(0, 700, 0, 540)
Main.Position          = UDim2.new(0.5, -350, 0.5, -270)
Main.BackgroundColor3  = Color3.fromRGB(10, 10, 14)
Main.BorderSizePixel   = 0
Main.ClipsDescendants  = true
Main.Parent            = ScreenGui

-- Start hidden for animation
Main.AnchorPoint = Vector2.new(0.5, 0.5)
Main.Position    = UDim2.new(0.5, 0, 0.5, 0)
Main.Size        = UDim2.new(0, 0, 0, 0)
Main.BackgroundTransparency = 1

local MainCorner = Instance.new("UICorner")
MainCorner.CornerRadius = UDim.new(0, 12)
MainCorner.Parent = Main

-- Subtle border glow
local MainStroke = Instance.new("UIStroke")
MainStroke.Color     = Color3.fromRGB(80, 80, 110)
MainStroke.Thickness = 1.2
MainStroke.Transparency = 0.5
MainStroke.Parent = Main

-- ── TOPBAR ────────────────────────────────────────────────────────────────────
local TopBar = Instance.new("Frame")
TopBar.Name             = "TopBar"
TopBar.Size             = UDim2.new(1, 0, 0, 52)
TopBar.Position         = UDim2.new(0, 0, 0, 0)
TopBar.BackgroundColor3 = Color3.fromRGB(16, 16, 22)
TopBar.BorderSizePixel  = 0
TopBar.ZIndex           = 3
TopBar.Parent           = Main

local TopBarCorner = Instance.new("UICorner")
TopBarCorner.CornerRadius = UDim.new(0, 12)
TopBarCorner.Parent = TopBar

-- Fix bottom corners of topbar
local TopBarFix = Instance.new("Frame")
TopBarFix.Size             = UDim2.new(1, 0, 0, 12)
TopBarFix.Position         = UDim2.new(0, 0, 1, -12)
TopBarFix.BackgroundColor3 = Color3.fromRGB(16, 16, 22)
TopBarFix.BorderSizePixel  = 0
TopBarFix.ZIndex           = 3
TopBarFix.Parent           = TopBar

-- Accent line under topbar
local AccentLine = Instance.new("Frame")
AccentLine.Size             = UDim2.new(1, 0, 0, 2)
AccentLine.Position         = UDim2.new(0, 0, 1, 0)
AccentLine.BackgroundColor3 = Color3.fromRGB(100, 100, 255)
AccentLine.BorderSizePixel  = 0
AccentLine.ZIndex           = 4
AccentLine.Parent           = TopBar

local AccentGrad = Instance.new("UIGradient")
AccentGrad.Color = ColorSequence.new({
	ColorSequenceKeypoint.new(0,   Color3.fromRGB(80, 80, 220)),
	ColorSequenceKeypoint.new(0.5, Color3.fromRGB(140, 100, 255)),
	ColorSequenceKeypoint.new(1,   Color3.fromRGB(80, 80, 220)),
})
AccentGrad.Parent = AccentLine

-- Title
local TitleLabel = Instance.new("TextLabel")
TitleLabel.Name               = "Title"
TitleLabel.Size               = UDim2.new(1, -130, 1, 0)
TitleLabel.Position           = UDim2.new(0, 18, 0, 0)
TitleLabel.BackgroundTransparency = 1
TitleLabel.Text               = "OG-Sniper Script"
TitleLabel.TextColor3         = Color3.fromRGB(240, 240, 255)
TitleLabel.TextSize           = 17
TitleLabel.Font               = Enum.Font.GothamBold
TitleLabel.TextXAlignment     = Enum.TextXAlignment.Left
TitleLabel.ZIndex             = 4
TitleLabel.Parent             = TopBar

-- Version badge
local VerBadge = Instance.new("Frame")
VerBadge.Size             = UDim2.new(0, 38, 0, 18)
VerBadge.Position         = UDim2.new(0, 205, 0.5, -9)
VerBadge.BackgroundColor3 = Color3.fromRGB(90, 70, 200)
VerBadge.BorderSizePixel  = 0
VerBadge.ZIndex           = 5
VerBadge.Parent           = TopBar

local VerBadgeCorner = Instance.new("UICorner")
VerBadgeCorner.CornerRadius = UDim.new(1, 0)
VerBadgeCorner.Parent = VerBadge

local VerText = Instance.new("TextLabel")
VerText.Size             = UDim2.new(1, 0, 1, 0)
VerText.BackgroundTransparency = 1
VerText.Text             = "v2.0"
VerText.TextColor3       = Color3.fromRGB(255, 255, 255)
VerText.TextSize         = 10
VerText.Font             = Enum.Font.GothamBold
VerText.TextXAlignment   = Enum.TextXAlignment.Center
VerText.ZIndex           = 6
VerText.Parent           = VerBadge

-- Close Button
local CloseBtn = Instance.new("TextButton")
CloseBtn.Name             = "CloseBtn"
CloseBtn.Size             = UDim2.new(0, 30, 0, 30)
CloseBtn.Position         = UDim2.new(1, -44, 0.5, -15)
CloseBtn.BackgroundColor3 = Color3.fromRGB(200, 50, 60)
CloseBtn.Text             = "✕"
CloseBtn.TextColor3       = Color3.fromRGB(255, 255, 255)
CloseBtn.TextSize         = 13
CloseBtn.Font             = Enum.Font.GothamBold
CloseBtn.BorderSizePixel  = 0
CloseBtn.ZIndex           = 5
CloseBtn.Parent           = TopBar

local CloseBtnCorner = Instance.new("UICorner")
CloseBtnCorner.CornerRadius = UDim.new(0, 8)
CloseBtnCorner.Parent = CloseBtn

-- Minimize Button
local MinBtn = Instance.new("TextButton")
MinBtn.Name             = "MinBtn"
MinBtn.Size             = UDim2.new(0, 30, 0, 30)
MinBtn.Position         = UDim2.new(1, -80, 0.5, -15)
MinBtn.BackgroundColor3 = Color3.fromRGB(40, 40, 55)
MinBtn.Text             = "─"
MinBtn.TextColor3       = Color3.fromRGB(180, 180, 200)
MinBtn.TextSize         = 13
MinBtn.Font             = Enum.Font.GothamBold
MinBtn.BorderSizePixel  = 0
MinBtn.ZIndex           = 5
MinBtn.Parent           = TopBar

local MinBtnCorner = Instance.new("UICorner")
MinBtnCorner.CornerRadius = UDim.new(0, 8)
MinBtnCorner.Parent = MinBtn

-- ── SIDEBAR ───────────────────────────────────────────────────────────────────
local Sidebar = Instance.new("Frame")
Sidebar.Name             = "Sidebar"
Sidebar.Size             = UDim2.new(0, 160, 1, -52)
Sidebar.Position         = UDim2.new(0, 0, 0, 52)
Sidebar.BackgroundColor3 = Color3.fromRGB(13, 13, 18)
Sidebar.BorderSizePixel  = 0
Sidebar.ZIndex           = 2
Sidebar.Parent           = Main

-- Sidebar divider
local SideDiv = Instance.new("Frame")
SideDiv.Size             = UDim2.new(0, 1, 1, 0)
SideDiv.Position         = UDim2.new(1, 0, 0, 0)
SideDiv.BackgroundColor3 = Color3.fromRGB(40, 40, 60)
SideDiv.BorderSizePixel  = 0
SideDiv.ZIndex           = 3
SideDiv.Parent           = Sidebar

-- Player Avatar
local AvatarFrame = Instance.new("Frame")
AvatarFrame.Size             = UDim2.new(0, 56, 0, 56)
AvatarFrame.Position         = UDim2.new(0.5, -28, 0, 18)
AvatarFrame.BackgroundColor3 = Color3.fromRGB(100, 80, 220)
AvatarFrame.BorderSizePixel  = 0
AvatarFrame.ZIndex           = 3
AvatarFrame.Parent           = Sidebar

local AvatarCorner = Instance.new("UICorner")
AvatarCorner.CornerRadius = UDim.new(1, 0)
AvatarCorner.Parent = AvatarFrame

local AvatarStroke = Instance.new("UIStroke")
AvatarStroke.Color     = Color3.fromRGB(120, 100, 255)
AvatarStroke.Thickness = 2
AvatarStroke.Parent = AvatarFrame

-- Load avatar image
local AvatarImg = Instance.new("ImageLabel")
AvatarImg.Size             = UDim2.new(1, 0, 1, 0)
AvatarImg.BackgroundTransparency = 1
AvatarImg.ZIndex           = 4
AvatarImg.Parent           = AvatarFrame

local AvatarImgCorner = Instance.new("UICorner")
AvatarImgCorner.CornerRadius = UDim.new(1, 0)
AvatarImgCorner.Parent = AvatarImg

-- Load player thumbnail
local userId = LocalPlayer.UserId
local thumbType = Enum.ThumbnailType.HeadShot
local thumbSize = Enum.ThumbnailSize.Size100x100
local content, isReady = Players:GetUserThumbnailAsync(userId, thumbType, thumbSize)
AvatarImg.Image = content

-- Player name label
local PlayerNameLabel = Instance.new("TextLabel")
PlayerNameLabel.Size             = UDim2.new(1, -10, 0, 22)
PlayerNameLabel.Position         = UDim2.new(0, 5, 0, 82)
PlayerNameLabel.BackgroundTransparency = 1
PlayerNameLabel.Text             = LocalPlayer.DisplayName
PlayerNameLabel.TextColor3       = Color3.fromRGB(230, 230, 255)
PlayerNameLabel.TextSize         = 13
PlayerNameLabel.Font             = Enum.Font.GothamBold
PlayerNameLabel.TextXAlignment   = Enum.TextXAlignment.Center
PlayerNameLabel.ZIndex           = 3
PlayerNameLabel.Parent           = Sidebar

-- @username
local PlayerUserLabel = Instance.new("TextLabel")
PlayerUserLabel.Size             = UDim2.new(1, -10, 0, 18)
PlayerUserLabel.Position         = UDim2.new(0, 5, 0, 102)
PlayerUserLabel.BackgroundTransparency = 1
PlayerUserLabel.Text             = "@" .. LocalPlayer.Name
PlayerUserLabel.TextColor3       = Color3.fromRGB(120, 120, 160)
PlayerUserLabel.TextSize         = 10
PlayerUserLabel.Font             = Enum.Font.Gotham
PlayerUserLabel.TextXAlignment   = Enum.TextXAlignment.Center
PlayerUserLabel.ZIndex           = 3
PlayerUserLabel.Parent           = Sidebar

-- Divider under player info
local SideInfoDiv = Instance.new("Frame")
SideInfoDiv.Size             = UDim2.new(0.75, 0, 0, 1)
SideInfoDiv.Position         = UDim2.new(0.125, 0, 0, 132)
SideInfoDiv.BackgroundColor3 = Color3.fromRGB(40, 40, 60)
SideInfoDiv.BorderSizePixel  = 0
SideInfoDiv.ZIndex           = 3
SideInfoDiv.Parent           = Sidebar

-- Sidebar tab: Main
local SideTabMain = Instance.new("Frame")
SideTabMain.Size             = UDim2.new(1, -16, 0, 36)
SideTabMain.Position         = UDim2.new(0, 8, 0, 148)
SideTabMain.BackgroundColor3 = Color3.fromRGB(90, 70, 200)
SideTabMain.BorderSizePixel  = 0
SideTabMain.ZIndex           = 3
SideTabMain.Parent           = Sidebar

local SideTabCorner = Instance.new("UICorner")
SideTabCorner.CornerRadius = UDim.new(0, 8)
SideTabCorner.Parent = SideTabMain

local SideTabGrad = Instance.new("UIGradient")
SideTabGrad.Color = ColorSequence.new({
	ColorSequenceKeypoint.new(0, Color3.fromRGB(100, 80, 220)),
	ColorSequenceKeypoint.new(1, Color3.fromRGB(60, 50, 150)),
})
SideTabGrad.Rotation = 90
SideTabGrad.Parent = SideTabMain

local SideTabText = Instance.new("TextLabel")
SideTabText.Size             = UDim2.new(1, -10, 1, 0)
SideTabText.Position         = UDim2.new(0, 10, 0, 0)
SideTabText.BackgroundTransparency = 1
SideTabText.Text             = "⚡  Main"
SideTabText.TextColor3       = Color3.fromRGB(255, 255, 255)
SideTabText.TextSize         = 13
SideTabText.Font             = Enum.Font.GothamBold
SideTabText.TextXAlignment   = Enum.TextXAlignment.Left
SideTabText.ZIndex           = 4
SideTabText.Parent           = SideTabMain

-- ── CONTENT AREA ──────────────────────────────────────────────────────────────
local ContentArea = Instance.new("Frame")
ContentArea.Name             = "ContentArea"
ContentArea.Size             = UDim2.new(1, -160, 1, -52)
ContentArea.Position         = UDim2.new(0, 160, 0, 52)
ContentArea.BackgroundTransparency = 1
ContentArea.ClipsDescendants = true
ContentArea.ZIndex           = 2
ContentArea.Parent           = Main

-- Content title
local ContentTitle = Instance.new("TextLabel")
ContentTitle.Size             = UDim2.new(1, -20, 0, 40)
ContentTitle.Position         = UDim2.new(0, 16, 0, 10)
ContentTitle.BackgroundTransparency = 1
ContentTitle.Text             = "Main  —  Select your sniper mode"
ContentTitle.TextColor3       = Color3.fromRGB(180, 180, 220)
ContentTitle.TextSize         = 13
ContentTitle.Font             = Enum.Font.Gotham
ContentTitle.TextXAlignment   = Enum.TextXAlignment.Left
ContentTitle.ZIndex           = 3
ContentTitle.Parent           = ContentArea

-- ── SCROLLING FRAME ───────────────────────────────────────────────────────────
local ScrollFrame = Instance.new("ScrollingFrame")
ScrollFrame.Name                  = "ScrollFrame"
ScrollFrame.Size                  = UDim2.new(1, -8, 1, -56)
ScrollFrame.Position              = UDim2.new(0, 4, 0, 50)
ScrollFrame.BackgroundTransparency = 1
ScrollFrame.BorderSizePixel       = 0
ScrollFrame.ScrollBarThickness    = 4
ScrollFrame.ScrollBarImageColor3  = Color3.fromRGB(90, 70, 200)
ScrollFrame.CanvasSize            = UDim2.new(0, 0, 0, 0)
ScrollFrame.AutomaticCanvasSize   = Enum.AutomaticSize.Y
ScrollFrame.ZIndex                = 3
ScrollFrame.Parent                = ContentArea

local ListLayout = Instance.new("UIListLayout")
ListLayout.Padding         = UDim.new(0, 12)
ListLayout.SortOrder       = Enum.SortOrder.LayoutOrder
ListLayout.Parent          = ScrollFrame

local ListPadding = Instance.new("UIPadding")
ListPadding.PaddingLeft   = UDim.new(0, 10)
ListPadding.PaddingRight  = UDim.new(0, 14)
ListPadding.PaddingTop    = UDim.new(0, 6)
ListPadding.PaddingBottom = UDim.new(0, 16)
ListPadding.Parent        = ScrollFrame

-- ══════════════════════════════════════
--          CARD BUILDER FUNCTION
-- ══════════════════════════════════════

local function MakeLevelBadge(parent, level, posX, posY)
	-- level: "safe_high"=green+recommended, "safe"=yellow, "acceptable"=red+warning
	local colors = {
		safe_high   = {bg = Color3.fromRGB(30, 160, 80),  text = "أمن جداً",   tag = "موصى به",   tagColor = Color3.fromRGB(50, 200, 100)},
		safe        = {bg = Color3.fromRGB(190, 150, 20), text = "أمن",         tag = nil,          tagColor = nil},
		acceptable  = {bg = Color3.fromRGB(180, 50, 50),  text = "مقبول",       tag = "⚠ تحذير",   tagColor = Color3.fromRGB(220, 80, 80)},
	}
	local cfg = colors[level]

	local wrapper = Instance.new("Frame")
	wrapper.Size             = UDim2.new(0, 160, 0, 28)
	wrapper.Position         = UDim2.new(0, posX, 0, posY)
	wrapper.BackgroundTransparency = 1
	wrapper.ZIndex           = 6
	wrapper.Parent           = parent

	-- Label row
	local levelTitle = Instance.new("TextLabel")
	levelTitle.Size             = UDim2.new(1, 0, 0, 14)
	levelTitle.Position         = UDim2.new(0, 0, 0, 0)
	levelTitle.BackgroundTransparency = 1
	levelTitle.Text             = "Recommendation Level"
	levelTitle.TextColor3       = Color3.fromRGB(120, 120, 160)
	levelTitle.TextSize         = 9
	levelTitle.Font             = Enum.Font.Gotham
	levelTitle.TextXAlignment   = Enum.TextXAlignment.Left
	levelTitle.ZIndex           = 6
	levelTitle.Parent           = wrapper

	local badge = Instance.new("Frame")
	badge.Size             = UDim2.new(0, 70, 0, 16)
	badge.Position         = UDim2.new(0, 0, 0, 14)
	badge.BackgroundColor3 = cfg.bg
	badge.BorderSizePixel  = 0
	badge.ZIndex           = 6
	badge.Parent           = wrapper

	local badgeCorner = Instance.new("UICorner")
	badgeCorner.CornerRadius = UDim.new(1, 0)
	badgeCorner.Parent = badge

	local badgeText = Instance.new("TextLabel")
	badgeText.Size             = UDim2.new(1, 0, 1, 0)
	badgeText.BackgroundTransparency = 1
	badgeText.Text             = cfg.text
	badgeText.TextColor3       = Color3.fromRGB(255, 255, 255)
	badgeText.TextSize         = 9
	badgeText.Font             = Enum.Font.GothamBold
	badgeText.TextXAlignment   = Enum.TextXAlignment.Center
	badgeText.ZIndex           = 7
	badgeText.Parent           = badge

	if cfg.tag then
		local tagLabel = Instance.new("TextLabel")
		tagLabel.Size             = UDim2.new(0, 80, 0, 16)
		tagLabel.Position         = UDim2.new(0, 76, 0, 14)
		tagLabel.BackgroundTransparency = 1
		tagLabel.Text             = cfg.tag
		tagLabel.TextColor3       = cfg.tagColor
		tagLabel.TextSize         = 9
		tagLabel.Font             = Enum.Font.GothamBold
		tagLabel.TextXAlignment   = Enum.TextXAlignment.Left
		tagLabel.ZIndex           = 7
		tagLabel.Parent           = wrapper
	end

	return wrapper
end

local function CreateCard(order, btnTitle, descAR, level, callback, imageAssetId)
	-- level: "safe_high", "safe", "acceptable"

	local Card = Instance.new("Frame")
	Card.Name             = "Card_" .. order
	Card.Size             = UDim2.new(1, 0, 0, 195)
	Card.BackgroundColor3 = Color3.fromRGB(18, 18, 26)
	Card.BorderSizePixel  = 0
	Card.LayoutOrder      = order
	Card.ZIndex           = 4
	Card.Parent           = ScrollFrame

	local CardCorner = Instance.new("UICorner")
	CardCorner.CornerRadius = UDim.new(0, 10)
	CardCorner.Parent = Card

	local CardStroke = Instance.new("UIStroke")
	CardStroke.Color       = Color3.fromRGB(45, 45, 65)
	CardStroke.Thickness   = 1
	CardStroke.Transparency = 0.3
	CardStroke.Parent = Card

	-- Number badge top-left
	local NumBadge = Instance.new("Frame")
	NumBadge.Size             = UDim2.new(0, 24, 0, 24)
	NumBadge.Position         = UDim2.new(0, 12, 0, 12)
	NumBadge.BackgroundColor3 = Color3.fromRGB(60, 50, 140)
	NumBadge.BorderSizePixel  = 0
	NumBadge.ZIndex           = 5
	NumBadge.Parent           = Card

	local NumCorner = Instance.new("UICorner")
	NumCorner.CornerRadius = UDim.new(0, 6)
	NumCorner.Parent = NumBadge

	local NumText = Instance.new("TextLabel")
	NumText.Size             = UDim2.new(1, 0, 1, 0)
	NumText.BackgroundTransparency = 1
	NumText.Text             = tostring(order)
	NumText.TextColor3       = Color3.fromRGB(200, 190, 255)
	NumText.TextSize         = 12
	NumText.Font             = Enum.Font.GothamBold
	NumText.TextXAlignment   = Enum.TextXAlignment.Center
	NumText.ZIndex           = 6
	NumText.Parent           = NumBadge

	-- Button Title
	local BtnTitleLabel = Instance.new("TextLabel")
	BtnTitleLabel.Size             = UDim2.new(1, -50, 0, 24)
	BtnTitleLabel.Position         = UDim2.new(0, 44, 0, 11)
	BtnTitleLabel.BackgroundTransparency = 1
	BtnTitleLabel.Text             = btnTitle
	BtnTitleLabel.TextColor3       = Color3.fromRGB(230, 230, 255)
	BtnTitleLabel.TextSize         = 12
	BtnTitleLabel.Font             = Enum.Font.GothamBold
	BtnTitleLabel.TextXAlignment   = Enum.TextXAlignment.Left
	BtnTitleLabel.TextTruncate     = Enum.TextTruncate.AtEnd
	BtnTitleLabel.ZIndex           = 5
	BtnTitleLabel.Parent           = Card

	-- Divider
	local TitleDiv = Instance.new("Frame")
	TitleDiv.Size             = UDim2.new(1, -24, 0, 1)
	TitleDiv.Position         = UDim2.new(0, 12, 0, 42)
	TitleDiv.BackgroundColor3 = Color3.fromRGB(35, 35, 55)
	TitleDiv.BorderSizePixel  = 0
	TitleDiv.ZIndex           = 5
	TitleDiv.Parent           = Card

	-- Description Arabic
	local DescLabel = Instance.new("TextLabel")
	DescLabel.Size             = UDim2.new(0, 160, 0, 32)
	DescLabel.Position         = UDim2.new(0, 12, 0, 50)
	DescLabel.BackgroundTransparency = 1
	DescLabel.Text             = descAR
	DescLabel.TextColor3       = Color3.fromRGB(140, 140, 175)
	DescLabel.TextSize         = 10
	DescLabel.Font             = Enum.Font.Gotham
	DescLabel.TextXAlignment   = Enum.TextXAlignment.Left
	DescLabel.TextYAlignment   = Enum.TextYAlignment.Top
	DescLabel.TextWrapped      = true
	DescLabel.ZIndex           = 5
	DescLabel.Parent           = Card

	-- Recommendation Level badge (bottom-left)
	MakeLevelBadge(Card, level, 12, 95)

	-- Image placeholder (right side)
	local ImgHolder = Instance.new("Frame")
	ImgHolder.Name             = "ImageHolder"
	ImgHolder.Size             = UDim2.new(0, 155, 0, 125)
	ImgHolder.Position         = UDim2.new(1, -167, 0, 46)
	ImgHolder.BackgroundColor3 = Color3.fromRGB(24, 24, 34)
	ImgHolder.BorderSizePixel  = 0
	ImgHolder.ZIndex = Card

local ImgHolderCorner = Instance.new("UICorner")
	ImgHolderCorner.CornerRadius = UDim.new(0, 8)
	ImgHolderCorner.Parent = ImgHolder

	local ImgHolderStroke = Instance.new("UIStroke")
	ImgHolderStroke.Color     = Color3.fromRGB(50, 50, 75)
	ImgHolderStroke.Thickness = 1
	ImgHolderStroke.Parent = ImgHolder

	local ImgLabel = Instance.new("ImageLabel")
	ImgLabel.Size             = UDim2.new(1, -4, 1, -4)
	ImgLabel.Position         = UDim2.new(0, 2, 0, 2)
	ImgLabel.BackgroundTransparency = 1
	ImgLabel.ScaleType        = Enum.ScaleType.Fit
	ImgLabel.ZIndex           = 6

	if imageAssetId and imageAssetId ~= "" then
		ImgLabel.Image = imageAssetId
	else
		ImgLabel.Image = ""
	end
	ImgLabel.Parent = ImgHolder

	-- Placeholder text if no image
	local PlaceholderText = Instance.new("TextLabel")
	PlaceholderText.Size             = UDim2.new(1, 0, 1, 0)
	PlaceholderText.BackgroundTransparency = 1
	PlaceholderText.Text             = imageAssetId ~= "" and "" or "🖼  ضع صورتك هنا\nImageHolder"
	PlaceholderText.TextColor3       = Color3.fromRGB(70, 70, 100)
	PlaceholderText.TextSize         = 9
	PlaceholderText.Font             = Enum.Font.Gotham
	PlaceholderText.TextXAlignment   = Enum.TextXAlignment.Center
	PlaceholderText.TextWrapped      = true
	PlaceholderText.ZIndex           = 6
	PlaceholderText.Parent           = ImgHolder

	-- ACTIVATE BUTTON
	local ActivateBtn = Instance.new("TextButton")
	ActivateBtn.Name             = "ActivateBtn"
	ActivateBtn.Size             = UDim2.new(0, 130, 0, 30)
	ActivateBtn.Position         = UDim2.new(0, 12, 1, -42)
	ActivateBtn.BackgroundColor3 = Color3.fromRGB(80, 60, 190)
	ActivateBtn.Text             = "▶  تشغيل"
	ActivateBtn.TextColor3       = Color3.fromRGB(255, 255, 255)
	ActivateBtn.TextSize         = 12
	ActivateBtn.Font             = Enum.Font.GothamBold
	ActivateBtn.BorderSizePixel  = 0
	ActivateBtn.ZIndex           = 6
	ActivateBtn.Parent           = Card

	local ActivateBtnCorner = Instance.new("UICorner")
	ActivateBtnCorner.CornerRadius = UDim.new(0, 8)
	ActivateBtnCorner.Parent = ActivateBtn

	local BtnGrad = Instance.new("UIGradient")
	BtnGrad.Color = ColorSequence.new({
		ColorSequenceKeypoint.new(0, Color3.fromRGB(100, 80, 220)),
		ColorSequenceKeypoint.new(1, Color3.fromRGB(60, 45, 160)),
	})
	BtnGrad.Rotation = 90
	BtnGrad.Parent = ActivateBtn

	-- Button hover
	ActivateBtn.MouseEnter:Connect(function()
		TweenService:Create(ActivateBtn, TweenInfo.new(0.15), {
			BackgroundColor3 = Color3.fromRGB(110, 90, 240)
		}):Play()
	end)
	ActivateBtn.MouseLeave:Connect(function()
		TweenService:Create(ActivateBtn, TweenInfo.new(0.15), {
			BackgroundColor3 = Color3.fromRGB(80, 60, 190)
		}):Play()
	end)

	-- Click: run function + close UI
	ActivateBtn.MouseButton1Click:Connect(function()
		-- Flash effect
		local flash = Instance.new("Frame")
		flash.Size             = UDim2.new(1, 0, 1, 0)
		flash.BackgroundColor3 = Color3.fromRGB(120, 100, 255)
		flash.BackgroundTransparency = 0.6
		flash.BorderSizePixel  = 0
		flash.ZIndex           = 20
		flash.Parent           = Main
		local fc = Instance.new("UICorner")
		fc.CornerRadius = UDim.new(0, 12)
		fc.Parent = flash

		TweenService:Create(flash, TweenInfo.new(0.35), {
			BackgroundTransparency = 1
		}):Play()
		task.delay(0.35, function() flash:Destroy() end)

		-- Close UI with animation
		task.delay(0.15, function()
			local closeTween = TweenService:Create(Main, TweenInfo.new(0.3, Enum.EasingStyle.Back, Enum.EasingDirection.In), {
				Size     = UDim2.new(0, 0, 0, 0),
				BackgroundTransparency = 1,
			})
			closeTween:Play()
			closeTween.Completed:Connect(function()
				ScreenGui:Destroy()
				callback()
			end)
		end)
	end)

	return Card
end

-- ── CREATE THE 4 CARDS ────────────────────────────────────────────────────────
-- Card 1
CreateCard(
	1,
	"OG-Sniper with 0.45 AimDelay",
	"ارجاع السنايبر القديم مع تاخير 0.45 عند الاطلاق",
	"acceptable",
	OGSniper_045,
	""  -- ← ضع asset id الصورة هنا مثال: "rbxassetid://123456"
)

-- Card 2
CreateCard(
	2,
	"OG-Sniper with 0.65 AimDelay",
	"ارجاع السنايبر القديم مع تاخير 0.65 عند الاطلاق",
	"safe_high",
	OGSniper_065,
	""
)

-- Card 3
CreateCard(
	3,
	"NEW-Sniper with better view with 0.45 AimDelay",
	"السنايبر الجديد نسخة محسنة ورؤية اكبر مع 0.45 تاخير الاطلاق",
	"safe",
	NEWSniper_045,
	""
)

-- Card 4
CreateCard(
	4,
	"NEW-Sniper with better view with 0.65 AimDelay",
	"السنايبر الجديد نسخة محسنة ورؤية اكبر مع 0.65 تاخير الاطلاق",
	"safe_high",
	NEWSniper_065,
	""
)

-- ══════════════════════════════════════
--         DRAGGING SYSTEM
-- ══════════════════════════════════════

local dragging = false
local dragStart, startPos

TopBar.InputBegan:Connect(function(input)
	if input.UserInputType == Enum.UserInputType.MouseButton1 or
		input.UserInputType == Enum.UserInputType.Touch then
		dragging  = true
		dragStart = input.Position
		startPos  = Main.Position
	end
end)

UserInputService.InputChanged:Connect(function(input)
	if dragging and (input.UserInputType == Enum.UserInputType.MouseMovement or
		input.UserInputType == Enum.UserInputType.Touch) then
		local delta = input.Position - dragStart
		Main.Position = UDim2.new(
			startPos.X.Scale,
			startPos.X.Offset + delta.X,
			startPos.Y.Scale,
			startPos.Y.Offset + delta.Y
		)
	end
end)

UserInputService.InputEnded:Connect(function(input)
	if input.UserInputType == Enum.UserInputType.MouseButton1 or
		input.UserInputType == Enum.UserInputType.Touch then
		dragging = false
	end
end)

-- ══════════════════════════════════════
--         CLOSE / MINIMIZE
-- ══════════════════════════════════════

CloseBtn.MouseButton1Click:Connect(function()
	local t = TweenService:Create(Main,
		TweenInfo.new(0.28, Enum.EasingStyle.Back, Enum.EasingDirection.In),
		{Size = UDim2.new(0, 0, 0, 0), BackgroundTransparency = 1}
	)
	t:Play()
	t.Completed:Connect(function() ScreenGui:Destroy() end)
end)

local minimized = false
MinBtn.MouseButton1Click:Connect(function()
	minimized = not minimized
	if minimized then
		TweenService:Create(Main, TweenInfo.new(0.25, Enum.EasingStyle.Quad), {
			Size = UDim2.new(0, 700, 0, 52)
		}):Play()
		MinBtn.Text = "▢"
	else
		TweenService:Create(Main, TweenInfo.new(0.25, Enum.EasingStyle.Quad), {
			Size = UDim2.new(0, 700, 0, 540)
		}):Play()
		MinBtn.Text = "─"
	end
end)

-- ══════════════════════════════════════
--         OPEN ANIMATION (FANCY)
-- ══════════════════════════════════════

Main.BackgroundTransparency = 1

-- Step 1: scale in with bounce
local openTween = TweenService:Create(Main,
	TweenInfo.new(0.5, Enum.EasingStyle.Back, Enum.EasingDirection.Out),
	{
		Size = UDim2.new(0, 700, 0, 540),
		BackgroundTransparency = 0,
	}
)
openTween:Play()

-- Step 2: slide children in after main opens
task.delay(0.15, function()
	for _, child in ipairs({TopBar, Sidebar, ContentArea}) do
		local origTrans = child.BackgroundTransparency
		child.BackgroundTransparency = 1
		TweenService:Create(child, TweenInfo.new(0.3, Enum.EasingStyle.Quad), {
			BackgroundTransparency = origTrans,
		}):Play()
	end
end)

-- Step 3: accent line shimmer on open
task.delay(0.4, function()
	local shimmer = TweenService:Create(AccentGrad,
		TweenInfo.new(1.2, Enum.EasingStyle.Sine, Enum.EasingDirection.InOut, 2, true),
		{Offset = Vector2.new(0.5, 0)}
	)
	shimmer:Play()
end)

