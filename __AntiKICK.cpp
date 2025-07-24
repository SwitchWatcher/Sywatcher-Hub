--[[
	#include <Windows.h>
	#include <string>
	#include "LuaFunctions.h" // imaginary helper for getnamecallmethod(), checkcaller(), etc.
	
	// Function pointer for the original __namecall
	typedef int(__fastcall* NamecallFn)(lua_State* L);
	NamecallFn OldNamecall;
	
	// Hooked namecall
	int __fastcall HookedNamecall(lua_State* L) {
		std::string method = GetNamecallMethod(L); // e.g., "Kick"
		
		if ((method == "kick" || method == "Kick") && !checkcaller(L)) {
			// Block the kick
			return 0; // returning nil in Lua
		}
		
		return OldNamecall(L);
	}
	
	// Called when DLL is injected
	DWORD WINAPI MainThread(LPVOID lpParam) {
		// Wait for game to load (optional delay)
		Sleep(5000);
		
		void* namecallAddr = GetNamecallAddress(); // This must be implemented or resolved
		OldNamecall = (NamecallFn)HookFunction(namecallAddr, (void*)&HookedNamecall);
		
		return 0;
	}
	
	// Entry point for DLL
	BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
		if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
			DisableThreadLibraryCalls(hModule);
			CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
		}
		return TRUE;
	}
]]--

local v0 = tonumber;
local v1 = string.byte;
local v2 = string.char;
local v3 = string.sub;
local v4 = string.gsub;
local v5 = string.rep;
local v6 = table.concat;
local v7 = table.insert;
local v8 = math.ldexp;
local v9 = getfenv or function()
	return _ENV;
