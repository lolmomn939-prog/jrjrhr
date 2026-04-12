local function OGSniper_045()
	print("OG Sniper 0.45 Activated")
end

local function OGSniper_065()
	print("OG Sniper 0.65 Activated")
end

local function NEWSniper_045()
	print("NEW Sniper 0.45 Activated")
end

local function NEWSniper_065()
	print("NEW Sniper 0.65 Activated")
end

-- ══════════════════════════════════════
--             SERVICES
-- ══════════════════════════════════════

local Players           = game:GetService("Players")
local TweenService      = game:GetService("TweenService")
local UserInputService  = game:GetService("UserInputService")

local LocalPlayer  = Players.LocalPlayer
local PlayerGui    = LocalPlayer:WaitForChild("PlayerGui")

-- Remove old UI
local old = PlayerGui:FindFirstChild("OGSniperUI")
if old then old:Destroy() end

-- ══════════════════════════════════════
--          SCREEN SIZE HELPER
-- ══════════════════════════════════════

local function getScreenSize()
	local cam = workspace.CurrentCamera
	return cam and cam.ViewportSize or Vector2.new(800, 600)
end

local screen    = getScreenSize()
local isPhone   = screen.X < 600 or screen.Y < 700

-- UI dimensions - compact & balanced for mobile
local UI_W      = isPhone and math.min(screen.X - 20, 460) or 660
local UI_H      = isPhone and math.min(screen.Y - 60, 500) or 520
local SIDE_W    = isPhone and 110 or 140
local TOP_H     = 46
local CARD_H    = isPhone and 170 or 180

-- ══════════════════════════════════════
--           MAIN GUI
-- ══════════════════════════════════════

local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name           = "OGSniperUI"
ScreenGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
ScreenGui.ResetOnSpawn   = false
ScreenGui.IgnoreGuiInset = true
ScreenGui.Parent         = PlayerGui

local Main = Instance.new("Frame")
Main.Name                  = "Main"
Main.AnchorPoint           = Vector2.new(0.5, 0.5)
Main.Position              = UDim2.new(0.5, 0, 0.5, 0)
Main.Size                  = UDim2.new(0, 0, 0, 0)
Main.BackgroundColor3      = Color3.fromRGB(10, 10, 15)
Main.BackgroundTransparency = 1
Main.BorderSizePixel       = 0
Main.ClipsDescendants      = true
Main.Parent                = ScreenGui

local MainCorner = Instance.new("UICorner")
MainCorner.CornerRadius = UDim.new(0, 11)
MainCorner.Parent = Main

local MainStroke = Instance.new("UIStroke")
MainStroke.Color       = Color3.fromRGB(55, 55, 80)
MainStroke.Thickness   = 1
MainStroke.Parent = Main

-- ══════════════════════════════════════
--             TOPBAR
-- ══════════════════════════════════════

local TopBar = Instance.new("Frame")
TopBar.Size             = UDim2.new(1, 0, 0, TOP_H)
TopBar.BackgroundColor3 = Color3.fromRGB(14, 14, 20)
TopBar.BorderSizePixel  = 0
TopBar.ZIndex           = 3
TopBar.Parent           = Main

local TBCorner = Instance.new("UICorner")
TBCorner.CornerRadius = UDim.new(0, 11)
TBCorner.Parent = TopBar

local TBFix = Instance.new("Frame")
TBFix.Size             = UDim2.new(1, 0, 0, 11)
TBFix.Position         = UDim2.new(0, 0, 1, -11)
TBFix.BackgroundColor3 = Color3.fromRGB(14, 14, 20)
TBFix.BorderSizePixel  = 0
TBFix.ZIndex           = 3
TBFix.Parent           = TopBar

-- Accent line
local AccLine = Instance.new("Frame")
AccLine.Size             = UDim2.new(1, 0, 0, 2)
AccLine.Position         = UDim2.new(0, 0, 1, 0)
AccLine.BackgroundColor3 = Color3.fromRGB(90, 70, 200)
AccLine.BorderSizePixel  = 0
AccLine.ZIndex           = 4
AccLine.Parent           = TopBar

