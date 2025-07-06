for i = 1, 500 do
	local tbl_main = { "collectOrb", "Red Orb", "City" }
	game:GetService("ReplicatedStorage").rEvents.orbEvent:FireServer(unpack(tbl_main))
	
	tbl_main = { "collectOrb", "Yellow Orb", "City" }
	game:GetService("ReplicatedStorage").rEvents.orbEvent:FireServer(unpack(tbl_main))
	
	tbl_main = { "collectOrb", "Gem", "City" }
	game:GetService("ReplicatedStorage").rEvents.orbEvent:FireServer(unpack(tbl_main))
	
	tbl_main = { "collectOrb", "Orange Orb", "City" }
	game:GetService("ReplicatedStorage").rEvents.orbEvent:FireServer(unpack(tbl_main))
	
	tbl_main = { "rebirthRequest" }
	game:GetService("ReplicatedStorage").rEvents.rebirthEvent:FireServer(unpack(tbl_main))
end