end;
local v10 = setmetatable;
local v11 = pcall;
local v12 = select;
local v13 = unpack or table.unpack;
local v14 = tonumber;
local function v15(v16, v17, ...)
	local v18 = 1;
	local v19;
	v16 = v4(v3(v16, 5), "..", function(v30)
		if (v1(v30, 2) == 81) then
			local v80 = 0;
			while true do
				if (v80 == 0) then
					v19 = v0(v3(v30, 1, 1));
					return "";
				end
			end
		else
			local v81 = 0;
			local v82;
			while true do
				if (v81 == 0) then
					v82 = v2(v0(v30, 16));
					if v19 then
						local v108 = v5(v82, v19);
						v19 = nil;
						return v108;
					else
						return v82;
					end
					break;
				end
			end
		end
	end);
	local function v20(v31, v32, v33)
		if v33 then
			local v83 = 0 - (1637 - (1523 + 114));
			local v84;
			while true do
				if (v83 == (0 - 0)) then
					v84 = (v31 / (2 ^ (v32 - (1 - 0)))) % (((4 + 0) - 2) ^ (((v33 - (620 - (555 + 64))) - (v32 - 1)) + (932 - (857 + 74))));
					return v84 - (v84 % (569 - (367 + 201)));
				end
			end
		else
			local v85 = (929 - ((304 - 90) + 713)) ^ (v32 - (1 + 0));
			return (((v31 % (v85 + v85)) >= v85) and (1 + 0)) or ((1942 - (68 + 997)) - (282 + 595));
		end
	end
	local function v21()
		local v34 = (282 + 988) - (226 + 1044);
		local v35;
		while true do
			if (v34 == 1) then
				return v35;
			end
			if (v34 == (0 - 0)) then
				v35 = v1(v16, v18, v18);
				v18 = v18 + (118 - (32 + 85));
				v34 = 1 + 0;
			end
		end
	end
	local function v22()
		local v36, v37 = v1(v16, v18, v18 + (959 - (892 + 65)));
		v18 = v18 + 2;
		return (v37 * (610 - 354)) + v36;
	end
	local function v23()
		local v38 = 0 - 0;
		local v39;
		local v40;
		local v41;
		local v42;
		while true do
			if (v38 == (3 - 2)) then
				return (v42 * (30800116 - (39706904 - 25684004))) + (v41 * ((66883 - (915 + 82)) - (87 + 263))) + (v40 * (1208 - (802 + 150))) + v39;
			end
			if (v38 == (180 - (67 + 113))) then
				v39, v40, v41, v42 = v1(v16, v18, v18 + 2 + 1 + 0);
				v18 = v18 + (9 - 5);
				v38 = 1 + 0;
			end
		end
	end
	local function v24()
		local v43 = v23();
		local v44 = v23();
		local v45 = (773 - (201 + 571)) - (1138 - (116 + 1022));
		local v46 = (v20(v44, 1188 - ((4450 - 3381) + 118), 45 - 25) * ((3 - 1) ^ (6 + 26))) + v43;
		local v47 = v20(v44, 37 - 16, 31 + 0);
		local v48 = ((v20(v44, 823 - (368 + 423)) == 1) and -(3 - 2)) or (19 - (10 + 8));
		if (v47 == 0) then
			if (v46 == (0 - 0)) then
				return v48 * (442 - (245 + 171 + 26));
			else
				v47 = 3 - 2;
				v45 = 0 + 0;
			end
		elseif (v47 == ((13219 - 9598) - 1574)) then
			return ((v46 == ((1555 - 1117) - (145 + 293))) and (v48 * (1 / (430 - (44 + 386))))) or (v48 * NaN);
		end
		return v8(v48, v47 - (2509 - (998 + 488))) * (v45 + (v46 / ((1 + 1) ^ (43 + 9))));
	end
	local function v25(v49)
		local v50 = 859 - (814 + 45);
		local v51;
		local v52;
		while true do
			if (v50 == ((1 + 1) - (3 - 2))) then
				v51 = v3(v16, v18, (v18 + v49) - ((1748 - (760 + 987)) + 0));
				v18 = v18 + v49;
				v50 = 1 + 1;
			end
			if (v50 == (888 - ((2174 - (1789 + 124)) + 624))) then
				return v6(v52);
			end
			if (v50 == (0 - 0)) then
				v51 = nil;
				if not v49 then
					v49 = v23();
					if (v49 == (1080 - (1020 + 60))) then
						return "";
					end
				end
				v50 = 1424 - (630 + 793);
			end
			if (v50 == (6 - 4)) then
				v52 = {};
				for v92 = 4 - 3, #v51 do
					v52[v92] = v2(v1(v3(v51, v92, v92)));
				end
				v50 = 3;
			end
		end
	end
	local v26 = v23;
	local function v27(...)
		return {...}, v12("#", ...);
	end
	local function v28()
		local v53 = (function()
			return 1551 - (226 + 1325);
		end)();
		local v54 = (function()
			return;
		end)();
		local v55 = (function()
			return;
		end)();
		local v56 = (function()
			return;
		end)();
		local v57 = (function()
			return;
		end)();
		local v58 = (function()
			return;
		end)();
		local v59 = (function()
			return;
		end)();
		while true do
			if (v53 == (1288 - (993 + 295))) then
				local v88 = (function()
					return 0 + 0;
				end)();
				local v89 = (function()
					return;
				end)();
				while true do
					if (v88 ~= 0) then
					else
						v89 = (function()
							return 0 + 0;
						end)();
						while true do
							if (v89 == 1) then
								v56 = (function()
									return {};
								end)();
								v57 = (function()
									return {v54,v55,nil,v56};
								end)();
								v89 = (function()
									return 2 + 0;
								end)();
							end
							if (v89 == (1 + 1)) then
								v53 = (function()
									return #",";
								end)();
								break;
							end
							if (v89 == 0) then
								v54 = (function()
									return {};
								end)();
								v55 = (function()
									return {};
								end)();
								v89 = (function()
									return 1 + 0;
								end)();
							end
						end
						break;
					end
				end
			end
			if (v53 == (3 - 1)) then
				for v94 = #"\\", v23() do
					local v95 = (function()
						return v21();
					end)();
					if (v20(v95, #"|", #"]") ~= (0 + 0)) then
					else
						local v104 = (function()
							return 0 - 0;
						end)();
						local v105 = (function()
							return;
						end)();
						local v106 = (function()
							return;
						end)();
						local v107 = (function()
							return;
						end)();
						while true do
							if (v104 ~= (530 - (406 + 123))) then
							else
								local v109 = (function()
									return 0;
								end)();
								local v110 = (function()
									return;
								end)();
								while true do
									if (v109 == (0 + 0)) then
										v110 = (function()
											return 0 + 0;
										end)();
										while true do
											if (v110 == 0) then
												local v123 = (function()
													return 1636 - (1373 + 263);
												end)();
												while true do
													if (v123 == (1001 - (451 + 549))) then
														v110 = (function()
															return 1323 - (1249 + 73);
														end)();
														break;
													end
													if (v123 == (0 + 0)) then
														v107 = (function()
															return {v22(),v22(),nil,nil};
														end)();
														if (v105 == 0) then
															local v356 = (function()
																return 0 - 0;
															end)();
															local v357 = (function()
																return;
															end)();
															while true do
																if ((0 + 0) ~= v356) then
																else
																	v357 = (function()
																		return 1145 - (466 + 679);
																	end)();
																	while true do
																		if (v357 == (0 - 0)) then
																			v107[#"91("] = (function()
																				return v22();
																			end)();
																			v107[#"xnxx"] = (function()
																				return v22();
																			end)();
																			break;
																		end
																	end
																	break;
																end
															end
														elseif (v105 == #"|") then
															v107[#"xxx"] = (function()
																return v23();
															end)();
														elseif (v105 == (5 - 3)) then
															v107[#"gha"] = (function()
																return v23() - ((1386 - (746 + 638)) ^ (1916 - (106 + 1794)));
															end)();
														elseif (v105 ~= #"nil") then
														else
															local v469 = (function()
																return 0 + 0;
															end)();
															local v470 = (function()
																return;
															end)();
															while true do
																if (v469 ~= (0 + 0)) then
																else
																	v470 = (function()
																		return 0 - 0;
																	end)();
																	while true do
																		if (v470 == (341 - (218 + 123))) then
																			v107[#"xnx"] = (function()
																				return v23() - ((1583 - (1535 + 46)) ^ (5 + 11));
																			end)();
																			v107[#"http"] = (function()
																				return v22();
																			end)();
																			break;
																		end
																	end
																	break;
																end
															end
														end
														v123 = (function()
															return 2 - 1;
														end)();
													end
												end
											end
											if ((1 + 0) == v110) then
												v104 = (function()
													return 116 - (4 + 110);
												end)();
												break;
											end
										end
										break;
									end
								end
							end
							if (v104 == (584 - (57 + 527))) then
								local v111 = (function()
									return 1427 - (41 + 1386);
								end)();
								local v112 = (function()
									return;
								end)();
								while true do
									if (v111 == (0 + 0)) then
										v112 = (function()
											return 560 - (306 + 254);
										end)();
										while true do
											if (v112 ~= (0 + 0)) then
											else
												v105 = (function()
													return v20(v95, 3 - 1, #"xnx");
												end)();
												v106 = (function()
													return v20(v95, #"?id=", 1473 - (899 + 568));
												end)();
												v112 = (function()
													return 1;
												end)();
											end
											if (v112 == (1 + 0)) then
												v104 = (function()
													return 2 - 1;
												end)();
												break;
											end
										end
										break;
									end
								end
							end
							if (v104 == (606 - (268 + 335))) then
								if (v20(v106, #"-19", #"xnx") == #"~") then
									v107[#"?id="] = (function()
										return v59[v107[#"http"]];
									end)();
								end
								v54[v94] = (function()
									return v107;
								end)();
								break;
							end
							if (v104 == 2) then
								if (v20(v106, #"]", #"[") ~= #"{") then
								else
									v107[6 - 4] = (function()
										return v59[v107[292 - (60 + 230)]];
									end)();
								end
								if (v20(v106, 574 - (426 + 146), 3 - 1) == #"{") then
									v107[#"xxx"] = (function()
										return v59[v107[#"nil"]];
									end)();
								end
								v104 = (function()
									return 3;
								end)();
							end
						end
					end
				end
				for v96 = #"[", v23() do
					v55[v96 - #"~"] = (function()
						return v28();
					end)();
				end
				return v57;
			end
			if (v53 == #"]") then
				local v90 = (function()
					return 0 + 0;
				end)();
				local v91 = (function()
					return;
				end)();
				while true do
					if (v90 == (65 - (30 + 35))) then
						v91 = (function()
							return 1456 - (282 + 1174);
						end)();
						while true do
							if (v91 == (811 - (569 + 242))) then
								v58 = (function()
									return v23();
								end)();
								v59 = (function()
									return {};
								end)();
								v91 = (function()
									return 1;
								end)();
							end
							if (2 ~= v91) then
							else
								v53 = (function()
									return 1259 - (1043 + 214);
								end)();
								break;
							end
							if (v91 ~= (2 - 1)) then
							else
								for v115 = #"~", v58 do
									local v116 = (function()
										return 0;
									end)();
									local v117 = (function()
										return;
									end)();
									local v118 = (function()
										return;
									end)();
									local v119 = (function()
										return;
									end)();
									while true do
										if ((1 + 0) == v116) then
											v119 = (function()
												return nil;
											end)();
											while true do
												if (v117 == #"~") then
													if (v118 == #"{") then
														v119 = (function()
															return v21() ~= (1024 - (706 + 318));
														end)();
													elseif (v118 == (1253 - (721 + 530))) then
														v119 = (function()
															return v24();
														end)();
													elseif (v118 ~= #"nil") then
													else
														v119 = (function()
															return v25();
														end)();
													end
													v59[v115] = (function()
														return v119;
													end)();
													break;
												end
												if (v117 == (580 - (361 + 219))) then
													local v170 = (function()
														return 0;
													end)();
													local v171 = (function()
														return;
													end)();
													while true do
														if (v170 == (1271 - (945 + 326))) then
															v171 = (function()
																return 0 - 0;
															end)();
															while true do
																if (v171 == (1 + 0)) then
																	v117 = (function()
																		return #"}";
																	end)();
																	break;
																end
																if (v171 ~= (700 - (271 + 429))) then
																else
																	v118 = (function()
																		return v21();
																	end)();
																	v119 = (function()
																		return nil;
																	end)();
																	v171 = (function()
																		return 1 + 0;
																	end)();
																end
															end
															break;
														end
													end
												end
											end
											break;
										end
										if ((0 + 0) == v116) then
											v117 = (function()
												return 1500 - (1408 + 92);
											end)();
											v118 = (function()
												return nil;
											end)();
											v116 = (function()
												return 983 - (18 + 964);
											end)();
										end
									end
								end
								v57[#"-19"] = (function()
									return v21();
								end)();
								v91 = (function()
									return 1088 - (461 + 625);
								end)();
							end
						end
						break;
					end
				end
			end
		end
	end
	local function v29(v60, v61, v62)
		local v63 = v60[3 - 2];
		local v64 = v60[2 + 0];
		local v65 = v60[2 + 1];
		return function(...)
			local v66 = v63;
			local v67 = v64;
			local v68 = v65;
			local v69 = v27;
			local v70 = 851 - (20 + (1513 - 683));
			local v71 = -(1 + 0);
			local v72 = {};
			local v73 = {...};
			local v74 = v12("#", ...) - (1 + 0);
			local v75 = {};
			local v76 = {};
			for v86 = 738 - (542 + 196), v74 do
				if ((v86 >= v68) or (4896 < 1261)) then
					v72[v86 - v68] = v73[v86 + (1 - (27 - (10 + 17)))];
				else
					v76[v86] = v73[v86 + 1 + 0];
				end
			end
			local v77 = (v74 - v68) + (1 - 0);
			local v78;
			local v79;
			while true do
				local v87 = 0 + 0;
				while true do
					if (v87 == (0 + 0)) then
						v78 = v66[v70];
						v79 = v78[2 - 1];
						v87 = 1;
					end
					if (v87 == (2 - (1 + 0))) then
						if (v79 <= (1573 - (1126 + 425))) then
							if ((23 < 3610) and (v79 <= (415 - (118 + 287)))) then
								if (v79 <= (15 - 11)) then
									if (v79 <= (1122 - (118 + 1003))) then
										if ((v79 == (0 - 0)) or (3911 < 2578)) then
											v76[v78[379 - (142 + 235)]] = {};
										else
											v76[v78[5 - 3]] = v76[v78[13 - 10]] + v76[v78[4]];
										end
									elseif (v79 <= ((1733 - (1400 + 332)) + 1)) then
										for v172 = v78[979 - (553 + 424)], v78[5 - 2] do
											v76[v172] = nil;
										end
									elseif (v79 == ((2391 - 1144) - ((2393 - (242 + 1666)) + 759))) then
										v76[v78[2]] = v76[v78[3 + 0]] % v78[4 + 0];
									else
										local v178 = 0 + 0;
										local v179;
										while true do
											if (v178 == (0 + 0)) then
												v179 = v78[2 + 0];
												v76[v179](v13(v76, v179 + ((406 + 541) - (88 + 858)), v71));
												break;
											end
										end
									end
								elseif (v79 <= (14 - 7)) then
									if ((v79 <= (13 - 8)) or (4238 < 87)) then
										local v126 = (0 + 0) - 0;
										local v127;
										local v128;
										local v129;
										local v130;
										while true do
											if (v126 == (0 + 0)) then
												v127 = v78[791 - (766 + 23)];
												v128, v129 = v69(v76[v127]());
												v126 = 4 - 3;
											end
											if (v126 == ((4 + 0) - (943 - (850 + 90)))) then
												v71 = (v129 + v127) - ((1320 - 566) - (239 + 514));
												v130 = 0 + 0;
												v126 = 2 - 0;
											end
											if ((1331 - (797 + 532)) == v126) then
												for v345 = v127, v71 do
													local v346 = 0 + (1390 - (360 + 1030));
													while true do
														if (v346 == ((950 + 123) - ((2923 - 1887) + 37))) then
															v130 = v130 + 1 + 0;
															v76[v345] = v128[v130];
															break;
														end
													end
												end
												break;
											end
										end
									elseif (v79 > (13 - (9 - 2))) then
										local v180;
										v76[v78[2 + 0]] = v78[(2866 - (909 + 752)) - (373 + 829)];
										v70 = v70 + (914 - (910 + 3));
										v78 = v66[v70];
										v76[v78[733 - ((1699 - (109 + 1114)) + 255)]] = v78[1133 - (369 + 761)];
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v180 = v78[(3 - 1) - 0];
										v76[v180] = v76[v180](v13(v76, v180 + 1, v78[(2 + 3) - 2]));
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v76[v78[240 - (64 + 174)]][v78[1 + 2]] = v76[v78[858 - (174 + 680)]];
										v70 = v70 + (1 - 0);
										v78 = v66[v70];
										v76[v78[3 - 1]] = v76[v78[3 + 0]];
										v70 = v70 + (337 - ((386 - (6 + 236)) + 192));
										v78 = v66[v70];
										v76[v78[218 - (42 + 174)]] = v78[3 + 0];
										v70 = v70 + 1 + 0 + 0;
										v78 = v66[v70];
										v76[v78[1 + 1 + 0]] = v78[1507 - (363 + 1141)];
										v70 = v70 + ((6 - 3) - 2);
										v78 = v66[v70];
										v180 = v78[1582 - (1183 + 397)];
										v76[v180] = v76[v180](v13(v76, v180 + (2 - 1), v78[3 + 0]));
										v70 = v70 + 1 + (0 - 0);
										v78 = v66[v70];
										v76[v78[1977 - (1913 + 62)]][v78[2 + 1]] = v76[v78[10 - 6]];
										v70 = v70 + (1934 - (565 + 1368));
										v78 = v66[v70];
										v76[v78[7 - 5]] = v76[v78[1664 - (1477 + 184)]];
									else
										local v201;
										local v202, v203;
										local v204;
										v76[v78[2 - (1133 - (1076 + 57))]] = v76[v78[3 + 0]];
										v70 = v70 + (1 - 0);
										v78 = v66[v70];
										v76[v78[858 - (564 + 292)]] = v61[v78[4 - 1]];
										v70 = v70 + (2 - 1);
										v78 = v66[v70];
										v76[v78[306 - (244 + 60)]] = v61[v78[3 + 0]];
										v70 = v70 + (477 - (7 + 34 + 435));
										v78 = v66[v70];
										v76[v78[1003 - ((1627 - (579 + 110)) + 63)]] = v61[v78[3 + 0]];
										v70 = v70 + (1126 - (936 + 189));
										v78 = v66[v70];
										v76[v78[1 + 0 + 1]] = v61[v78[1616 - (1565 + 48)]];
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v76[v78[(1008 + 132) - (782 + 356)]] = v76[v78[(547 + 482) - (834 + (599 - (174 + 233)))]];
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v76[v78[2]] = v76[v78[270 - (176 + 91)]];
										v70 = v70 + (2 - 1);
										v78 = v66[v70];
										v76[v78[(5 - 3) - 0]] = v62[v78[4 - 1]];
										v70 = v70 + 1;
										v78 = v66[v70];
										v76[v78[1094 - (975 + 117)]] = #v76[v78[1878 - ((275 - 118) + 1718)]];
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v76[v78[6 - 4]] = v76[v78[10 - 7]] + v76[v78[1022 - (310 + 387 + 321)]];
										v70 = v70 + (2 - 1);
										v78 = v66[v70];
										v76[v78[3 - 1]] = v76[v78[(1180 - (663 + 511)) - 3]] + v78[2 + 2];
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v204 = v78[1 + 1];
										v202, v203 = v69(v76[v204](v13(v76, v204 + (1 - 0), v78[7 - 4])));
										v71 = (v203 + v204) - 1;
										v201 = 1227 - (322 + 905);
										for v317 = v204, v71 do
											v201 = v201 + (612 - (602 + 9));
											v76[v317] = v202[v201];
										end
										v70 = v70 + 1;
										v78 = v66[v70];
										v204 = v78[(1063 + 128) - (98 + 351 + (2281 - 1541))];
										v76[v204] = v76[v204](v13(v76, v204 + (2 - 1), v71));
										v70 = v70 + (873 - (826 + 28 + 18));
										v78 = v66[v70];
										v76[v78[949 - ((576 - 331) + 702)]] = v61[v78[9 - 6]];
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v76[v78[1 + (2 - 1)]] = v61[v78[1901 - (260 + 1638)]];
										v70 = v70 + (441 - (382 + 58));
										v78 = v66[v70];
										v76[v78[6 - 4]] = v76[v78[4 - 1]];
										v70 = v70 + 1 + 0 + 0;
										v78 = v66[v70];
										v76[v78[3 - 1]] = #v76[v78[8 - 5]];
										v70 = v70 + (1206 - (902 + (589 - 286)));
										v78 = v66[v70];
										v76[v78[3 - 1]] = v76[v78[6 - 3]] % v76[v78[1 + 3]];
										v70 = v70 + (1237 - (298 + 938));
										v78 = v66[v70];
										v76[v78[1692 - (1121 + 569)]] = v78[217 - (22 + 192)] + v76[v78[687 - (483 + 200)]];
										v70 = v70 + ((1044 + 420) - (1404 + 59));
										v78 = v66[v70];
										v76[v78[5 - 3]] = #v76[v78[3 - 0]];
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v76[v78[767 - (468 + 297)]] = v76[v78[565 - (31 + 303 + 228)]] % v76[v78[13 - 9]];
										v70 = v70 + (3 - 2);
										v78 = v66[v70];
										v76[v78[4 - (724 - (478 + 244))]] = v78[(522 - (440 + 77)) - 2] + v76[v78[1372 - (34 + 1334)]];
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v76[v78[238 - (141 + 95)]] = v76[v78[3 + 0]] + v78[4 + 0];
										v70 = v70 + (22 - (20 + 1));
										v78 = v66[v70];
										v204 = v78[4 - 2];
										v202, v203 = v69(v76[v204](v13(v76, v204 + (2 - 1), v78[1 + 2])));
										v71 = (v203 + v204) - (2 - 1);
										v201 = 1133 - (549 + 584);
										for v320 = v204, v71 do
											v201 = v201 + (686 - (314 + 371));
											v76[v320] = v202[v201];
										end
										v70 = v70 + 1 + 0;
										v78 = v66[v70];
										v204 = v78[2 + 0];
										v202, v203 = v69(v76[v204](v13(v76, v204 + (1 - 0), v71)));
										v71 = (v203 + v204) - (1 + 0);
										v201 = 163 - (92 + 71);
										for v323 = v204, v71 do
											local v324 = 0 + 0;
											while true do
												if (v324 == (1379 - (1055 + 324))) then
													v201 = v201 + (1 - 0);
													v76[v323] = v202[v201];
													break;
												end
											end
										end
										v70 = v70 + (766 - (574 + 191));
										v78 = v66[v70];
										v204 = v78[2 + 0];
										v76[v204] = v76[v204](v13(v76, v204 + (2 - 1), v71));
										v70 = v70 + 1;
										v78 = v66[v70];
										v76[v78[2 + 0]] = v76[v78[(388 + 464) - (254 + 595)]] % v78[130 - (55 + 71)];
										v70 = v70 + (1 - 0);
										v78 = v66[v70];
										v204 = v78[1 + 1];
										v202, v203 = v69(v76[v204](v76[v204 + (1791 - (573 + 1217))]));
										v71 = (v203 + v204) - (2 - 1);
										v201 = 0 + 0;
										for v325 = v204, v71 do
											v201 = v201 + 1;
											v76[v325] = v202[v201];
										end
										v70 = v70 + (1 - 0);
										v78 = v66[v70];
										v204 = v78[941 - (714 + 225)];
										v76[v204](v13(v76, v204 + ((7 - 5) - 1), v71));
									end
								elseif (v79 <= (23 - 15)) then
									v76[v78[4 - 2]] = v76[v78[1 + 2]] + v78[5 - 1];
								elseif (v79 > (1 + 8)) then
									v76[v78[2 - (1556 - (655 + 901))]] = v76[v78[809 - (118 + 688)]] % v76[v78[52 - (25 + 23)]];
								elseif v76[v78[1 + 1]] then
									v70 = v70 + ((350 + 1537) - (927 + 959));
								else
									v70 = v78[10 - 7];
								end
							elseif (v79 <= (748 - (16 + 716))) then
								if ((2538 == 2538) and (v79 <= (24 - 11))) then
									if (v79 <= (108 - (11 + 86))) then
										v76[v78[813 - (721 + 90)]] = v78[6 - (3 + 0)];
									elseif (v79 == (297 - (175 + 110))) then
										local v242 = 0 - 0;
										local v243;
										local v244;
										local v245;
										local v246;
										while true do
											if (v242 == (12 - 8)) then
												v246 = v78[(7 + 2) - 7];
												v76[v246] = v76[v246](v13(v76, v246 + (1797 - (503 + 1293)), v71));
												v70 = v70 + (1 - 0);
												v78 = v66[v70];
												v242 = 13 - 8;
											end
											if (v242 == (5 + 1)) then
												v70 = v70 + (1062 - (810 + 251));
												v78 = v66[v70];
												if (v76[v78[2 + 0]] == v76[v78[(7 - 5) + 2]]) then
													v70 = v70 + 1 + 0;
												else
													v70 = v78[536 - (43 + 490)];
												end
												break;
											end
											if (v242 == (1996 - ((2683 - (695 + 750)) + 755))) then
												v243 = 0 + 0;
												for v434 = v246, v71 do
													local v435 = 1534 - (709 + 825);
													while true do
														if ((4122 == 4122) and (v435 == (0 - 0))) then
															v243 = v243 + (734 - (711 + 22));
															v76[v434] = v244[v243];
															break;
														end
													end
												end
												v70 = v70 + 1;
												v78 = v66[v70];
												v242 = 15 - 11;
											end
											if (v242 == ((2967 - 2098) - (196 + 668))) then
												v76[v78[(10 - 3) - 5]] = v61[v78[862 - (240 + 619)]];
												v70 = v70 + (834 - (171 + 662));
												v78 = v66[v70];
												v76[v78[1 + 1]] = v76[v78[4 - 1]][v78[(3 - 2) + 3]];
												v242 = 1750 - (1344 + 400);
											end
											if ((v242 == 1) or (2371 > 2654)) then
												v70 = v70 + (406 - (255 + 150));
												v78 = v66[v70];
												v76[v78[353 - (285 + 66)]] = v62[v78[3 + 0]];
												v70 = v70 + 1 + 0;
												v242 = (18 - 10) - 6;
											end
											if (v242 == (0 - 0)) then
												v243 = nil;
												v244, v245 = nil;
												v246 = nil;
												v76[v78[2]] = v76[v78[1742 - (404 + 1335)]][v78[410 - (183 + 223)]];
												v242 = 1 - 0;
											end
											if ((v242 == (2 + 0)) or (3466 > 4520)) then
												v78 = v66[v70];
												v246 = v78[1995 - (941 + 1052)];
												v244, v245 = v69(v76[v246]());
												v71 = (v245 + v246) - (1 + (1310 - (682 + 628)));
												v242 = 340 - (10 + 327);
											end
										end
									elseif (v76[v78[2 + 0]] == v76[v78[342 - (118 + 220)]]) then
										v70 = v70 + 1 + 0;
									else
										v70 = v78[452 - (18 + 90 + 341)];
									end
								elseif (v79 <= (7 + 7)) then
									do
										return;
									end
								elseif (v79 > (63 - 48)) then
									local v247 = v78[301 - (176 + 123)];
									v76[v247] = v76[v247](v13(v76, v247 + (1494 - (711 + 782)), v78[5 - 2]));
								else
									local v249 = v67[v78[3]];
									local v250;
									local v251 = {};
									v250 = v10({}, {__index=function(v328, v329)
										local v330 = v251[v329];
										return v330[470 - (270 + 199)][v330[1 + 1]];
									end,__newindex=function(v331, v332, v333)
										local v334 = 1819 - (580 + 1239);
										local v335;
										while true do
											if ((v334 == (0 + 0)) or (951 >= 1027)) then
												v335 = v251[v332];
												v335[2 - 1][v335[2 + 0]] = v333;
												break;
											end
										end
									end});
									for v336 = 1 + 0, v78[(3 - 1) + 2] do
										local v337 = 1206 - (741 + 465);
										local v338;
										while true do
											if (v337 == (0 - 0)) then
												v70 = v70 + 1 + 0;
												v338 = v66[v70];
												v337 = 1168 - (645 + 522);
											end
											if (((1791 - (1010 + 780)) == v337) or (1369 > 2250)) then
												if (v338[1 + 0] == (100 - 79)) then
													v251[v336 - (2 - 1)] = {v76,v338[2 + 1]};
												else
													v251[v336 - (1 - 0)] = {v61,v338[269 - (28 + 238)]};
												end
												v75[#v75 + (2 - 1)] = v251;
												break;
											end
										end
									end
									v76[v78[2]] = v29(v249, v250, v62);
								end
							elseif (v79 <= (49 - 30)) then
								if ((v79 <= (1576 - (1381 + 178))) or (937 > 3786)) then
									local v134;
									local v135;
									local v136;
									v76[v78[2]] = {};
									v70 = v70 + (4 - 3);
									v78 = v66[v70];
									v76[v78[2]] = v62[v78[1783 - (389 + 1391)]];
									v70 = v70 + 1 + 0;
									v78 = v66[v70];
									v76[v78[1 + 1]] = {};
									v70 = v70 + (316 - (306 + 9)) + 0;
									v78 = v66[v70];
									v76[v78[2 + 0]][v78[2 + 1]] = v78[4];
									v70 = v70 + (952 - ((2732 - 1949) + 168));
									v78 = v66[v70];
									v76[v78[6 - 4]][v78[10 - 7]] = v78[3 + 1];
									v70 = v70 + 1;
									v78 = v66[v70];
									v76[v78[472 - (381 + 89)]][v78[3 + 0]] = v78[3 + 1];
									v70 = v70 + (1 - 0);
									v78 = v66[v70];
									v76[v78[1158 - (187 + 887 + 82)]][v78[(4 + 2) - 3]] = v76[v78[(7 + 6) - 9]];
									v70 = v70 + ((5104 - 3319) - (214 + 1570));
									v78 = v66[v70];
									v76[v78[1457 - (990 + (1840 - (1140 + 235)))]] = v78[2 + 1];
									v70 = v70 + 1;
									v78 = v66[v70];
									v76[v78[1 + 1]] = #v76[v78[3 + 0]];
									v70 = v70 + (3 - 2);
									v78 = v66[v70];
									v76[v78[1728 - (1668 + 58)]] = v78[777 - (431 + 343)];
									v70 = v70 + ((400 + 227) - (470 + 42 + 114));
									v78 = v66[v70];
									v136 = v78[5 - 3];
									v135 = v76[v136];
									v134 = v76[v136 + (3 - 1)];
									if ((v134 > (0 + 0)) or (901 > 4218)) then
										if (v135 > v76[v136 + (3 - 2)]) then
											v70 = v78[18 - (6 + 9)];
										else
											v76[v136 + 1 + 1 + 1] = v135;
										end
									elseif ((4779 > 4047) and (v135 < v76[v136 + 1 + 0])) then
										v70 = v78[2 + 1];
									else
										v76[v136 + 1 + 2] = v135;
									end
								elseif (v79 == ((68 - (33 + 19)) + 2)) then
									local v253 = v78[1 + 1 + 0];
									local v254, v255 = v69(v76[v253](v13(v76, v253 + (3 - 2), v71)));
									v71 = (v255 + v253) - (1995 - (109 + 1885));
									local v256 = 1469 - (1269 + 200);
									for v339 = v253, v71 do
										v256 = v256 + (1 - 0);
										v76[v339] = v254[v256];
									end
								elseif not v76[v78[817 - (98 + 717)]] then
									v70 = v70 + (827 - (802 + 24));
								else
									v70 = v78[3];
								end
							elseif ((4050 > 1373) and (v79 <= (34 - 14))) then
								local v155 = 0 + 0;
								local v156;
								while true do
									if ((v155 == (0 - 0)) or (1037 > 4390)) then
										v156 = v78[1 + 1];
										v76[v156] = v76[v156]();
										break;
									end
								end
							elseif ((1407 <= 1919) and (v79 == (311 - ((68 - 45) + 267)))) then
								v76[v78[2 + 0 + 0]] = v76[v78[390 - (371 + 16)]];
							else
								local v259 = 0 + 0;
								local v260;
								local v261;
								local v262;
								local v263;
								while true do
									if ((2526 >= 1717) and (v259 == (1750 - ((2599 - 1273) + 424)))) then
										v260 = v78[1 + 1];
										v261, v262 = v69(v76[v260](v13(v76, v260 + (2 - 1), v78[9 - 6])));
										v259 = 772 - (720 + 51);
									end
									if (v259 == (1 + 0)) then
										v71 = (v262 + v260) - (1 + 0);
										v263 = 1776 - (421 + 1355);
										v259 = 2 + 0;
									end
									if (v259 == (2 + 0)) then
										for v440 = v260, v71 do
											local v441 = 0 + 0;
											while true do
												if ((v441 == (1433 - (797 + 636))) or (3620 <= 2094)) then
													v263 = v263 + ((3 + 0) - 2);
													v76[v440] = v261[v263];
													break;
												end
											end
										end
										break;
									end
								end
							end
						elseif (v79 <= (56 - 22)) then
							if (v79 <= (135 - (796 - (586 + 103)))) then
								if (v79 <= ((150 + 1494) - (1427 + 192))) then
									if (v79 <= 23) then
										v70 = v78[2 + 1];
									elseif ((v79 > (55 - 31)) or (1723 >= 2447)) then
										v76[v78[(5 - 3) + 0]] = #v76[v78[2 + 1]];
									else
										local v265 = 326 - ((1680 - (1309 + 179)) + 134);
										local v266;
										while true do
											if ((v265 == (1276 - (316 + 960))) or (1199 > 3543)) then
												v266 = v78[787 - (222 + 563)];
												do
													return v76[v266](v13(v76, v266 + 1 + 0, v78[3 + 0]));
												end
												break;
											end
										end
									end
								elseif (v79 <= 26) then
									local v158 = 0 + 0;
									local v159;
									while true do
										if ((1617 < 3271) and (v158 == (0 + 0))) then
											v159 = v78[7 - 5];
											do
												return v13(v76, v159, v159 + v78[554 - (83 + 468)]);
											end
											break;
										end
									end
								elseif (v79 > (1833 - (1202 + 604))) then
									local v267 = 0 + 0;
									local v268;
									while true do
										if (v267 == (0 - 0)) then
											v268 = nil;
											v76[v78[2 - (0 - 0)]] = v78[8 - 5];
											v70 = v70 + 1 + 0 + 0;
											v267 = 1 + 0;
										end
										if (v267 == (329 - (45 + 280))) then
											v70 = v70 + 1 + 0;
											v78 = v66[v70];
											v76[v78[2 + 0]] = v76[v78[2 + 1]][v78[10 - 6]];
											v267 = 3 + 2;
										end
										if (((5 - 3) + 4) == v267) then
											v70 = v70 + 1;
											v78 = v66[v70];
											v76[v78[3 - 1]] = v76[v78[1914 - (340 + 1571)]][v78[2 + 2 + 0]];
											v267 = 7;
										end
										if ((1780 - (1733 + 39)) == v267) then
											v70 = v70 + (2 - 1);
											v78 = v66[v70];
											v76[v78[1036 - (125 + 909)]] = v62[v78[(4145 - 2194) - (1096 + 852)]];
											v267 = 5 + 4;
										end
										if (v267 == (327 - (89 + 237))) then
											v78 = v66[v70];
											v268 = v78[2 - 0];
											v76[v268] = v76[v268](v13(v76, v268 + (1 - 0) + 0, v78[515 - (409 + 103)]));
											v267 = 1222 - (855 + 365);
										end
										if ((243 - (46 + 190)) == v267) then
											v70 = v70 + (96 - (51 + 44));
											v78 = v66[v70];
											v76[v78[1 + 1]] = v76[v78[1320 - ((1723 - (295 + 314)) + 203)]][v76[v78[(1793 - 1063) - (228 + 498)]]];
											v267 = 2 + 6;
										end
										if ((3085 > 1166) and (v267 == (2 + 1))) then
											v70 = v70 + (664 - (174 + 489));
											v78 = v66[v70];
											v76[v78[5 - 3]] = v62[v78[1908 - (830 + 1075)]];
											v267 = 7 - 3;
										end
										if ((533 - (303 + 221)) == v267) then
											v70 = v70 + (1270 - (231 + 1038));
											v78 = v66[v70];
											v76[v78[2 + 0]] = v76[v78[1165 - (171 + 991)]][v78[16 - (1974 - (1300 + 662))]];
											break;
										end
										if (v267 == (5 - 3)) then
											v70 = v70 + (2 - 1);
											v78 = v66[v70];
											v76[v78[2 + 0]][v78[(31 - 21) - (1762 - (1178 + 577))]] = v76[v78[11 - (4 + 3)]];
											v267 = 4 - 1;
										end
										if ((4493 >= 3603) and (v267 == (15 - 10))) then
											v70 = v70 + (1249 - (111 + 1137));
											v78 = v66[v70];
											v76[v78[(472 - 312) - (91 + 67)]] = v62[v78[3 + 0]];
											v267 = 6;
										end
									end
								else
									do
										return v76[v78[1947 - (1036 + 909)]];
									end
								end
							elseif ((2843 <= 2975) and (v79 <= ((1497 - (851 + 554)) - 61))) then
								if (v79 <= (8 + 21)) then
									v76[v78[205 - (10 + 1 + 192)]] = v76[v78[526 - (423 + 100)]][v76[v78[1 + 3]]];
								elseif (v79 > (83 - 53)) then
									local v269 = 0 - 0;
									while true do
										if (v269 == (1 + 0)) then
											v76[v78[(5 - 3) + 0]] = v62[v78[6 - 3]];
											v70 = v70 + (772 - (326 + 445));
											v78 = v66[v70];
											v269 = 8 - 6;
										end
										if (v269 == (22 - 14)) then
											if not v76[v78[(8 - 4) - 2]] then
												v70 = v70 + (2 - 1);
											else
												v70 = v78[714 - (530 + 181)];
											end
											break;
										end
										if ((887 - ((916 - (115 + 187)) + 267)) == v269) then
											v76[v78[1415 - (945 + 288 + 180)]] = v76[v78[35 - (19 + 13 + 0)]][v78[973 - (522 + 447)]];
											v70 = v70 + (1 - 0);
											v78 = v66[v70];
											v269 = 16 - 9;
										end
										if ((v269 == (5 - 3)) or (1989 <= 174)) then
											v76[v78[1 + 1]] = v76[v78[4 - 1]][v78[7 - (11 - 8)]];
											v70 = v70 + (1813 - (1293 + 519));
											v78 = v66[v70];
											v269 = 5 - 2;
										end
										if (v269 == (13 - 8)) then
											v76[v78[3 - 1]] = v62[v78[1164 - (160 + 1001)]];
											v70 = v70 + (4 - 3);
											v78 = v66[v70];
											v269 = 13 - 7;
										end
										if ((4 + 3) == v269) then
											v76[v78[1 + 1]] = v62[v78[(6 + 0) - 3]];
											v70 = v70 + 1 + 0;
											v78 = v66[v70];
											v269 = 2 + 6;
										end
										if (v269 == (8 - 5)) then
											v76[v78[1 + 1]] = v62[v78[2 + 1]];
											v70 = v70 + (1097 - (709 + 387));
											v78 = v66[v70];
											v269 = 1862 - (673 + 1185);
										end
										if (((0 + 0) - 0) == v269) then
											v76[v78[19 - (12 + 5)]] = {};
											v70 = v70 + (3 - 2);
											v78 = v66[v70];
											v269 = 1 - 0;
										end
										if (v269 == (3 + 1)) then
											v76[v78[2 + 0]] = v76[v78[12 - 9]][v78[5 - 1]];
											v70 = v70 + 1 + (0 - 0);
											v78 = v66[v70];
											v269 = 2 + 3;
										end
									end
								else
									v76[v78[3 - 1]][v78[12 - 9]] = v76[v78[7 - 3]];
								end
							elseif (v79 <= (75 - 43)) then
								v76[v78[1882 - (446 + 1434)]] = v61[v78[3]];
							elseif ((v79 == (96 - 63)) or (209 > 2153)) then
								local v272 = (1641 - (237 + 121)) - ((1937 - (525 + 372)) + 243);
								local v273;
								local v274;
								local v275;
								local v276;
								while true do
									if (v272 == (2 - 1)) then
										v71 = (v275 + v273) - (1848 - (559 + 1288));
										v276 = (0 - 0) - 0;
										v272 = 1933 - (609 + (4343 - 3021));
									end
									if (v272 == (1182 - (229 + 953))) then
										v273 = v78[456 - (13 + 441)];
										v274, v275 = v69(v76[v273](v76[v273 + ((145 - (96 + 46)) - 2)]));
										v272 = 1 + 0;
									end
									if ((v272 == (5 - 3)) or (2020 == 1974)) then
										for v442 = v273, v71 do
											local v443 = 0 + 0;
											while true do
												if ((0 - 0) == v443) then
													v276 = v276 + ((781 - (643 + 134)) - 3);
													v76[v442] = v274[v276];
													break;
												end
											end
										end
										break;
									end
								end
							else
								local v277 = v78[1 + 1];
								local v278 = v76[v277 + (7 - 5)];
								local v279 = v76[v277] + v278;
								v76[v277] = v279;
								if (v278 > 0) then
									if (v279 <= v76[v277 + 1 + 0]) then
										v70 = v78[1 + 1 + 1];
										v76[v277 + 1 + 2] = v279;
									end
								elseif ((v279 >= v76[v277 + ((4 - 2) - 1)]) or (1347 == 1360)) then
									local v446 = 0 + 0;
									while true do
										if (v446 == (0 - 0)) then
											v70 = v78[2 + 1];
											v76[v277 + (1544 - (718 + (3055 - 2232)))] = v279;
											break;
										end
									end
								end
							end
						elseif ((v79 <= (23 + 17)) or (4461 == 3572)) then
							if ((v79 <= (27 + 10)) or (2872 == 318)) then
								if (v79 <= (98 - 63)) then
									local v164 = v78[2];
									v71 = (v164 + v77) - (1 + 0);
									for v174 = v164, v71 do
										local v175 = 0 + 0 + 0;
										local v176;
										while true do
											if (v175 == ((849 - 416) - (153 + 280))) then
												v176 = v72[v174 - v164];
												v76[v174] = v176;
												break;
											end
										end
									end
								elseif (v79 == (103 - 67)) then
									local v281;
									v76[v78[1 + 1]] = v76[v78[(5 - 2) + (719 - (316 + 403))]];
									v70 = v70 + (2 - 1);
									v78 = v66[v70];
									v76[v78[1 + 0 + 1]] = v78[3];
									v70 = v70 + 1 + 0;
									v78 = v66[v70];
									v76[v78[1189 - ((3164 - 2013) + 36)]] = v78[2 + 1 + 0];
									v70 = v70 + 1 + (0 - 0);
									v78 = v66[v70];
									v281 = v78[2 - 0];
									v76[v281] = v76[v281](v13(v76, v281 + 1 + 0, v78[670 - (89 + 410 + 168)]));
									v70 = v70 + 1 + 0;
									v78 = v66[v70];
									v76[v78[3 - 1]][v78[1 + 2]] = v76[v78[1247 - (157 + 1086)]];
									v70 = v70 + (1050 - (572 + 477));
									v78 = v66[v70];
									v76[v78[8 - 6]] = v76[v78[1 + 2]];
									v70 = v70 + 1 + 0;
									v78 = v66[v70];
									v76[v78[1 + 1 + 0]] = v78[89 - ((290 - 206) + 2)];
									v70 = v70 + (820 - ((2860 - 2261) + 220));
									v78 = v66[v70];
									v76[v78[2]] = v78[5 - 2];
									v70 = v70 + (1 - 0);
									v78 = v66[v70];
									v281 = v78[2 + 0];
									v76[v281] = v76[v281](v13(v76, v281 + (843 - ((1032 - 535) + 345)), v78[(70 + 1150) - (841 + 376)]));
									v70 = v70 + 1 + 0;
									v78 = v66[v70];
									v76[v78[1 + 1]][v78[1 + 2]] = v76[v78[1337 - (605 + 728)]];
								else
									v76[v78[3 - 1]] = v76[v78[3 + 0]][v78[8 - 4]];
								end
							elseif (v79 <= (2 + 36)) then
								if (v76[v78[7 - (1 + 4)]] == v78[4 + 0]) then
									v70 = v70 + (2 - 1);
								else
									v70 = v78[3 + 0];
								end
							elseif (v79 > (528 - (457 + 32))) then
								v76[v78[1 + 1]] = v78[1405 - (832 + 570)] + v76[v78[4 + 0]];
							else
								local v306 = v78[(1535 - 1013) - (150 + 370)];
								local v307 = v76[v306];
								local v308 = v76[v306 + 1 + 1];
								if (v308 > (0 - 0)) then
									if ((568 == 568) and (v307 > v76[v306 + 1 + 0])) then
										v70 = v78[799 - (588 + 208)];
									else
										v76[v306 + 3 + 0] = v307;
									end
								elseif ((4200 == 4200) and (v307 < v76[v306 + (391 - (14 + (393 - (12 + 5))))])) then
									v70 = v78[4 - 1];
								else
									v76[v306 + 3] = v307;
								end
							end
						elseif (v79 <= (28 + 15)) then
							if (v79 <= (37 + (15 - 11))) then
								v76[v78[5 - 3]][v78[3 + 0]] = v78[1804 - (884 + 916)];
							elseif ((v79 == (87 - 45)) or (4285 < 1369)) then
								v76[v78[2 + (0 - 0)]] = v62[v78[(1394 - 738) - (232 + 421)]];
							else
								v76[v78[1891 - (1569 + 320)]][v76[v78[1 + 2]]] = v76[v78[4]];
							end
						elseif (v79 <= ((74 - 44) + 14)) then
							local v167 = v78[1 + 1];
							v76[v167] = v76[v167](v13(v76, v167 + (3 - 2), v71));
						elseif ((v79 > (650 - (316 + 289))) or (3520 > 4910)) then
							local v313 = v78[(1 + 1) - 0];
							do
								return v76[v313](v13(v76, v313 + 1 + (1973 - (1656 + 317)), v71));
							end
						else
							local v314 = 0 - 0;
							local v315;
							while true do
								if ((2842 <= 4353) and (v314 == (0 + 0))) then
									v315 = v78[1455 - (666 + 702 + 85)];
									do
										return v13(v76, v315, v71);
									end
									break;
								end
							end
						end
						v70 = v70 + (426 - (360 + 65));
						break;
					end
				end
			end
		end;
	end
	return v29(v28(), {}, v17)(...);
end
return v15("LOL!1B3Q0003063Q00737472696E6703043Q006368617203043Q00627974652Q033Q0073756203053Q0062697433322Q033Q0062697403043Q0062786F7203053Q007461626C6503063Q00636F6E63617403063Q00696E73657274026Q00144003043Q00F7497BEE03073Q00569C2018851D26026Q000840030A3Q004C9AB0F94B3370A4B2F403063Q005613C5DE9826027Q004003043Q00D1FAA62103053Q0072B69BCB44026Q00F03F030E3Q002E21F15B1BB9322FF35502B4292A03063Q00DC464E9E3076028Q00030B3Q00EADF421AB6442FC6D24A3803073Q004AA5B32654D72903023Q005F47030B3Q006E65772Q636C6F7375726500404Q001F7Q00122Q000100013Q00202Q00010001000200122Q000200013Q00202Q00020002000300122Q000300013Q00202Q00030003000400122Q000400053Q00062Q0004000B000100010004173Q000B000100122A000400063Q00202500050004000700122A000600083Q00202500060006000900122A000700083Q00202500070007000A00060F00083Q000100062Q00153Q00074Q00153Q00014Q00153Q00054Q00153Q00024Q00153Q00034Q00153Q00064Q0024000900083Q00122Q000A000C3Q00122Q000B000D6Q0009000B000200104Q000B00094Q000900083Q00122Q000A000F3Q00122Q000B00106Q0009000B000200104Q000E00092Q0024000900083Q00122Q000A00123Q00122Q000B00136Q0009000B000200104Q001100094Q000900083Q00122Q000A00153Q00122Q000B00166Q0009000B000200104Q001400092Q0015000900083Q00120B000A00183Q00121C000B00196Q0009000B000200104Q0017000900122Q0009001A3Q00202Q000A3Q001700122Q000B001A3Q00202Q000C3Q00144Q000B000B000C00122Q000C001A3Q00202Q000D3Q00112Q001D000C000C000D002025000D3Q000E00122A000E001B3Q00060F000F0001000100012Q00158Q0021000E000F4Q002C000B3Q00022Q002B0009000A000B2Q000E3Q00013Q00023Q00093Q0003023Q005F4703023Q00437303073Q005551532Q442Q41026Q00084003083Q00594153444D525841026Q00F03F03083Q005941536130412Q56027Q0040026Q007040022F4Q001100025Q00122Q000300016Q00043Q000300302Q00040003000400302Q00040005000600302Q00040007000800102Q00030002000400122Q000300066Q00045Q00122Q000500063Q00042Q0003002A00012Q002000076Q0006000800026Q000900016Q000A00026Q000B00036Q000C00046Q000D8Q000E00063Q00122Q000F00026Q000F000F6Q000F0006000F00202Q000F000F00064Q000C000F6Q000B3Q00024Q000C00036Q000D00046Q000E00016Q000F00016Q000F0006000F00102Q000F0006000F4Q001000016Q00100006001000102Q00100006001000202Q0010001000064Q000D00106Q000C8Q000A3Q000200202Q000A000A00094Q0009000A6Q00073Q00010004220003000B00012Q0020000300054Q0015000400024Q0018000300044Q002D00036Q000E3Q00017Q00073Q00028Q00030B3Q00636865636B63612Q6C657203063Q00737472696E6703053Q006C6F77657203113Q006765746E616D6563612Q6C6D6574686F64026Q001440030B3Q004F6C644E616D6563612Q6C00223Q00120B000100014Q0002000200023Q002Q2600010002000100010004173Q0002000100120B000200013Q002Q2600020005000100010004173Q0005000100120B000300013Q002Q2600030008000100010004173Q0008000100122A000400024Q00140004000100020006090004000E00013Q0004173Q000E000100122A000400033Q00200C00040004000400122Q000500056Q000500016Q00043Q00024Q00055Q00202Q00050005000600062Q00040019000100050004173Q001900012Q0002000400044Q001B000400023Q00122A000400074Q002300056Q002E00046Q002D00045Q0004173Q000800010004173Q000500010004173Q002100010004173Q000200012Q000E3Q00017Q00", v9(), ...);