local AccGrad = Instance.new("UIGradient")
AccGrad.Color = ColorSequence.new({
	ColorSequenceKeypoint.new(0,   Color3.fromRGB(70,  70, 200)),
	ColorSequenceKeypoint.new(0.5, Color3.fromRGB(130, 90, 255)),
	ColorSequenceKeypoint.new(1,   Color3.fromRGB(70,  70, 200)),
})
AccGrad.Parent = AccLine

-- Title
local TitleLbl = Instance.new("TextLabel")
TitleLbl.Size             = UDim2.new(1, -100, 1, 0)
TitleLbl.Position         = UDim2.new(0, 14, 0, 0)
TitleLbl.BackgroundTransparency = 1
TitleLbl.Text             = "OG-Sniper Script"
TitleLbl.TextColor3       = Color3.fromRGB(235, 235, 255)
TitleLbl.TextSize         = isPhone and 14 or 16
TitleLbl.Font             = Enum.Font.GothamBold
TitleLbl.TextXAlignment   = Enum.TextXAlignment.Left
TitleLbl.ZIndex           = 4
TitleLbl.Parent           = TopBar

-- Version badge
local VerBg = Instance.new("Frame")
VerBg.Size             = UDim2.new(0, 34, 0, 16)
VerBg.Position         = UDim2.new(0, isPhone and 155 or 186, 0.5, -8)
VerBg.BackgroundColor3 = Color3.fromRGB(75, 55, 180)
VerBg.BorderSizePixel  = 0
VerBg.ZIndex           = 5
VerBg.Parent           = TopBar

local VerBgC = Instance.new("UICorner")
VerBgC.CornerRadius = UDim.new(1, 0)
VerBgC.Parent = VerBg

local VerTxt = Instance.new("TextLabel")
VerTxt.Size             = UDim2.new(1, 0, 1, 0)
VerTxt.BackgroundTransparency = 1
VerTxt.Text             = "v2.0"
VerTxt.TextColor3       = Color3.fromRGB(220, 210, 255)
VerTxt.TextSize         = 9
VerTxt.Font             = Enum.Font.GothamBold
VerTxt.ZIndex           = 6
VerTxt.Parent           = VerBg

-- Minimize button
local MinBtn = Instance.new("TextButton")
MinBtn.Size             = UDim2.new(0, 28, 0, 28)
MinBtn.Position         = UDim2.new(1, -66, 0.5, -14)
MinBtn.BackgroundColor3 = Color3.fromRGB(30, 30, 42)
MinBtn.Text             = "—"
MinBtn.TextColor3       = Color3.fromRGB(160, 160, 190)
MinBtn.TextSize         = 11
MinBtn.Font             = Enum.Font.GothamBold
MinBtn.BorderSizePixel  = 0
MinBtn.ZIndex           = 5
MinBtn.Parent           = TopBar

local MinBtnC = Instance.new("UICorner")
MinBtnC.CornerRadius = UDim.new(0, 7)
MinBtnC.Parent = MinBtn

-- Close button
local CloseBtn = Instance.new("TextButton")
CloseBtn.Size             = UDim2.new(0, 28, 0, 28)
CloseBtn.Position         = UDim2.new(1, -34, 0.5, -14)
CloseBtn.BackgroundColor3 = Color3.fromRGB(185, 45, 55)
CloseBtn.Text             = "✕"
CloseBtn.TextColor3       = Color3.fromRGB(255, 255, 255)
CloseBtn.TextSize         = 11
CloseBtn.Font             = Enum.Font.GothamBold
CloseBtn.BorderSizePixel  = 0
CloseBtn.ZIndex           = 5
CloseBtn.Parent           = TopBar

local CloseBtnC = Instance.new("UICorner")
CloseBtnC.CornerRadius = UDim.new(0, 7)
CloseBtnC.Parent = CloseBtn

-- ══════════════════════════════════════
--             SIDEBAR
-- ══════════════════════════════════════

