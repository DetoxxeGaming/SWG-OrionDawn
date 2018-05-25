ep3_clone_relics_durge_droid_01 = Creature:new {
	customName = "Durge Droid",
	randomNameType = NAME_GENERIC_TAG,
	socialGroup = "droids",
	faction = "",
	level = 150,
	chanceHit = 15.0,
	damageMin = 1750,
	damageMax = 2250,
	baseXp = 15000,
	baseHAM = 275000,
	baseHAMmax = 375000,
	armor = 2,
	resists = {65,65,65,65,65,65,65,65,25},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ENEMY + ATTACKABLE,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/ep3/ep3_clone_relics_durge_droid_01.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = merge(bountyhuntermaster)
}

CreatureTemplates:addCreatureTemplate(ep3_clone_relics_durge_droid_01, "ep3_clone_relics_durge_droid_01")
