for i, v in pairs(game.Workspace.Hoops:GetChildren()) do
	if v:IsA("BasePart") then
		v.CFrame = game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame
	end
end