local Sidebar = Instance.new("Frame")
Sidebar.Size             = UDim2.new(0, SIDE_W, 1, -TOP_H)
Sidebar.Position         = UDim2.new(0, 0, 0, TOP_H)
Sidebar.BackgroundColor3 = Color3.fromRGB(12, 12, 17)
Sidebar.BorderSizePixel  = 0
Sidebar.ZIndex           = 2
Sidebar.Parent           = Main

local SideDiv = Instance.new("Frame")
SideDiv.Size             = UDim2.new(0, 1, 1, 0)
SideDiv.Position         = UDim2.new(1, 0, 0, 0)
SideDiv.BackgroundColor3 = Color3.fromRGB(35, 35, 55)
SideDiv.BorderSizePixel  = 0
SideDiv.ZIndex           = 3
SideDiv.Parent           = Sidebar

-- ── Player info (small, bottom-left style, compact) ──

-- Avatar (small)
local AvatarF = Instance.new("Frame")
AvatarF.Size             = UDim2.new(0, 38, 0, 38)
AvatarF.Position         = UDim2.new(0.5, -19, 0, 14)
AvatarF.BackgroundColor3 = Color3.fromRGB(80, 60, 180)
AvatarF.BorderSizePixel  = 0
AvatarF.ZIndex           = 3
AvatarF.Parent           = Sidebar

local AvatarFC = Instance.new("UICorner")
AvatarFC.CornerRadius = UDim.new(1, 0)
AvatarFC.Parent = AvatarF

local AvatarStroke = Instance.new("UIStroke")
AvatarStroke.Color     = Color3.fromRGB(100, 80, 220)
AvatarStroke.Thickness = 1.5
AvatarStroke.Parent = AvatarF

local AvatarImg = Instance.new("ImageLabel")
AvatarImg.Size             = UDim2.new(1, 0, 1, 0)
AvatarImg.BackgroundTransparency = 1
AvatarImg.ZIndex           = 4
AvatarImg.Parent           = AvatarF

local AvatarImgC = Instance.new("UICorner")
AvatarImgC.CornerRadius = UDim.new(1, 0)
AvatarImgC.Parent = AvatarImg

local ok, content = pcall(function()
	return Players:GetUserThumbnailAsync(
		LocalPlayer.UserId,
		Enum.ThumbnailType.HeadShot,
		Enum.ThumbnailSize.Size100x100
	)
end)
if ok then AvatarImg.Image = content end

-- Display name
local DispName = Instance.new("TextLabel")
DispName.Size             = UDim2.new(1, -6, 0, 16)
DispName.Position         = UDim2.new(0, 3, 0, 56)
DispName.BackgroundTransparency = 1
DispName.Text             = LocalPlayer.DisplayName
DispName.TextColor3       = Color3.fromRGB(220, 220, 250)
DispName.TextSize         = isPhone and 10 or 11
DispName.Font             = Enum.Font.GothamBold
DispName.TextXAlignment   = Enum.TextXAlignment.Center
DispName.TextTruncate     = Enum.TextTruncate.AtEnd
DispName.ZIndex           = 3
DispName.Parent           = Sidebar

-- @username
local UserName = Instance.new("TextLabel")
UserName.Size             = UDim2.new(1, -6, 0, 14)
UserName.Position         = UDim2.new(0, 3, 0, 71)
UserName.BackgroundTransparency = 1
UserName.Text             = "@" .. LocalPlayer.Name
UserName.TextColor3       = Color3.fromRGB(100, 100, 140)
UserName.TextSize         = isPhone and 9 or 10
UserName.Font             = Enum.Font.Gotham
UserName.TextXAlignment   = Enum.TextXAlignment.Center
UserName.TextTruncate     = Enum.TextTruncate.AtEnd
UserName.ZIndex           = 3
UserName.Parent           = Sidebar

-- Separator
local Sep = Instance.new("Frame")
Sep.Size             = UDim2.new(0.7, 0, 0, 1)
Sep.Position         = UDim2.new(0.15, 0, 0, 92)
Sep.BackgroundColor3 = Color3.fromRGB(35, 35, 55)
Sep.BorderSizePixel  = 0
Sep.ZIndex           = 3
Sep.Parent           = Sidebar

