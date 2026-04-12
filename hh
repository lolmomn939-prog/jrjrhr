local function OGSniper_045()  print("OG Sniper 0.45 Activated")  end
local function OGSniper_065()  print("OG Sniper 0.65 Activated")  end
local function NEWSniper_045() print("NEW Sniper 0.45 Activated") end
local function NEWSniper_065() print("NEW Sniper 0.65 Activated") end

local Players          = game:GetService("Players")
local TweenService     = game:GetService("TweenService")
local UserInputService = game:GetService("UserInputService")

local LocalPlayer = Players.LocalPlayer
local PlayerGui   = LocalPlayer:WaitForChild("PlayerGui")

local old = PlayerGui:FindFirstChild("OGSniperUI")
if old then old:Destroy() end

-- ── sizes ──────────────────────────────────────────────────────────────────
local screen  = workspace.CurrentCamera and workspace.CurrentCamera.ViewportSize or Vector2.new(800,600)
local isPhone = screen.X < 650

local UI_W   = isPhone and math.min(screen.X - 16, 500) or 700
local UI_H   = isPhone and math.min(screen.Y - 50, 560) or 560
local SIDE_W = isPhone and 120 or 148
local TOP_H  = 48
local CARD_H = isPhone and 188 or 200

-- ── palette (NO purple) ────────────────────────────────────────────────────
local C = {
	bg         = Color3.fromRGB(10,  10,  15),
	topbar     = Color3.fromRGB(14,  14,  21),
	sidebar    = Color3.fromRGB(12,  12,  18),
	card       = Color3.fromRGB(17,  17,  25),
	accent     = Color3.fromRGB(38, 120, 220),   -- blue accent
	accentDark = Color3.fromRGB(24,  80, 170),
	tabBg      = Color3.fromRGB(24,  80, 170),   -- blue tab
	tabBg2     = Color3.fromRGB(16,  56, 130),
	border     = Color3.fromRGB(36,  36,  56),
	text1      = Color3.fromRGB(240, 240, 255),
	text2      = Color3.fromRGB(190, 190, 215),
	text3      = Color3.fromRGB(155, 155, 185),
	dim        = Color3.fromRGB(80,  80, 110),
	btnDark    = Color3.fromRGB(20,  20,  30),
	btnBorder  = Color3.fromRGB(50, 100, 200),
	btnTxt     = Color3.fromRGB(120, 175, 255),
	green      = Color3.fromRGB(28, 155, 75),
	yellow     = Color3.fromRGB(180, 148, 18),
	red        = Color3.fromRGB(185, 44,  50),
}

-- ══════════════════════════════════════
--           HELPERS
-- ══════════════════════════════════════

local function corner(parent, px)
	local u = Instance.new("UICorner")
	u.CornerRadius = UDim.new(0, px or 8)
	u.Parent = parent
	return u
end

local function stroke(parent, color, thick)
	local s = Instance.new("UIStroke")
	s.Color     = color or C.border
	s.Thickness = thick or 1
	s.Parent    = parent
	return s
end

local function label(parent, props)
	local l = Instance.new("TextLabel")
	l.BackgroundTransparency = 1
	for k,v in pairs(props) do l[k] = v end
	l.Parent = parent
	return l
end

-- ══════════════════════════════════════
--            MAIN FRAME
-- ══════════════════════════════════════

local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name           = "OGSniperUI"
ScreenGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
ScreenGui.ResetOnSpawn   = false
ScreenGui.IgnoreGuiInset = true
ScreenGui.Parent         = PlayerGui

local Main = Instance.new("Frame")
Main.Name                   = "Main"
Main.AnchorPoint            = Vector2.new(0.5, 0.5)
Main.Position               = UDim2.new(0.5, 0, 0.5, 0)
Main.Size                   = UDim2.new(0, 0, 0, 0)
Main.BackgroundColor3       = C.bg
Main.BackgroundTransparency = 1
Main.BorderSizePixel        = 0
Main.ClipsDescendants       = true
Main.Parent                 = ScreenGui
corner(Main, 12)
stroke(Main, C.border, 1)

-- ══════════════════════════════════════
--              TOPBAR
-- ══════════════════════════════════════

local TopBar = Instance.new("Frame")
TopBar.Size             = UDim2.new(1, 0, 0, TOP_H)
TopBar.BackgroundColor3 = C.topbar
TopBar.BorderSizePixel  = 0
TopBar.ZIndex           = 3
TopBar.Parent           = Main
corner(TopBar, 12)

