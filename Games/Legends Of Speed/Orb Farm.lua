for i, v in pairs(game.Workspace.orbFolder.City:GetChildren()) do
	if v.Name ~= "Gem" then
		v.outerOrb.CFrame = game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame
	end
end