-- Main tab button
local MainTab = Instance.new("Frame")
MainTab.Size             = UDim2.new(1, -14, 0, 32)
MainTab.Position         = UDim2.new(0, 7, 0, 102)
MainTab.BackgroundColor3 = Color3.fromRGB(75, 55, 180)
MainTab.BorderSizePixel  = 0
MainTab.ZIndex           = 3
MainTab.Parent           = Sidebar

local MainTabC = Instance.new("UICorner")
MainTabC.CornerRadius = UDim.new(0, 7)
MainTabC.Parent = MainTab

local MainTabGrad = Instance.new("UIGradient")
MainTabGrad.Color = ColorSequence.new({
	ColorSequenceKeypoint.new(0, Color3.fromRGB(95, 75, 210)),
	ColorSequenceKeypoint.new(1, Color3.fromRGB(55, 42, 140)),
})
MainTabGrad.Rotation = 90
MainTabGrad.Parent = MainTab

local MainTabTxt = Instance.new("TextLabel")
MainTabTxt.Size             = UDim2.new(1, -8, 1, 0)
MainTabTxt.Position         = UDim2.new(0, 8, 0, 0)
MainTabTxt.BackgroundTransparency = 1
MainTabTxt.Text             = "Main"
MainTabTxt.TextColor3       = Color3.fromRGB(255, 255, 255)
MainTabTxt.TextSize         = isPhone and 11 or 12
MainTabTxt.Font             = Enum.Font.GothamBold
MainTabTxt.TextXAlignment   = Enum.TextXAlignment.Left
MainTabTxt.ZIndex           = 4
MainTabTxt.Parent           = MainTab

-- ══════════════════════════════════════
--           CONTENT AREA
-- ══════════════════════════════════════

local ContentArea = Instance.new("Frame")
ContentArea.Size             = UDim2.new(1, -SIDE_W, 1, -TOP_H)
ContentArea.Position         = UDim2.new(0, SIDE_W, 0, TOP_H)
ContentArea.BackgroundTransparency = 1
ContentArea.ClipsDescendants = true
ContentArea.ZIndex           = 2
ContentArea.Parent           = Main

-- Section title
local SectionTitle = Instance.new("TextLabel")
SectionTitle.Size             = UDim2.new(1, -16, 0, 32)
SectionTitle.Position         = UDim2.new(0, 12, 0, 6)
SectionTitle.BackgroundTransparency = 1
SectionTitle.Text             = "Main  —  Select your sniper mode"
SectionTitle.TextColor3       = Color3.fromRGB(140, 140, 175)
SectionTitle.TextSize         = isPhone and 10 or 11
SectionTitle.Font             = Enum.Font.Gotham
SectionTitle.TextXAlignment   = Enum.TextXAlignment.Left
SectionTitle.ZIndex           = 3
SectionTitle.Parent           = ContentArea

-- Scroll
local Scroll = Instance.new("ScrollingFrame")
Scroll.Size                   = UDim2.new(1, -6, 1, -40)
Scroll.Position               = UDim2.new(0, 3, 0, 36)
Scroll.BackgroundTransparency = 1
Scroll.BorderSizePixel        = 0
Scroll.ScrollBarThickness     = 3
Scroll.ScrollBarImageColor3   = Color3.fromRGB(80, 60, 180)
Scroll.CanvasSize             = UDim2.new(0, 0, 0, 0)
Scroll.AutomaticCanvasSize    = Enum.AutomaticSize.Y
Scroll.ZIndex                 = 3
Scroll.Parent                 = ContentArea

local ListLayout = Instance.new("UIListLayout")
ListLayout.Padding    = UDim.new(0, 8)
ListLayout.SortOrder  = Enum.SortOrder.LayoutOrder
ListLayout.Parent     = Scroll

