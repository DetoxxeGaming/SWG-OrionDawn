theme_park_rebel_selonian_male = Creature:new {
	objectName = "",
	socialGroup = "rebel",
	faction = "rebel",
	level = 100,
	chanceHit = 1,
	damageMin = 645,
	damageMax = 1000,
	baseXp = 9429,
	baseHAM = 24000,
	baseHAMmax = 30000,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = PACK,
	optionsBitmask = INVULNERABLE + CONVERSABLE,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_selonian_m_01.iff",
				 "object/mobile/dressed_selonian_m_02.iff",
				 "object/mobile/dressed_selonian_m_03.iff",
				 "object/mobile/dressed_selonian_m_04.iff",
				 "object/mobile/dressed_selonian_m_05.iff",
				 "object/mobile/dressed_selonian_m_06.iff",
				 "object/mobile/dressed_selonian_m_07.iff",
				 "object/mobile/dressed_selonian_m_08.iff",
				 "object/mobile/dressed_selonian_m_09.iff",
				 "object/mobile/dressed_selonian_m_10.iff",
				 "object/mobile/dressed_selonian_m_11.iff",
				 "object/mobile/dressed_selonian_m_12.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "theme_park_rebel_mission_target_convotemplate",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(theme_park_rebel_selonian_male, "theme_park_rebel_selonian_male")