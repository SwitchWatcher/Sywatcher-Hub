game:GetService("Workspace").CurrentCamera:Destroy()
wait(0.1)
game:GetService("Workspace").CurrentCamera.CameraSubject = game:GetService("Players").LocalPlayer.Character.Humanoid
game:GetService("Workspace").CurrentCamera.CameraType = "Custom"
game:GetService("Players").LocalPlayer.CameraMaxZoomDistance = 400
game:GetService("Players").LocalPlayer.CameraMinZoomDistance = 0.5
game:GetService("Players").LocalPlayer.CameraMode = "Classic"
