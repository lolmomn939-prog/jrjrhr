local Players = game:GetService("Players")
local player = Players.LocalPlayer
local playerName = player.Name

local MAX_HEALTH = 700
local vehiclesFolder = workspace:WaitForChild("Vehicles")

local function applyVehicleProtection(vehicle)
    if not vehicle or vehicle.Name ~= playerName then return end
    local function maintain()
        if vehicle:GetAttribute("IsOn") ~= true then
            vehicle:SetAttribute("IsOn", true)
        end
        if vehicle:GetAttribute("currentHealth") ~= MAX_HEALTH then
            vehicle:SetAttribute("currentHealth", MAX_HEALTH)
        end
    end

    maintain()

    vehicle:GetAttributeChangedSignal("IsOn"):Connect(maintain)
    vehicle:GetAttributeChangedSignal("currentHealth"):Connect(maintain)
end

for _, v in ipairs(vehiclesFolder:GetChildren()) do
    applyVehicleProtection(v)
end

vehiclesFolder.ChildAdded:Connect(function(child)
    task.wait(0.5)
    applyVehicleProtection(child)
end)


    local Players = game:GetService("Players")
local Workspace = game:GetService("Workspace")
local UserInputService = game:GetService("UserInputService")
local RunService = game:GetService("RunService")

local player = Players.LocalPlayer
local VehiclesFolder = Workspace:WaitForChild("Vehicles")

local hasBoostedThisSession = false 
local isBoosting = false          

RunService.Heartbeat:Connect(function()
    local char = player.Character
    if not char then return end
    local hum = char:FindFirstChild("Humanoid")
    if not hum then return end
    
    local myCar = VehiclesFolder:FindFirstChild(player.Name)
    local driveSeat = myCar and myCar:FindFirstChild("DriveSeat")
    
    if driveSeat and hum.SeatPart == driveSeat then
        
    
        if not hasBoostedThisSession and not isBoosting and UserInputService:IsKeyDown(Enum.KeyCode.W) then
            
            hasBoostedThisSession = true
            isBoosting = true
        
            local startTime = os.clock()
            local boostConnection
        
            boostConnection = RunService.Heartbeat:Connect(function()
                if os.clock() - startTime >= 0.7 or hum.SeatPart ~= driveSeat then
                    isBoosting = false
                    boostConnection:Disconnect()
                    return
                end
                driveSeat.AssemblyLinearVelocity = driveSeat.AssemblyLinearVelocity + (driveSeat.CFrame.LookVector * 0.26)
            end)
        end
        
    else
        if hasBoostedThisSession and not isBoosting then
            hasBoostedThisSession = false
        end
    end
end)


local Players = game:GetService("Players")
local RunService = game:GetService("RunService")

local player = Players.LocalPlayer
local wasSittingInCar = false
local postExitConnection = nil
local lastSeat = nil

local function setCharacterCollisionGroup(character, groupName)
	for _, part in ipairs(character:GetDescendants()) do
		if part:IsA("BasePart") then
			pcall(function()
				part.CollisionGroup = groupName
			end)
		end
	end
end

RunService.Heartbeat:Connect(function()
	local char = player.Character
	if not char then return end
	local hum = char:FindFirstChild("Humanoid")
	local hrp = char:FindFirstChild("HumanoidRootPart")
	if not hum or not hrp then return end
	
	local currentSeat = hum.SeatPart
	
	if currentSeat and (currentSeat:IsA("Seat") or currentSeat:IsA("VehicleSeat")) then
		wasSittingInCar = true
		lastSeat = currentSeat
	else
		if wasSittingInCar then
			wasSittingInCar = false
			
			if lastSeat and lastSeat.Parent then
				hrp.CFrame = CFrame.new(lastSeat.Position + Vector3.new(0, 1, 0))
			end
			
			if postExitConnection then
				postExitConnection:Disconnect()
				postExitConnection = nil
			end
			
			local startTime = os.clock()
			
			postExitConnection = RunService.Heartbeat:Connect(function()
				local currentChar = player.Character
				if not currentChar then return end
				
				if os.clock() - startTime >= 2 then
					postExitConnection:Disconnect()
					postExitConnection = nil
					
					setCharacterCollisionGroup(currentChar, "Characters")
					return
				end
				
				setCharacterCollisionGroup(currentChar, "Seated")
			end)
		end
	end
end)