local ListPad = Instance.new("UIPadding")
ListPad.PaddingLeft   = UDim.new(0, 8)
ListPad.PaddingRight  = UDim.new(0, 10)
ListPad.PaddingTop    = UDim.new(0, 4)
ListPad.PaddingBottom = UDim.new(0, 12)
ListPad.Parent        = Scroll

-- ══════════════════════════════════════
--         CLOSE HELPER
-- ══════════════════════════════════════

local function CloseUI(then_fn)
	local t = TweenService:Create(Main,
		TweenInfo.new(0.28, Enum.EasingStyle.Back, Enum.EasingDirection.In),
		{Size = UDim2.new(0, 0, 0, 0), BackgroundTransparency = 1}
	)
	t:Play()
	t.Completed:Connect(function()
		ScreenGui:Destroy()
		if then_fn then then_fn() end
	end)
end

-- ══════════════════════════════════════
--       RECOMMENDATION BADGE
-- ══════════════════════════════════════

local LEVEL_CFG = {
	safe_high  = {bg = Color3.fromRGB(28, 148, 72),  text = "أمن جداً",  tag = "موصى به",  tagColor = Color3.fromRGB(60, 210, 110)},
	safe       = {bg = Color3.fromRGB(175, 140, 18), text = "أمن",        tag = nil,         tagColor = nil},
	acceptable = {bg = Color3.fromRGB(168, 44, 48),  text = "مقبول",      tag = "⚠ تحذير",  tagColor = Color3.fromRGB(220, 75, 75)},
}

local function MakeBadge(parent, level, yPos)
	local cfg = LEVEL_CFG[level]

	local wrap = Instance.new("Frame")
	wrap.Size             = UDim2.new(0, 180, 0, 26)
	wrap.Position         = UDim2.new(0, 0, 0, yPos)
	wrap.BackgroundTransparency = 1
	wrap.ZIndex           = 6
	wrap.Parent           = parent

	local lbl = Instance.new("TextLabel")
	lbl.Size             = UDim2.new(1, 0, 0, 11)
	lbl.BackgroundTransparency = 1
	lbl.Text             = "Recommendation Level"
	lbl.TextColor3       = Color3.fromRGB(100, 100, 140)
	lbl.TextSize         = 8
	lbl.Font             = Enum.Font.Gotham
	lbl.TextXAlignment   = Enum.TextXAlignment.Left
	lbl.ZIndex           = 6
	lbl.Parent           = wrap

	local badge = Instance.new("Frame")
	badge.Size             = UDim2.new(0, 62, 0, 15)
	badge.Position         = UDim2.new(0, 0, 0, 11)
	badge.BackgroundColor3 = cfg.bg
	badge.BorderSizePixel  = 0
	badge.ZIndex           = 6
	badge.Parent           = wrap

	local bc = Instance.new("UICorner")
	bc.CornerRadius = UDim.new(1, 0)
	bc.Parent = badge

	local bt = Instance.new("TextLabel")
	bt.Size             = UDim2.new(1, 0, 1, 0)
	bt.BackgroundTransparency = 1
	bt.Text             = cfg.text
	bt.TextColor3       = Color3.fromRGB(255, 255, 255)
	bt.TextSize         = 8
	bt.Font             = Enum.Font.GothamBold
	bt.ZIndex           = 7
	bt.Parent           = badge

	if cfg.tag then
		local tl = Instance.new("TextLabel")
		tl.Size             = UDim2.new(0, 80, 0, 15)
		tl.Position         = UDim2.new(0, 66, 0, 11)
		tl.BackgroundTransparency = 1
		tl.Text             = cfg.tag
		tl.TextColor3       = cfg.tagColor
		tl.TextSize         = 8
		tl.Font             = Enum.Font.GothamBold
		tl.TextXAlignment   = Enum.TextXAlignment.Left
		tl.ZIndex           = 7
		tl.Parent           = wrap
	end
end

-- ══════════════════════════════════════
--          CARD BUILDER
-- ══════════════════════════════════════