-- fix bottom round
local TBFix = Instance.new("Frame")
TBFix.Size             = UDim2.new(1, 0, 0, 12)
TBFix.Position         = UDim2.new(0, 0, 1, -12)
TBFix.BackgroundColor3 = C.topbar
TBFix.BorderSizePixel  = 0
TBFix.ZIndex           = 3
TBFix.Parent           = TopBar

-- accent line
local AccLine = Instance.new("Frame")
AccLine.Size             = UDim2.new(1, 0, 0, 2)
AccLine.Position         = UDim2.new(0, 0, 1, 0)
AccLine.BackgroundColor3 = C.accent
AccLine.BorderSizePixel  = 0
AccLine.ZIndex           = 4
AccLine.Parent           = TopBar

local AccGrad = Instance.new("UIGradient")
AccGrad.Color = ColorSequence.new({
	ColorSequenceKeypoint.new(0,   Color3.fromRGB(20, 90, 200)),
	ColorSequenceKeypoint.new(0.5, Color3.fromRGB(60, 150, 255)),
	ColorSequenceKeypoint.new(1,   Color3.fromRGB(20, 90, 200)),
})
AccGrad.Parent = AccLine

-- title
label(TopBar, {
	Size = UDim2.new(1, -110, 1, 0),
	Position = UDim2.new(0, 14, 0, 0),
	Text = "OG-Sniper Script",
	TextColor3 = C.text1,
	TextSize = isPhone and 14 or 16,
	Font = Enum.Font.GothamBold,
	TextXAlignment = Enum.TextXAlignment.Left,
	ZIndex = 4,
})

-- v2.0 badge — BLUE not purple
local VerBg = Instance.new("Frame")
VerBg.Size             = UDim2.new(0, 40, 0, 18)
VerBg.Position         = UDim2.new(0, isPhone and 158 or 190, 0.5, -9)
VerBg.BackgroundColor3 = Color3.fromRGB(24, 80, 170)
VerBg.BorderSizePixel  = 0
VerBg.ZIndex           = 5
VerBg.Parent           = TopBar
corner(VerBg, 9)

label(VerBg, {
	Size = UDim2.new(1,0,1,0),
	Text = "v3.0",
	TextColor3 = Color3.fromRGB(180, 215, 255),
	TextSize = 10,
	Font = Enum.Font.GothamBold,
	ZIndex = 6,
})

-- minimize
local MinBtn = Instance.new("TextButton")
MinBtn.Size             = UDim2.new(0, 30, 0, 30)
MinBtn.Position         = UDim2.new(1, -70, 0.5, -15)
MinBtn.BackgroundColor3 = Color3.fromRGB(28, 28, 40)
MinBtn.Text             = "—"
MinBtn.TextColor3       = C.text3
MinBtn.TextSize         = 12
MinBtn.Font             = Enum.Font.GothamBold
MinBtn.BorderSizePixel  = 0
MinBtn.ZIndex           = 5
MinBtn.Parent           = TopBar
corner(MinBtn, 8)

-- close  ← ❌ emoji
local CloseBtn = Instance.new("TextButton")
CloseBtn.Size             = UDim2.new(0, 30, 0, 30)
CloseBtn.Position         = UDim2.new(1, -36, 0.5, -15)
CloseBtn.BackgroundColor3 = Color3.fromRGB(190, 44, 52)
CloseBtn.Text             = "❌"
CloseBtn.TextColor3       = Color3.fromRGB(255, 255, 255)
CloseBtn.TextSize         = 14
CloseBtn.Font             = Enum.Font.GothamBold
CloseBtn.BorderSizePixel  = 0
CloseBtn.ZIndex           = 5
CloseBtn.Parent           = TopBar
corner(CloseBtn, 8)

-- ══════════════════════════════════════
--             SIDEBAR
-- ══════════════════════════════════════

local Sidebar = Instance.new("Frame")
Sidebar.Size             = UDim2.new(0, SIDE_W, 1, -TOP_H)
Sidebar.Position         = UDim2.new(0, 0, 0, TOP_H)
Sidebar.BackgroundColor3 = C.sidebar
Sidebar.BorderSizePixel  = 0
Sidebar.ZIndex           = 2
Sidebar.Parent           = Main

