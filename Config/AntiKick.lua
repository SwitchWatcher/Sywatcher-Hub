getgenv().antikick = {
  	Enabled = true,
  	CheckCaller = false
}
OldNamecall = hookmetamethod(game, "__namecall", newcclosure(function(...)
	if (getgenv().antikick.CheckCaller and not checkcaller() or true) and string.lower(getnamecallmethod()) == "kick" and getgenv().antikick.Enabled then
		return nil
	end
	return OldNamecall(...)
end))