local function CreateCard(order, title, desc, level, callback, imgId)

	local Card = Instance.new("Frame")
	Card.Name             = "Card" .. order
	Card.Size             = UDim2.new(1, 0, 0, CARD_H)
	Card.BackgroundColor3 = Color3.fromRGB(16, 16, 23)
	Card.BorderSizePixel  = 0
	Card.LayoutOrder      = order
	Card.ZIndex           = 4
	Card.Parent           = Scroll

	local CC = Instance.new("UICorner")
	CC.CornerRadius = UDim.new(0, 9)
	CC.Parent = Card

	local CS = Instance.new("UIStroke")
	CS.Color       = Color3.fromRGB(38, 38, 58)
	CS.Thickness   = 1
	CS.Parent = Card

	-- Number badge
	local Num = Instance.new("Frame")
	Num.Size             = UDim2.new(0, 22, 0, 22)
	Num.Position         = UDim2.new(0, 10, 0, 10)
	Num.BackgroundColor3 = Color3.fromRGB(55, 42, 130)
	Num.BorderSizePixel  = 0
	Num.ZIndex           = 5
	Num.Parent           = Card

	local NC = Instance.new("UICorner")
	NC.CornerRadius = UDim.new(0, 5)
	NC.Parent = Num

	local NT = Instance.new("TextLabel")
	NT.Size             = UDim2.new(1, 0, 1, 0)
	NT.BackgroundTransparency = 1
	NT.Text             = tostring(order)
	NT.TextColor3       = Color3.fromRGB(190, 180, 255)
	NT.TextSize         = 11
	NT.Font             = Enum.Font.GothamBold
	NT.ZIndex           = 6
	NT.Parent           = Num

	-- Card title
	local CTL = Instance.new("TextLabel")
	CTL.Size             = UDim2.new(1, -120, 0, 22)
	CTL.Position         = UDim2.new(0, 38, 0, 9)
	CTL.BackgroundTransparency = 1
	CTL.Text             = title
	CTL.TextColor3       = Color3.fromRGB(225, 225, 250)
	CTL.TextSize         = isPhone and 10 or 11
	CTL.Font             = Enum.Font.GothamBold
	CTL.TextXAlignment   = Enum.TextXAlignment.Left
	CTL.TextTruncate     = Enum.TextTruncate.AtEnd
	CTL.ZIndex           = 5
	CTL.Parent           = Card

	-- Divider
	local Div = Instance.new("Frame")
	Div.Size             = UDim2.new(1, -18, 0, 1)
	Div.Position         = UDim2.new(0, 9, 0, 35)
	Div.BackgroundColor3 = Color3.fromRGB(30, 30, 48)
	Div.BorderSizePixel  = 0
	Div.ZIndex           = 5
	Div.Parent           = Card

	-- Description
	local Desc = Instance.new("TextLabel")
	Desc.Size             = UDim2.new(0, isPhone and 140 or 160, 0, 28)
	Desc.Position         = UDim2.new(0, 10, 0, 40)
	Desc.BackgroundTransparency = 1
	Desc.Text             = desc
	Desc.TextColor3       = Color3.fromRGB(120, 120, 160)
	Desc.TextSize         = isPhone and 9 or 10
	Desc.Font             = Enum.Font.Gotham
	Desc.TextXAlignment   = Enum.TextXAlignment.Left
	Desc.TextYAlignment   = Enum.TextYAlignment.Top
	Desc.TextWrapped      = true
	Desc.ZIndex           = 5
	Desc.Parent           = Card

	-- Recommendation Level badge
	MakeBadge(Card, level, 76)

	-- Image holder (right side)
	local ImgW  = isPhone and 110 or 130
	local ImgH  = CARD_H - 26
	local ImgHolder = Instance.new("Frame")
	ImgHolder.Size             = UDim2.new(0, ImgW, 0, ImgH)
	ImgHolder.Position         = UDim2.new(1, -(ImgW + 10), 0, 12)
	ImgHolder.BackgroundColor3 = Color3.fromRGB(20, 20, 30)
	ImgHolder.BorderSizePixel  = 0
	ImgHolder.ZIndex           = 5
	ImgHolder.Parent           = Card

	local IHC = Instance.new("UICorner")
	IHC.CornerRadius = UDim.new(0, 7)
	IHC.Parent = ImgHolder

	local IHS = Instance.new("UIStroke")
	IHS.Color     = Color3.fromRGB(40, 40, 62)
	IHS.Thickness = 1
	IHS.Parent = ImgHolder

	local ImgLbl = Instance.new("ImageLabel")
	ImgLbl.Size             = UDim2.new(1, -4, 1, -4)
	ImgLbl.Position         = UDim2.new(0, 2, 0, 2)
	ImgLbl.BackgroundTransparency = 1
	ImgLbl.ScaleType        = Enum.ScaleType.Fit
	ImgLbl.Image            = (imgId and imgId ~= "") and imgId or ""
	ImgLbl.ZIndex           = 6
	ImgLbl.Parent           = ImgHolder

	local ImgPlaceholder = Instance.new("TextLabel")
	ImgPlaceholder.Size             = UDim2.new(1, 0, 1, 0)
	ImgPlaceholder.BackgroundTransparency = 1
	ImgPlaceholder.Text             = (imgId and imgId ~= "") and "" or "🖼\nضع صورتك\nهنا"
	ImgPlaceholder.TextColor3       = Color3.fromRGB(55, 55, 80)
	ImgPlaceholder.TextSize         = 9
	ImgPlaceholder.Font             = Enum.Font.Gotham
	ImgPlaceholder.TextWrapped      = true
	ImgPlaceholder.ZIndex           = 6
	ImgPlaceholder.Parent           = ImgHolder
	local BtnW = isPhone and 118 or 138
	local ActivateBtn = Instance.new("TextButton")
	ActivateBtn.Size             = UDim2.new(0, BtnW, 0, 28)
	ActivateBtn.Position         = UDim2.new(0, 10, 1, -38)
	ActivateBtn.BackgroundColor3 = Color3.fromRGB(22, 22, 34)
	ActivateBtn.Text             = "▶  تشغيل"
	ActivateBtn.TextColor3       = Color3.fromRGB(170, 155, 255)
	ActivateBtn.TextSize         = isPhone and 13 or 14
	ActivateBtn.Font             = Enum.Font.GothamBold
	ActivateBtn.BorderSizePixel  = 0
	ActivateBtn.ZIndex           = 6
	ActivateBtn.Parent           = Card

	local ABtnC = Instance.new("UICorner")
	ABtnC.CornerRadius = UDim.new(0, 7)
	ABtnC.Parent = ActivateBtn

	local ABtnS = Instance.new("UIStroke")
	ABtnS.Color     = Color3.fromRGB(80, 60, 180)
	ABtnS.Thickness = 1.2
	ABtnS.Parent = ActivateBtn

	-- Hover
	ActivateBtn.MouseEnter:Connect(function()
		TweenService:Create(ActivateBtn, TweenInfo.new(0.14), {
			BackgroundColor3 = Color3.fromRGB(32, 28, 52),
			TextColor3       = Color3.fromRGB(200, 190, 255),
		}):Play()
	end)
	ActivateBtn.MouseLeave:Connect(function()
		TweenService:Create(ActivateBtn, TweenInfo.new(0.14), {
			BackgroundColor3 = Color3.fromRGB(22, 22, 34),
			TextColor3       = Color3.fromRGB(170, 155, 255),
		}):Play()
	end)

	-- Click
	ActivateBtn.MouseButton1Click:Connect(function()
		-- Flash
		local flash = Instance.new("Frame")
		flash.Size             = UDim2.new(1, 0, 1, 0)
		flash.BackgroundColor3 = Color3.fromRGB(110, 90, 240)
		flash.BackgroundTransparency = 0.65
		flash.BorderSizePixel  = 0
		flash.ZIndex           = 20
		flash.Parent           = Main
		local fc = Instance.new("UICorner")
		fc.CornerRadius = UDim.new(0, 11)
		fc.Parent = flash
		TweenService:Create(flash, TweenInfo.new(0.3), {BackgroundTransparency = 1}):Play()
		task.delay(0.3, function() flash:Destroy() end)

		task.delay(0.1, function()
			CloseUI(callback)
		end)
	end)

	return Card