local SideDiv = Instance.new("Frame")
SideDiv.Size             = UDim2.new(0, 1, 1, 0)
SideDiv.Position         = UDim2.new(1, 0, 0, 0)
SideDiv.BackgroundColor3 = C.border
SideDiv.BorderSizePixel  = 0
SideDiv.ZIndex           = 3
SideDiv.Parent           = Sidebar

-- Avatar (compact)
local AvatarF = Instance.new("Frame")
AvatarF.Size             = UDim2.new(0, 42, 0, 42)
AvatarF.Position         = UDim2.new(0.5, -21, 0, 14)
AvatarF.BackgroundColor3 = C.accentDark
AvatarF.BorderSizePixel  = 0
AvatarF.ZIndex           = 3
AvatarF.Parent           = Sidebar
corner(AvatarF, 21)
stroke(AvatarF, C.accent, 1.5)

local AvatarImg = Instance.new("ImageLabel")
AvatarImg.Size             = UDim2.new(1,0,1,0)
AvatarImg.BackgroundTransparency = 1
AvatarImg.ZIndex           = 4
AvatarImg.Parent           = AvatarF
corner(AvatarImg, 21)

local ok, thumb = pcall(function()
	return Players:GetUserThumbnailAsync(
		LocalPlayer.UserId,
		Enum.ThumbnailType.HeadShot,
		Enum.ThumbnailSize.Size100x100
	)
end)
if ok then AvatarImg.Image = thumb end

label(Sidebar, {
	Size = UDim2.new(1,-8,0,16),
	Position = UDim2.new(0,4,0,60),
	Text = LocalPlayer.DisplayName,
	TextColor3 = C.text1,
	TextSize = 11,
	Font = Enum.Font.GothamBold,
	TextXAlignment = Enum.TextXAlignment.Center,
	TextTruncate = Enum.TextTruncate.AtEnd,
	ZIndex = 3,
})

label(Sidebar, {
	Size = UDim2.new(1,-8,0,13),
	Position = UDim2.new(0,4,0,75),
	Text = "@" .. LocalPlayer.Name,
	TextColor3 = C.dim,
	TextSize = 9,
	Font = Enum.Font.Gotham,
	TextXAlignment = Enum.TextXAlignment.Center,
	TextTruncate = Enum.TextTruncate.AtEnd,
	ZIndex = 3,
})

local Sep = Instance.new("Frame")
Sep.Size             = UDim2.new(0.65,0,0,1)
Sep.Position         = UDim2.new(0.175,0,0,94)
Sep.BackgroundColor3 = C.border
Sep.BorderSizePixel  = 0
Sep.ZIndex           = 3
Sep.Parent           = Sidebar

-- Main tab — BLUE
local MainTab = Instance.new("Frame")
MainTab.Size             = UDim2.new(1,-14,0,34)
MainTab.Position         = UDim2.new(0,7,0,103)
MainTab.BackgroundColor3 = C.tabBg
MainTab.BorderSizePixel  = 0
MainTab.ZIndex           = 3
MainTab.Parent           = Sidebar
corner(MainTab, 8)

local MTGrad = Instance.new("UIGradient")
MTGrad.Color = ColorSequence.new({
	ColorSequenceKeypoint.new(0, Color3.fromRGB(30, 100, 210)),
	ColorSequenceKeypoint.new(1, Color3.fromRGB(16, 60, 140)),
})
MTGrad.Rotation = 90
MTGrad.Parent = MainTab

label(MainTab, {
	Size = UDim2.new(1,-8,1,0),
	Position = UDim2.new(0,8,0,0),
	Text = "Main",
	TextColor3 = Color3.fromRGB(255,255,255),
	TextSize = isPhone and 12 or 13,
	Font = Enum.Font.GothamBold,
	TextXAlignment = Enum.TextXAlignment.Left,
	ZIndex = 4,
})

-- ══════════════════════════════════════
--           CONTENT + SCROLL
-- ══════════════════════════════════════

local ContentArea = Instance.new("Frame")
ContentArea.Size             = UDim2.new(1,-SIDE_W,1,-TOP_H)
ContentArea.Position         = UDim2.new(0,SIDE_W,0,TOP_H)
ContentArea.BackgroundTransparency = 1
ContentArea.ClipsDescendants = true
ContentArea.ZIndex           = 2
ContentArea.Parent           = Main

