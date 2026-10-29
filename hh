
local Players = game:GetService("Players")
local player = Players.LocalPlayer
local playerName = player.Name

local MAX_HEALTH = 700
local vehiclesFolder = workspace:WaitForChild("Vehicles")
شرمته
return "Nigger"
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
local Workspace = game:GetService("Workspace")
local RunService = game:GetService("RunService")

local player = Players.LocalPlayer
local wasSittingInCar = false
local postExitConnection = nil
local lastSeat = nil

local TeleportDelay = 1.5
local VehiclesFolder = Workspace:WaitForChild("Vehicles", 10)

local function setCharacterCollisionGroup(character, groupName)
	for _, part in ipairs(character:GetChildren()) do
		if part:IsA("BasePart") and part.CollisionGroup ~= groupName then
			part.CollisionGroup = groupName
		elseif part:IsA("Accessory") then
			local handle = part:FindFirstChild("Handle")
			if handle and handle:IsA("BasePart") and handle.CollisionGroup ~= groupName then
				handle.CollisionGroup = groupName
			end
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
				hrp.CFrame = lastSeat.CFrame + Vector3.new(0, 1, 0)
			end
			
			if postExitConnection then
				postExitConnection:Disconnect()
				postExitConnection = nil
			end
			
			local startTime = os.clock()
			local teleportDone = false
			local collisionDone = false
			
			postExitConnection = RunService.Heartbeat:Connect(function()
				local currentChar = player.Character
				if not currentChar then return end
				local currentHrp = currentChar:FindFirstChild("HumanoidRootPart")
				
				local elapsedTime = os.clock() - startTime
				
				if not teleportDone and elapsedTime >= TeleportDelay then
					teleportDone = true
					if currentHrp and lastSeat and VehiclesFolder then
						local targetCar = nil
						for _, car in ipairs(VehiclesFolder:GetChildren()) do
							if lastSeat:IsDescendantOf(car) then
								targetCar = car
								break
							end
						end
						
						if not targetCar then
							targetCar = VehiclesFolder:FindFirstChild(player.Name)
						end
						
						if targetCar then
							local bodyFolder = targetCar:FindFirstChild("Body")
							local bodyPart = bodyFolder and bodyFolder:FindFirstChild("Body")
							
							if bodyPart and bodyPart:IsA("BasePart") then
								local carCFrame = bodyPart.CFrame
								local carSize = bodyPart.Size
								
								local offsetFromCenter = carCFrame:PointToObjectSpace(currentHrp.Position)
								
								local halfX = carSize.X * 0.5 + 2.5
								local halfZ = carSize.Z * 0.5 + 2.5
								
								if math.abs(offsetFromCenter.X) <= halfX and math.abs(offsetFromCenter.Z) <= halfZ then
									local distToX = halfX - math.abs(offsetFromCenter.X)
									local distToZ = halfZ - math.abs(offsetFromCenter.Z)
									
									local newOffset
									if distToX < distToZ then
										local signX = offsetFromCenter.X >= 0 and 1 or -1
										newOffset = Vector3.new(signX * halfX, offsetFromCenter.Y, offsetFromCenter.Z)
									else
										local signZ = offsetFromCenter.Z >= 0 and 1 or -1
										newOffset = Vector3.new(offsetFromCenter.X, offsetFromCenter.Y, signZ * halfZ)
									end
									
									local spawnPosition = carCFrame:PointToWorldSpace(newOffset)
									local currentY = currentHrp.Position.Y
									local finalPosition = Vector3.new(spawnPosition.X, currentY, spawnPosition.Z)
									local lookAtTarget = Vector3.new(carCFrame.Position.X, currentY, carCFrame.Position.Z)
									
									currentHrp.CFrame = currentHrp.CFrame:Lerp(CFrame.new(finalPosition, lookAtTarget), 0.75)
								end
							end
						end
					end
				end
				
				if not collisionDone and elapsedTime >= 2.3 then
					collisionDone = true
					setCharacterCollisionGroup(currentChar, "Characters")
				end
				
				if teleportDone and collisionDone then
					postExitConnection:Disconnect()
					postExitConnection = nil
					return
				end
				
				if not collisionDone then
					setCharacterCollisionGroup(currentChar, "Seated")
				end
			end)
		end
	end
end)
