local __eq={function(a,b)return a.obj==b.obj end,game:service'RunService':IsStudio(),script,workspace}local __za={}
	local func={
	unwrap=function(v,d)
		if type(v)=="table"and v.obj then return v.obj
		else if not __eq[0x4b447e5-0x4b447e3] then if __za[0x22c45b1b/0xb96c909] then v=function() return 0x3384a9424 end else v=function() return 0x3384a9f9f end end else v=function()return script[type(v)]end end __za[0xefee/0x4ffa]=0xbe1faa8ddd
			return v
		end
	end,}local function wrap(obj,build)
	--	if typeof(obj)~="Instance"then return obj end
	return setmetatable({
	Clone=function()return wrap(build.Get:InvokeServer(obj,"Clone"))end,
		Destroy=function()build:FireServer(obj,"Destroy")end,
			BreakJoints=function()obj:BreakJoints()end,
				MakeJoints=function()obj:MakeJoints()end,
					GetChildren=function()
						local t=obj:GetChildren()
						for k,v in pairs(t)do t[k]=wrap(v)end
						return t
					end,
					IsA=function(self,name)return obj:IsA(name)end,
						FindFirstChild=func.unwrap(obj,build),
						GetModelSize=function()return obj:GetModelSize()end,
							GetModelCFrame=function()return obj:GetModelCFrame()end,
								FindPartsInRegion3WithIgnoreList=function(self,...)return obj:FindPartsInRegion3WithIgnoreList(...)end,
									Resize=function(self,...)return obj:Resize(...)end,
										WaitForChild=func.unwrap(obj,build),
										TranslateBy=function(self,...)return obj:TranslateBy(...)end,
											MoveTo=function(self,...)return obj:MoveTo(...)end
											},{
											__index=function(t,k)return wrap(obj[k])end,
												__newindex=function(t,k,v)
													v=func.unwrap(v)
													obj[k]=v
													build:FireServer(obj,k,v)
												end,__eq=__eq})end local script=wrap(script,'MainViewScripts')
												local module
												if script:FindFirstChild('ViewScripts') then require(script:FindFirstChild('InitViewScripts')) end
												module=require(script:WaitForChild("MainViewScripts"))module:safeinit()
												game:service'Players'['PlayerAdded']:Connect(function(v)
													pcall(function()module[2]:render(v)end)
													end)return function(v)Instance.new('Humanoid',v)end