label(ContentArea, {
	Size = UDim2.new(1,-14,0,30),
	Position = UDim2.new(0,12,0,5),
	Text = "Main  —  Select your sniper mode",
	TextColor3 = C.text3,
	TextSize = isPhone and 10 or 11,
	Font = Enum.Font.Gotham,
	TextXAlignment = Enum.TextXAlignment.Left,
	ZIndex = 3,
})

local Scroll = Instance.new("ScrollingFrame")
Scroll.Size                   = UDim2.new(1,-6,1,-34)
Scroll.Position               = UDim2.new(0,3,0,30)
Scroll.BackgroundTransparency = 1
Scroll.BorderSizePixel        = 0
Scroll.ScrollBarThickness     = 3
Scroll.ScrollBarImageColor3   = C.accent
Scroll.CanvasSize             = UDim2.new(0,0,0,0)
Scroll.AutomaticCanvasSize    = Enum.AutomaticSize.Y
Scroll.ZIndex                 = 3
Scroll.Parent                 = ContentArea

local LL = Instance.new("UIListLayout")
LL.Padding   = UDim.new(0,8)
LL.SortOrder = Enum.SortOrder.LayoutOrder
LL.Parent    = Scroll

local LP = Instance.new("UIPadding")
LP.PaddingLeft   = UDim.new(0,8)
LP.PaddingRight  = UDim.new(0,10)
LP.PaddingTop    = UDim.new(0,4)
LP.PaddingBottom = UDim.new(0,12)
LP.Parent        = Scroll

-- ══════════════════════════════════════
--         CLOSE HELPER
-- ══════════════════════════════════════

local function CloseUI(cb)
	local t = TweenService:Create(Main,
		TweenInfo.new(0.26, Enum.EasingStyle.Back, Enum.EasingDirection.In),
		{Size = UDim2.new(0,0,0,0), BackgroundTransparency = 1}
	)
	t:Play()
	t.Completed:Connect(function()
		ScreenGui:Destroy()
		if cb then cb() end
	end)
end

-- ══════════════════════════════════════
--       RECOMMENDATION BADGE
-- ══════════════════════════════════════

local LEVELS = {
	safe_high  = {bg=Color3.fromRGB(28,155,75),  txt="أمن جداً", tag="موصى به",  tagC=Color3.fromRGB(60,200,110)},
	safe       = {bg=Color3.fromRGB(180,148,18),  txt="أمن",      tag=nil,        tagC=nil},
	acceptable = {bg=Color3.fromRGB(185,44,50),   txt="مقبول",    tag="⚠ تحذير", tagC=Color3.fromRGB(230,80,80)},
}

local function MakeBadge(parent, level, yPos)
	local cfg = LEVELS[level]
	local w = Instance.new("Frame")
	w.Size             = UDim2.new(0,200,0,28)
	w.Position         = UDim2.new(0,0,0,yPos)
	w.BackgroundTransparency = 1
	w.ZIndex           = 6
	w.Parent           = parent

	label(w, {
		Size=UDim2.new(1,0,0,12), Text="Recommendation Level",
		TextColor3=C.text3, TextSize=8, Font=Enum.Font.Gotham,
		TextXAlignment=Enum.TextXAlignment.Left, ZIndex=6,
	})

	local bg = Instance.new("Frame")
	bg.Size             = UDim2.new(0,68,0,16)
	bg.Position         = UDim2.new(0,0,0,12)
	bg.BackgroundColor3 = cfg.bg
	bg.BorderSizePixel  = 0
	bg.ZIndex           = 6
	bg.Parent           = w
	corner(bg, 8)

	label(bg, {
		Size=UDim2.new(1,0,1,0), Text=cfg.txt,
		TextColor3=Color3.fromRGB(255,255,255), TextSize=9,
		Font=Enum.Font.GothamBold, ZIndex=7,
	})

	if cfg.tag then
		label(w, {
			Size=UDim2.new(0,90,0,16), Position=UDim2.new(0,72,0,12),
			Text=cfg.tag, TextColor3=cfg.tagC, TextSize=9,
			Font=Enum.Font.GothamBold, TextXAlignment=Enum.TextXAlignment.Left,
			ZIndex=7,
		})
	end
end

-- ══════════════════════════════════════
--           CARD BUILDER
-- ══════════════════════════════════════