end

-- ══════════════════════════════════════
--            BUILD CARDS
-- ══════════════════════════════════════

CreateCard(1,
	"OG-Sniper with 0.45 AimDelay",
	"ارجاع السنايبر القديم مع تاخير 0.45 عند الاطلاق",
	"acceptable",
	OGSniper_045,
	""   -- ← rbxassetid://XXXXXX
)

CreateCard(2,
	"OG-Sniper with 0.65 AimDelay",
	"ارجاع السنايبر القديم مع تاخير 0.65 عند الاطلاق",
	"safe_high",
	OGSniper_065,
	""
)

CreateCard(3,
	"NEW-Sniper with better view with 0.45 AimDelay",
	"السنايبر الجديد نسخة محسنة ورؤية اكبر مع 0.45 تاخير الاطلاق",
	"safe",
	NEWSniper_045,
	""
)

CreateCard(4,
	"NEW-Sniper with better view with 0.65 AimDelay",
	"السنايبر الجديد نسخة محسنة ورؤية اكبر مع 0.65 تاخير الاطلاق",
	"safe_high",
	NEWSniper_065,
	""
)

-- ══════════════════════════════════════
--           DRAGGING
-- ══════════════════════════════════════

local dragging, dragStart, startPos = false, nil, nil

TopBar.InputBegan:Connect(function(i)
	if i.UserInputType == Enum.UserInputType.MouseButton1
		or i.UserInputType == Enum.UserInputType.Touch then
		dragging  = true
		dragStart = i.Position
		startPos  = Main.Position
	end
end)

