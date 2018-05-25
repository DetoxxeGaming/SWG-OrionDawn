rifle_a280 = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/weapon/ranged/rifle/rifle_a280.iff",
	craftingValues = {
		{"mindamage",85,150,0},
		{"maxdamage",250,450,0},
		{"attackspeed",9.1,6.3,0},
		{"woundchance",25,35,0},
		{"hitpoints",750,750,0},
		{"attackhealthcost",23,14,0},
		{"attackactioncost",47,28,0},
		{"attackmindcost",61,37,0},
		{"roundsused",60,85,0},
		{"zerorangemod",-50,-50,0},
		{"maxrangemod",-50,-50,0},
		{"midrange",65,65,0},
		{"midrangemod",20,20,0},
	},
	customizationStringNames = {},
	customizationValues = {},

	-- randomDotChance: The chance of this weapon object dropping with a random dot on it. Higher number means less chance. Set to 0 to always have a random dot.
	randomDotChance = 1000,
	junkDealerTypeNeeded = JUNKWEAPONS+JUNKJAWA,
	junkMinValue = 25,
	junkMaxValue = 45

}

addLootItemTemplate("rifle_a280", rifle_a280)