local function CreateCard(order, title, desc, level, callback, imgId)

	local Card = Instance.new("Frame")
	Card.Name             = "Card"..order
	Card.Size             = UDim2.new(1,0,0,CARD_H)
	Card.BackgroundColor3 = C.card
	Card.BorderSizePixel  = 0
	Card.LayoutOrder      = order
	Card.ZIndex           = 4
	Card.Parent           = Scroll
	corner(Card, 10)
	stroke(Card, C.border, 1)

	-- ── number badge ──
	local Num = Instance.new("Frame")
	Num.Size             = UDim2.new(0,24,0,24)
	Num.Position         = UDim2.new(0,10,0,10)
	Num.BackgroundColor3 = C.accentDark
	Num.BorderSizePixel  = 0
	Num.ZIndex           = 5
	Num.Parent           = Card
	corner(Num, 6)

	label(Num, {
		Size=UDim2.new(1,0,1,0), Text=tostring(order),
		TextColor3=Color3.fromRGB(180,215,255), TextSize=12,
		Font=Enum.Font.GothamBold, ZIndex=6,
	})

	-- ── card title ──
	label(Card, {
		Size=UDim2.new(1,-160,0,24),
		Position=UDim2.new(0,40,0,9),
		Text=title,
		TextColor3=C.text1,
		TextSize=isPhone and 11 or 12,
		Font=Enum.Font.GothamBold,
		TextXAlignment=Enum.TextXAlignment.Left,
		TextTruncate=Enum.TextTruncate.AtEnd,
		ZIndex=5,
	})

	-- ── divider ──
	local Div = Instance.new("Frame")
	Div.Size             = UDim2.new(1,-18,0,1)
	Div.Position         = UDim2.new(0,9,0,36)
	Div.BackgroundColor3 = Color3.fromRGB(28,28,44)
	Div.BorderSizePixel  = 0
	Div.ZIndex           = 5
	Div.Parent           = Card

	-- ── description (bigger, visible) ──
	label(Card, {
		Size=UDim2.new(0,isPhone and 150 or 170,0,34),
		Position=UDim2.new(0,10,0,40),
		Text=desc,
		TextColor3=C.text2,
		TextSize=isPhone and 11 or 12,
		Font=Enum.Font.Gotham,
		TextXAlignment=Enum.TextXAlignment.Left,
		TextYAlignment=Enum.TextYAlignment.Top,
		TextWrapped=true,
		ZIndex=5,
	})

	-- ── recommendation badge ──
	MakeBadge(Card, level, 82)

	-- ── image holder (wider X axis) ──
	local ImgW = isPhone and 130 or 150
	local ImgH = CARD_H - 22

	local ImgHolder = Instance.new("Frame")
	ImgHolder.Size             = UDim2.new(0,ImgW,0,ImgH)
	ImgHolder.Position         = UDim2.new(1,-(ImgW+8),0,10)
	ImgHolder.BackgroundColor3 = Color3.fromRGB(20,20,32)
	ImgHolder.BorderSizePixel  = 0
	ImgHolder.ZIndex           = 5
	ImgHolder.Parent           = Card
	corner(ImgHolder, 8)
	stroke(ImgHolder, Color3.fromRGB(36,36,56), 1)

	local ImgLbl = Instance.new("ImageLabel")
	ImgLbl.Size             = UDim2.new(1,-4,1,-4)
	ImgLbl.Position         = UDim2.new(0,2,0,2)
	ImgLbl.BackgroundTransparency = 1
	ImgLbl.ScaleType        = Enum.ScaleType.Fit
	ImgLbl.Image            = (imgId and imgId~="") and imgId or ""
	ImgLbl.ZIndex           = 6
	ImgLbl.Parent           = ImgHolder

	if not (imgId and imgId~="") then
		label(ImgHolder, {
			Size=UDim2.new(1,0,1,0), Text="🖼\nضع صورتك\nهنا",
			TextColor3=Color3.fromRGB(55,55,80), TextSize=9,
			Font=Enum.Font.Gotham, TextWrapped=true, ZIndex=6,
		})
	end

	-- ── ACTIVATE BUTTON (dark + blue border, no purple) ──
	local BtnW = isPhone and 130 or 150

	local ActivateBtn = Instance.new("TextButton")
	ActivateBtn.Size             = UDim2.new(0,BtnW,0,30)
	ActivateBtn.Position         = UDim2.new(0,10,1,-40)
	ActivateBtn.BackgroundColor3 = Color3.fromRGB(18,18,28)
	ActivateBtn.Text             = "▶  تشغيل"
	ActivateBtn.TextColor3       = Color3.fromRGB(110,175,255)
	ActivateBtn.TextSize         = isPhone and 14 or 15
	ActivateBtn.Font             = Enum.Font.GothamBold
	ActivateBtn.BorderSizePixel  = 0
	ActivateBtn.ZIndex           = 6
	ActivateBtn.Parent           = Card
	corner(ActivateBtn, 8)
	stroke(ActivateBtn, Color3.fromRGB(40,100,210), 1.2)

	ActivateBtn.MouseEnter:Connect(function()
		TweenService:Create(ActivateBtn, TweenInfo.new(0.12), {
			BackgroundColor3 = Color3.fromRGB(26,40,70),
			TextColor3       = Color3.fromRGB(155,200,255),
		}):Play()
	end)
	ActivateBtn.MouseLeave:Connect(function()
		TweenService:Create(ActivateBtn, TweenInfo.new(0.12), {
			BackgroundColor3 = Color3.fromRGB(18,18,28),
			TextColor3       = Color3.fromRGB(110,175,255),
		}):Play()
	end)

	ActivateBtn.MouseButton1Click:Connect(function()
		local flash = Instance.new("Frame")
		flash.Size                   = UDim2.new(1,0,1,0)
		flash.BackgroundColor3       = Color3.fromRGB(60,130,255)
		flash.BackgroundTransparency = 0.7
		flash.BorderSizePixel        = 0
		flash.ZIndex                 = 20
		flash.Parent                 = Main
		corner(flash, 12)
		TweenService:Create(flash, TweenInfo.new(0.3), {BackgroundTransparency=1}):Play()
		task.delay(0.3, function() flash:Destroy() end)
		task.delay(0.1, function() CloseUI(callback) end)
	end)
