sword_mandalorian = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/weapon/melee/sword/sword_mandalorian.iff",
	craftingValues = {
		{"mindamage",350,550,0},
		{"maxdamage",551,750,0},
		{"attackspeed",2.1,1.0,1},
		{"woundchance",8,15,0},
		{"hitpoints",2500,2500,0},
		{"zerorangemod",-5,5,0},
		{"maxrangemod",-5,5,0},
		{"midrange",3,3,0},
		{"midrangemod",-5,5,0},
		{"maxrange",7,7,0},
		{"attackhealthcost",5,1,0},
		{"attackactioncost",10,5,0},
		{"attackmindcost",8,2,0},
	},
	customizationStringNames = {},
	customizationValues = {},

	-- randomDotChance: The chance of this weapon object dropping with a random dot on it. Higher number means less chance. Set to 0 to always have a random dot.
	randomDotChance = 0,
	junkDealerTypeNeeded = JUNKWEAPONS,
	junkMinValue = 30,
	junkMaxValue = 55
}

addLootItemTemplate("sword_mandalorian", sword_mandalorian)