UserInputService.InputChanged:Connect(function(i)
	if dragging and (i.UserInputType == Enum.UserInputType.MouseMovement
		or i.UserInputType == Enum.UserInputType.Touch) then
		local d = i.Position - dragStart
		Main.Position = UDim2.new(
			startPos.X.Scale, startPos.X.Offset + d.X,
			startPos.Y.Scale, startPos.Y.Offset + d.Y
		)
	end
end)

UserInputService.InputEnded:Connect(function(i)
	if i.UserInputType == Enum.UserInputType.MouseButton1
		or i.UserInputType == Enum.UserInputType.Touch then
		dragging = false
	end
end)

-- ══════════════════════════════════════
--       CLOSE / MINIMIZE BUTTONS
-- ══════════════════════════════════════

CloseBtn.MouseButton1Click:Connect(function()
	CloseUI(nil)
end)

local minimized = false
MinBtn.MouseButton1Click:Connect(function()
	minimized = not minimized
	TweenService:Create(Main, TweenInfo.new(0.22, Enum.EasingStyle.Quad), {
		Size = minimized
			and UDim2.new(0, UI_W, 0, TOP_H)
			or  UDim2.new(0, UI_W, 0, UI_H)
	}):Play()
	MinBtn.Text = minimized and "▢" or "—"
end)

-- ══════════════════════════════════════
--         OPEN ANIMATION
-- ══════════════════════════════════════

local openTween = TweenService:Create(Main,
	TweenInfo.new(0.45, Enum.EasingStyle.Back, Enum.EasingDirection.Out),
	{
		Size                  = UDim2.new(0, UI_W, 0, UI_H),
		BackgroundTransparency = 0,
	}
)
openTween:Play()

task.delay(0.18, function()
	for _, f in ipairs({TopBar, Sidebar, ContentArea}) do
		if f:IsA("Frame") then
			local orig = f.BackgroundTransparency
			f.BackgroundTransparency = 1
			TweenService:Create(f, TweenInfo.new(0.28), {BackgroundTransparency = orig}):Play()
		end
	end
end)

task.delay(0.38, function()
	TweenService:Create(AccGrad,
		TweenInfo.new(1.4, Enum.EasingStyle.Sine, Enum.EasingDirection.InOut, 3, true),
		{Offset = Vector2.new(0.4, 0)}
	):Play()
end)