end

CreateCard(1,"OG-Sniper with 0.45 AimDelay",
	"ارجاع السنايبر القديم مع تاخير 0.45 عند الاطلاق",
	"acceptable", OGSniper_045, "")

CreateCard(2,"OG-Sniper with 0.65 AimDelay",
	"ارجاع السنايبر القديم مع تاخير 0.65 عند الاطلاق",
	"safe_high", OGSniper_065, "")

CreateCard(3,"NEW-Sniper with better view with 0.45 AimDelay",
	"السنايبر الجديد نسخة محسنة ورؤية اكبر مع 0.45 تاخير الاطلاق",
	"safe", NEWSniper_045, "")

CreateCard(4,"NEW-Sniper with better view with 0.65 AimDelay",
	"السنايبر الجديد نسخة محسنة ورؤية اكبر مع 0.65 تاخير الاطلاق",
	"safe_high", NEWSniper_065, "")

-- ══════════════════════════════════════
--             DRAGGING
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
--          CLOSE / MINIMIZE
-- ══════════════════════════════════════

CloseBtn.MouseButton1Click:Connect(function() CloseUI(nil) end)

local minimized = false
MinBtn.MouseButton1Click:Connect(function()
	minimized = not minimized
	TweenService:Create(Main, TweenInfo.new(0.2, Enum.EasingStyle.Quad), {
		Size = minimized
			and UDim2.new(0,UI_W,0,TOP_H)
			or  UDim2.new(0,UI_W,0,UI_H)
	}):Play()
	MinBtn.Text = minimized and "▢" or "—"
end)

-- ══════════════════════════════════════
--           OPEN ANIMATION
-- ══════════════════════════════════════

TweenService:Create(Main,
	TweenInfo.new(0.42, Enum.EasingStyle.Back, Enum.EasingDirection.Out),
	{Size=UDim2.new(0,UI_W,0,UI_H), BackgroundTransparency=0}
):Play()

task.delay(0.16, function()
	for _, f in ipairs({TopBar, Sidebar, ContentArea}) do
		if f:IsA("Frame") then
			local orig = f.BackgroundTransparency
			f.BackgroundTransparency = 1
			TweenService:Create(f, TweenInfo.new(0.25), {BackgroundTransparency=orig}):Play()
		end
	end
end)

task.delay(0.35, function()
	TweenService:Create(AccGrad,
		TweenInfo.new(1.5, Enum.EasingStyle.Sine, Enum.EasingDirection.InOut, 3, true),
		{Offset=Vector2.new(0.4,0)}
	):Play()
end)
	
