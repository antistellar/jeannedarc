#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <algorithm>

using namespace std;

string requestedStone, lowercaseSkills[174];

const string sword = "Sword", spear = "Spear", axe = "Axe", bow = "Bow", staff = "Staff", dagger = "Dagger", whip = "Whip",
other = "Cannot be used by player characters", any = "Any", red = "Coup de Grace (Red)", purple = "Innate skill (Purple)",
green = "Magic (Green)", blue = "Statistic (Blue)", n = "No", y = "Yes", null = "null";

const string skillNames[174] = {"Follow Me!", "Follow Me! II", "Jugulaire", "Blood Sword", "Blood Sword II", "Flash Strike",
"Triple Slash", "Heaven's Gate", "Crescent Arc", "Spirit Sword", "Tempest Sword", "War Reverie", "Hymn of Glory", "Impale!",
"Take Flight!", "Sweep!", "Leg Strike", "Pierce!", "Pierce! II", "Ravage!", "Destroy!", "Wood Chop", "Helm Splitter", "Mighty Roar",
"Compass", "Dire Swing", "Sniper", "Sniper II", "Sniper III", "Sniper IV", "Skewer Shot", "Poison Arrow", "Stun Arrow", "Recovery Shot",
"Meteor Bolt", "Salvo", "Sky Dart", "Toxic Arrow", "Revivify", "Mind Eater", "Swap", "Meteor", "Lightning", "Inferno", "Angel Tear",
"Thor's Hammer", "Sinister Storm", "Earthquake", "Shadow Stitch", "Venom Edge", "Two Hits", "Three Hits", "Four Hits", "Strange Dance",
"Bomb", "Skill Shakedown", "Gold Shakedown", "Aero Dagger", "Provoke", "Gold Snatcher", "Stun Whip", "Wild Whip", "Skill Snatcher",
"Jezebel's Slave", "Jezebel's Slave II", "Tail Whip", "Poison Breath", "Breath", "Wallop", "Body Slam", "Counter", "Counter II",
"Adroit", "Piercing Power", "Piercing Power II", "Piercing Power III", "Desperation", "Desperation II", "Desperation III", "Range +1",
"Range +2", "Mindbreaker", "Sneak By", "Healing Perfume", "Slip Through", "Fireball", "Fireball II", "Flame", "Flame II", "Ice Bullet",
"Ice Bullet II", "Blizzard", "Blizzard II", "Thunderbolt", "Thunderbolt II", "Cyclone", "Cyclone II", "Heal", "Heal II", "Healing Wind",
"Healing Wind II", "Cure", "Raise Force", "Raise Defenses", "Magic Shield", "Raise Mobility", "Lower Mobility", "Poison", "Lower Force",
"Lower Defenses", "Magic Rust", "HP Recovery", "HP Recovery II", "HP Recovery III", "EXP Bonus", "EXP Bonus II", "EXP Bonus III",
"EXP Bonus IV", "Preemptive", "Two Rounds", "Three Rounds", "Beast Slayer", "Man-Eater", "Goliath Slayer", "Undead Slayer", "Devil Slayer",
"Dragon Slayer", "Godspeed", "Critical Edge", "Treasure Hunter", "Treasure Lover", "HP +20", "HP +30", "HP +50", "HP +100", "HP +150",
"HP +300", "MP +10", "MP +20", "MP +30", "MP +50", "MP +100", "MP +150", "Attack +3", "Attack +5", "Attack +10", "Attack +20", "Attack +30",
"Magic Attack +3", "Magic Attack +5", "Magic Attack +10", "Magic Attack +20", "Accuracy +5", "Accuracy +10", "Accuracy +30", "Evade +5",
"Evade +10", "Evade +30", "Mobility +1", "Mobility +2", "Mobility +3", "Defense +3", "Defense +5", "Magic Defense +3", "Magic Defense +5",
"Sol Spirit +1", "Sol Spirit +2", "Sol Spirit +3", "Luna Spirit +1", "Luna Spirit +2", "Luna Spirit +3", "Stella Spirit +1", "Stella Spirit +2",
"Stella Spirit +3"};

const string skillDescriptions[174] = {"A mighty cry to stir up comrades. Raises the attack of allies within a 4-square radius for several turns.",
"Heroic daring that drives allies' fear away. Greatly raises the attack of all surrounding allies.",
"A precision strike on enemy vitals. Ensures all single-enemy attacks are critical hits for several turns.",
"Curses the bearer's weapon with a thirst for blood. Absorbs HP equal to 1/2 the damage dealt.",
"Turns the bearer's weapon into a malevolent demon. Absorbs HP equal to the damage dealt.",
"A single, scintillating attack to fell the opposition. Deals damage to one enemy.",
"Changes the users aura to a blade that strikes from three ways at once. Deals damage to one enemy.",
"A merciful attack that opens the gates to a peaceful afterlife. Deals mortal damage to one enemy.",
"Flashes the blade in an arc that evokes the moonlight. Strikes the 3 squares directly ahead at once.",
"Concentrates the surrounding aura into a sharp blade. Attacks all directly adjacent enemies at once.",
"Wields a storm as if it were rage and blows foes to bits. Attacks 4 squares directly ahead at once.",
"A hundred battles pass like a fleeting dream. Attacks all nearby foes, one after another.",
"A glorious attack blessed by all. Unleashes a powerful attack on the 7 squares directly ahead.",
"Strike down numerous foes at once with a single thrust! Attacks 7 squares in a straight line.",
"Take off like a bird and launch a thrust from above! Surmounts all obstacles to strike far-off foes.",
"Use the lance's length to mow down many foes at once! Attacks a wide area straight ahead.",
"Trips up the enemy with a long hilt. Stuns the enemy in addition to dealing damage.",
"Bust through enemy armor with a sharp thrust. Deals damage regardless of a foe's defense.",
"Bust through even heavy armor and go for the kill! Deals big damage regardless of a foe's defense.",
"Become a true demon and take on surrounding foes alone! Attacks enemies 2 squares away.",
"Slay all in your way with a cyclonic strike! Launches a fierce attack against a wide area directly ahead.",
"Raise a weapon up before hacking downward full-force. Deals heavy damage to one enemy.",
"A full-force attack that cleaves an enemy helm in two. Deals heavy damage and lowers defense.",
"The roar of a fearsome beast. Can paralyze enemies in the 3 squares directly ahead.",
"Use brute force to swing your weapon in a wide radius. Attacks all surrounding foes at once.",
"A ruthless slash that cuts through bone and all, leaving only a pitiful shell...Always critical if it hits.",
"Use keen archer senses to always hit the target. Guarantees a hit, but greatly lessens damage.",
"Use keen archer senses to always hit the target. Guarantees a hit, but slightly lessens damage.",
"Use keen archer senses to always hit a single target. Guarantees a hit without compromising damage.",
"Sight enemy weak points with the accuracy of God Himself. Ensures a hit for heavy damage.",
"Draw the bow taut and run one foe after another through. Attacks all enemies in a straight line at once.",
"A poison-tipped arrow that is a tradition of hunting peoples. Inflicts poison as well as damage.",
"An arrow tipped with a powerful tranquilizer. Paralyzes foe in addition to dealing damage.",
"A first aid shot that fires a healing arrow into an ally. Restores a lot of HP to a faraway target.",
"A dense aura that tears the sky and pierces the enemy. A secret bow technique that deals big damage.",
"An assault of arrows that rains down wherever you aim. Randomly attacks a wide area.",
"An arrow of light shot heavenward that chases its prey to Earth's end. Attacks anywhere on the map.",
"A poisonous attack that fills the battlefield with agonized screams. Inflicts damage and strong poison.",
"High recovery spell. Breathes life into the fallen. Revives an ally.",
"High offensive spell. Steals an opponent's magic-ancient taboo. Absorbs the target's MP.",
"High support spell. Twists the fabric of space. Swaps the caster's position with that of a chosen ally.",
"High offensive spell. Causes a meteor shower that deals random damage to enemies in range.",
"High offensive spell(neutral). Sets off a supercharged blast that deals heavy damage to one enemy.",
"The ultimate sol magic. Summons hellfire through a sinister pact, turning the battlefield to cinders.",
"The ultimate luna magic. A single droplet's purity washes all away in a raging torrent.",
"The ultimate stella magic. An ancient thunder god's hammer parts the heavens in judgment.",
"The ultimate neutral magic. Summons a tornado of loathing that gouges the earth.",
"Ultimate magic that leads good and evil to nature's appointed end. Shakes up friend and foe alike.",
"Sews a foe's shadow to the ground, restricting movement. Paralyzes foe in addition to dealing damage.",
"Attacks with a blade coated in venom. Sometimes poisons in addition to dealing damage.",
"Unleashes a string of attacks faster than the eye can register. Attacks twice in one go.",
"Unleashes a string of attacks faster than the eye can register. Attacks thrice in one go.",
"Unleashes a string of attacks faster than the eye can register. Attacks four times in one go.",
"Sap energy from foes with an odd dance that's...not meant to be odd. Lowers attack for several turns.",
"Sends a bomb rolling toward the enemy's feet. Deals damage to a wide area around the target.",
"A cutthroat tactic that steals the enemies skill stones. Randomly obtains one stone if successful.",
"A cutthroat tactic that robs the enemy of their gold. Children don't try this at home!",
"Hurls a knife in a straight line at the targeted foe. Can attack an enemy up to 7 squares away.",
"Taunts the enemy to draw their attention. Makes the user more prone to attack for 1 turn.",
"Reaches into the enemy's bosom to relieve them of their valuables. Don't try this at home, loves!",
"Ties up foes after striking them. Sometimes paralyzes enemies in addition to dealing damage.",
"Crack your whip indiscriminately as if possessed by an ice queen. Randomly attacks a wide area.",
"Filch skill stones the enemy is carrying. We might even snag us one stone at random, loves!",
"Charm enemies with a titillating pose. Makes the user more prone to attacks for 1 turn.",
"Play up irresistible...assets to seduce the enemy. Makes the user more prone to attacks for 3 turns.",
"Dragon skill. Swings a tail as thick as a log. Deals damage to the 3 squares directly ahead.",
"Dragon skill. Breathes noxious breath. Poisons a wide area directly ahead.",
"Dragon skill. Breathes fiery breath that can melt iron. Deals heavy damage to the area directly ahead.",
"Golem skill. Swings a huge arm in a crushing punch. Deals damage to the 3 squares directly ahead.",
"Golem skill. Leaps and crashes its enormous body into the ground. Deals heavy damage to all nearby.",
"Predict, dodge, and returns blows. Counters a percentage of enemy attacks without taking damage.",
"Dodge an attack and rebound with a powerful counterattack. Deals heavy damage when countering.",
"Meet assaults from any directions. No disadvantage when attacked from the rear or side.",
"Uses the wielder's weight to limit damage drop to the distant foe when piercing two targets.",
"Uses the wielder's weight to negate damage drop to the distant foe when piercing two targets.",
"Uses all the wielders weight to deliver heavy damage, even to the distant foe.",
"Become a death-seeking warrior, swinging with abandon. Raises attack but slightly lowers defense.",
"Become a death-seeking warrior, swinging with abandon. Greatly raises attack but lowers defense.",
"Parallel a warrior willing to give all to kill his foe. Gain fearsome attack, but also perilous defense.",
"A bow technique that uses more effective trajectory. Extends range by 1 square.",
"A bow technique that uses more effective trajectory. Extends range by 2 squares.",
"A wallop of negative magic hinders enemy spellpowers. Deals damage to MP as well when attacking.",
"An agent's tech for slipping past nearby foes. Enables movement through an enemy square.",
"An adult scent mixed with an odd healing medicine. Restores some HP to all allies each turn.",
"A bandit skill used for charming nearby foes. Move through an enemy's square, loves!",
"Offensive Spell (sol). Hurls a giant ball of flame at an enemy.",
"Offensive Spell (sol). Hurls an enormous fireball that chars to the bone.",
"Offensive Spell (sol). Scorches the area in a fierce torrent of flame.",
"Offensive Spell (sol). Turns the area to ash in a storm of blazing fire.",
"Offensive Spell (luna). Fires an icy projectile at an enemy.",
"Offensive Spell (luna). Mercilessly impales an enemy on myriad lances of ice.",
"Offensive Spell (luna). Turns the area to ice with its cold, raging winds.",
"Offensive Spell (luna). Whirls up an ice tempest that freezes all in the area.",
"Offensive Spell (stella). Rains lightning down upon an enemy's head.",
"Offensive Spell (stella). Sunders the heavens and strikes an enemy dead.",
"Offensive Spell (stella). Swirls through an area and dices enemies in a violent whirlwind.",
"Offensive Spell (stella). Swallows the enemy horde in a vortex that rips through the area.",
"Recovery Spell. Mends wounds with its pure light. Restores HP to the target (normal).",
"Recovery Spell. Mends dire wounds with the light of God's mercy. Restores HP to the target (high).",
"Recovery Spell. Its balmy winds bring comfort to all. Restores HP to all allies in an area (normal).",
"Recovery Spell. Its merciful light heals all that behold it. Restores HP to all allies in an area (high).",
"Recovery Spell. Neutralizes the body's afflictions. Cures status ailments like poison and paralysis.",
"Support spell. Temporarily invigorates the muscles. Raises the target's attack for several turns.",
"Support spell. Magically fortifies armor. Raises the target's defense for several turns.",
"Support spell. Creates a magic barrier. Raises the target's magic defense for several turns.",
"Support spell. Calls upon the wind to lighten one's step. Raises the target's mobility for several turns.",
"Support spell. Makes the air around a foe denser. Lowers the target's mobility for several turns.",
"Offensive Spell. Gathers up latent toxins around the enemy. Poisons the target for several turns.",
"Support spell. Temporarily fatigues an enemy. Lowers the target's attack for several turns.",
"Support spell. Weakens the overall constitution of armor. Lowers the target's defense for several turns.",
"Support spell. Upsets a foe's concentration. Lowers the target's magic defense for several turns.",
"A crystal full of life's wondrous ability to endure harsh conditions. Restores HP by 10% each turn.",
"A crystal full of life's wondrous ability to endure harsh conditions. Restores HP by 20% each turn.",
"A crystal full of life's wondrous ability to endure harsh conditions. Restores HP by 30% each turn.",
"A stone that has traveled eternity and seen the art of war perfected. Multiplies EXP earned by 120%.",
"A stone that has traveled eternity and seen the art of war perfected. Multiplies EXP earned by 150%.",
"A stone that has traveled eternity and seen the art of war perfected. Multiplies EXP earned by 200%.",
"A stone that has traveled eternity and seen the art of war perfected. Multiplies EXP earned by 300%.",
"An odd stone that invites carelessness on the part of foes. Counters before their attack instead of after.",
"The crystallized souls of heroes drunk on battle. Fight a second round with opponents.",
"The crystallized souls of heroes drunk on battle. Fight a third round with opponents.",
"A stone that causes weapons to confuse a beast's instincts. Deals additional damage to beasts.",
"A stone that curses weapons with a loathing of mankind. Deals additional damage to humans.",
"A dishonorable stone that reminds giants of their days of defeat. Deals additional damage to giants.",
"A heaven-blessed stone full of divine prayers. Deals additional damage to the undead.",
"A miraculous demon-repelling stone with God's mark. Deals additional damage to demons.",
"A stone housing ancient braves who brought dragons to the bay. Deals additional damage to wyverns.",
"Amplifies power as each foe is slain, speeding the wielder along. Move again if target is defeated.",
"An eerie light that reveals foes' weaknesses. Improves the chances of critical hits when attacking.",
"A bandit skill that uses a sixth sense to seek out treasure. Locates hidden treasures on the map.",
"A bandit skill that uses a sixth sense to seek out treasure. Locates hidden treasures, loves!",
"A stone of crystallized life force. Increases HP by 20.",
"A stone of crystallized life force. Increases HP by 30.",
"A stone of crystallized life force. Increases HP by 50.",
"A stone of crystallized life force. Increases HP by 100.",
"A stone of crystallized life force. Increases HP by 150.",
"A stone of crystallized life force. Increases HP by 300.",
"A stone of crystallized magic. Increases MP by 10.",
"A stone of crystallized magic. Increases MP by 20.",
"A stone of crystallized magic. Increases MP by 30.",
"A stone of crystallized magic. Increases MP by 50.",
"A stone of crystallized magic. Increases MP by 100.",
"A stone of crystallized magic. Increases MP by 150.",
"A stone said to contain the crystallized valor of a great warrior. Increases attack by 3.",
"A stone said to contain the crystallized valor of a great warrior. Increases attack by 5.",
"A stone said to contain the crystallized valor of a great warrior. Increases attack by 10.",
"A stone said to contain the crystallized valor of a great warrior. Increases attack by 20.",
"A stone said to contain the crystallized valor of a great warrior. Increases attack by 20.",
"A stone said to contain the crystallized wisdom of a great mage. Increases magic attack by 3.",
"A stone said to contain the crystallized wisdom of a great mage. Increases magic attack by 5.",
"A stone said to contain the crystallized wisdom of a great mage. Increases magic attack by 10.",
"A stone said to contain the crystallized wisdom of a great mage. Increases magic attack by 20.",
"A stone with an odd shine that offers courage to stare down a foe. Increases accuracy by 5.",
"A stone with an odd shine that offers courage to stare down a foe. Increases accuracy by 10.",
"A stone with an odd shine that offers courage to stare down a foe. Increases accuracy by 30.",
"A softly glowing stone that hones the mind. Increases evade by 5.",
"A softly glowing stone that hones the mind. Increases evade by 10.",
"A softly glowing stone that hones the mind. Increases evade by 30.",
"A stone that floats in midair by some strange force. Lightens the bearer and increases mobility by 1.",
"A stone that floats in midair by some strange force. Lightens the bearer and increases mobility by 2.",
"A stone that floats in midair by some strange force. Lightens the bearer and increases mobility by 3.",
"A stone said to contain the crystallized fortitude of a knight. Increases defense by 3.",
"A stone said to contain the crystallized fortitude of a knight. Increases defense by 5.",
"A stone said to contain the crystallized prayers of a priest. Increases magic defense by 3.",
"A stone said to contain the crystallized prayers of a priest. Increases magic defense by 5.",
"A warmly-lit stone said to contain the crystallized blessings of the sun. Increases sol affinity by 1.",
"A warmly-lit stone said to contain the crystallized blessings of the sun. Increases sol affinity by 2.",
"A warmly-lit stone said to contain the crystallized blessings of the sun. Increases sol affinity by 3.",
"A coldly-lit stone said to contain the crystallized blessings of the moon. Increases luna affinity by 1.",
"A coldly-lit stone said to contain the crystallized blessings of the moon. Increases luna affinity by 2.",
"A coldly-lit stone said to contain the crystallized blessings of the moon. Increases luna affinity by 3.",
"A queerly-lit stone said to contain the crystallized blessings of the stars. Increases stella affinity by 1.",
"A queerly-lit stone said to contain the crystallized blessings of the stars. Increases stella affinity by 2.",
"A queerly-lit stone said to contain the crystallized blessings of the stars. Increases stella affinity by 3."};

const int followMe = 0, followMeII = 1, jugulaire = 2, bloodSword = 3, bloodSwordII = 4, flashStrike = 5, tripleSlash = 6, heavensGate = 7,
crescentArc = 8, spiritSword = 9, tempestSword = 10, warReverie = 11, hymnOfGlory = 12, impale = 13, takeFlight = 14, sweep = 15, legStrike = 16,
pierce = 17, pierceII = 18, ravage = 19, destroy = 20, woodChop = 21, helmSplitter = 22, mightyRoar = 23, compass = 24, direSwing = 25,
sniper = 26, sniperII = 27, sniperIII = 28, sniperIV = 29, skewerShot = 30, poisonArrow = 31, stunArrow = 32, recoveryShot = 33, meteorBolt = 34,
salvo = 35, skyDart = 36, toxicArrow = 37, revivify = 38, mindEater = 39, swapSpell = 40, meteor = 41, lightning = 42, inferno = 43, angelTear = 44,
thorsHammer = 45, sinisterStorm = 46, earthquake = 47, shadowStitch = 48, venomEdge = 49, twoHits = 50, threeHits = 51, fourHits = 52,
strangeDance = 53, bomb = 54, skillShakedown = 55, goldShakedown = 56, aeroDagger = 57, provoke = 58, goldSnatcher = 59, stunWhip = 60,
wildWhip = 61, skillSnatcher = 62, jezebelsSlave = 63, jezebelsSlaveII = 64, tailWhip = 65, poisonBreath = 66, breath = 67, wallop = 68,
bodySlam = 69, counter = 70, counterII = 71, adroit = 72, piercingPower = 73, piercingPowerII = 74, piercingPowerIII = 75, desperation = 76,
desperationII = 77, desperationIII = 78, rangePlusOne = 79, rangePlusTwo = 80, mindbreaker = 81, sneakBy = 82, healingPerfume = 83, slipThrough = 84,
fireball = 85, fireballII = 86, flame = 87, flameII = 88, iceBullet = 89, iceBulletII = 90, blizzard = 91, blizzardII = 92, thunderbolt = 93,
thunderboltII = 94, cyclone = 95, cycloneII = 96, heal = 97, healII = 98, healingWind = 99, healingWindII = 100, cure = 101, raiseForce = 102,
raiseDefenses = 103, magicShield = 104, raiseMobility = 105, lowerMobility = 106, poison = 107, lowerForce = 108, lowerDefenses = 109,
magicRust = 110, hpRecovery = 111, hpRecoveryII = 112, hpRecoveryIII = 113, expBonus = 114, expBonusII = 115, expBonusIII = 116, expBonusIV = 117,
preemptive = 118, twoRounds = 119, threeRounds = 120, beastSlayer = 121, manEater = 122, goliathSlayer = 123, undeadSlayer = 124, devilSlayer = 125,
dragonSlayer = 126, godspeed = 127, criticalEdge = 128, treasureHunter = 129, treasureLover = 130, hpPlusTwenty = 131, hpPlusThirty = 132,
hpPlusFifty = 133, hpPlusOneHundred = 134, hpPlusOneFifty = 135, hpPlusThreeHundred = 136, mpPlusTen = 137, mpPlusTwenty = 138, mpPlusThirty = 139,
mpPlusFifty = 140, mpPlusOneHundred = 141, mpPlusOneFifty = 142, attackPlusThree = 143, attackPlusFive = 144, attackPlusTen = 145,
attackPlusTwenty = 146, attackPlusThirty = 147, magicAttackPlusThree = 148, magicAttackPlusFive = 149, magicAttackPlusTen = 150, magicAttackPlusTwenty = 151,
accuracyPlusFive = 152, accuracyPlusTen = 153, accuracyPlusThirty = 154, evadePlusFive = 155, evadePlusTen = 156, evadePlusThirty = 157,
mobilityPlusOne = 158, mobilityPlusTwo = 159, mobilityPlusThree = 160, defensePlusThree = 161, defensePlusFive = 162, magicDefensePlusThree = 163,
magicDefensePlusFive = 164, solSpiritPlusOne = 165, solSpiritPlusTwo = 166, solSpiritPlusThree = 167, lunaSpiritPlusOne = 168, lunaSpiritPlusTwo = 169,
lunaSpiritPlusThree = 170, stellaSpiritPlusOne = 171, stellaSpiritPlusTwo = 172, stellaSpiritPlusThree = 173, self = 0, weapon = 50, map = 100;

//effect, type(color), weapon, through obstacles?, reversible, aoe
const string skillProperties[174][6] = {/*followme*/{"Attack +10", red, sword, null, null, "  X\n XUX\n  X"},
/*followMeII*/{"Attack + 20", red, sword, null, null, " XXX\n XUX\n XXX"}, /*jugulaire*/{"100% Critical", red, sword, null, null, null},
/*bloodSword*/{"ATKm = 1.0, Heals = 1/2 enemy HP loss", red, sword, null, y, null}, /*bloodSwordII*/{"ATKm = 1.0, Heals = enemy HP loss", red, sword, null, y, null},
/*flashStrike*/{"ATKm = 1.1", red, sword, null, y, null}, /*tripleSlash*/{"ATKm = 1.2", red, sword, null, y, null},
/*heavensGate*/{"Effect: ATKm = 1.3", red, sword, null, y, null}, /*crescentArc*/{"ATKb = 40", red, sword, null, n, "  X\n UX\n  X"},
/*spiritSword*/{"ATKb = 60", red, sword, null, n, "  X\n XUX\n  X"}, /*tempestSword*/{"ATKb = 80", red, sword, y, n, "  X\n UXX\n  X"},
/*warReverie*/{"ATKb = 100", red, sword, null, n, " XXX\n XUX\n XXX"}, /*hymnOfGlory*/{"ATKb = 120", red, sword, y, n, "  XX\n UXXX\n  XX"},
/*impale*/{"ATKb = 30", red, spear, n, n, " UXXXXXXX"}, /*takeFlight*/{"ATKb = 50", red, spear, null, n, null},
/*sweep*/{"ATKb = 50", red, spear, y, n, "  X\n  XX\n UXXX\n  XX\n  X"}, /*legStrike*/{"Damage = (pATK - eDEF)/4, 75% chance to Paralyze", red, spear, n, y, null},
/*pierce*/{"ATKm = 0.3, eDEF = 0", red, spear, n, y, null}, /*pierceII*/{"ATKm = 0.5 eDEF = 0", red, spear, n, y, null},
/*ravage*/{"ATKb = 70", red, spear, y, n, "   X\n  X X\n X U X\n  X X\n   X"}, /*destroy*/{"ATKb = 90", red, spear, y, n, "  XX\n UXXXX\n  XX"},
/*woodChop*/{"ATKm = 1.2", red, axe, null, y, null}, /*helmSplitter*/{"ATKm = 1.3, chance to reduce eDEF by 20% for three turns.", red, axe, null, y, null},
/*mightyRoar*/{"50% chance to Paralyze", red, axe, null, n, "  X\n UX\n  X\n"}, /*compass*/{"ATKb = 0", red, axe, null, n, " XXX\n XUX\n XXX"},
/*direSwing*/{"ATKm = 1.2, always Critical", red, axe, null, y, null}, /*sniper*/{"ATKm = 0.8", red, bow, null, n, null},
/*sniperII*/{"ATKm = 0.9", red, bow, null, n, null}, /*sniperIII*/{"ATKm = 1.0", red, bow, null, n, null}, /*sniperIV*/{"ATKm = 1.5", red, bow, null, n, null},
/*skewerShot*/{"ATKb = 35", red, bow, n, n, " UXXXXXX"}, /*poisonArrow*/{"ATKm = 1.0, 25% chance to Poison", red, bow, null, n, null},
/*stunArrow*/{"ATKm = 1.0, 75% chance to Paralyze", red, bow, null, n, null}, /*recoveryShot */{"Heals = pMATK * 0.1 + 70", red, bow, null, null, null},
/*meteorBolt*/{"ATKm = 1.2", red, bow, null, n, null}, /*salvo*/{"ATKb = 60, hits 10 times randomly in Area of Effect", red, bow, null, n, "   X\n  XXX\n XXTXX\n  XXX\n   X"},
/*skyDart*/{"ATKm = 1.0", red, bow, null, n, null}, /*toxicArrow*/{"ATKm = 0.9, 75% chance to Poison", red, bow, null, n, null},
/*revivify*/{"Restores one dead unit to the map.", red, staff, null, null, null},
/*mindEater*/{"MATKb = 40, damages MP, restores MP equal to enemy MP loss", red, staff, null, n, null},
/*swapSpell*/{"Switches caster's position with targetted player unit.", red, staff, null, null, null},
/*meteor*/{"MATKb = 60, hits 10 times randomly in Area of Effect", red, staff, null, n, "   X\n  XXX\n XXTXX\n  XXX\n   X"},
/*lightning*/{"MATKb = 130", red, staff, null, n, null},
/*inferno*/{"Sol elemental, hits all enemy units, vs. Sol, MATKb = 75, vs. Luna, MATKb = -135, vs. Stella, MATKb = 285", red, staff, null, n, null},
/*angelTear*/{"Luna elemental, hits all enemy units, vs. Sol, MATKb = 285, vs. Luna, MATKb = 75, vs. Stella, MATKb = -135", red, staff, null, n, null},
/*thorsHammer*/{"Stella elemental, hits all enemy units, vs. Sol, MATKb = -135, vs. Luna, MATKb = 285, vs. Stella, MATKb = 75", red, staff, null, n, null},
/*sinisterStorm*/{"MATKb = 75, hits all enemy units", red, staff, null, n, null},
/*earthquake*/{"MATKb = 65, hits all enemy and allied units", red, staff, null, n, null},
/*shadowStitch*/{"(pATK - eDEF)/2, 75% chance to Paralyze", red, dagger, null, n, "  X\n XUX\n  X"}, /*venomEdge*/{"ATKm = 1.0, 50% chance to Poison", red, dagger, null, y, null},
/*twoHits*/{"ATKm = 1.0, strikes twice.", red, dagger, null, y, null}, /*threeHits*/{"ATKm = 1.0, strikes three times.", red, dagger, null, y, null},
/*fourHits*/{"ATKm = 1.0, strikes four times.", red, dagger, null, y, null},
/*strangeDance*/{"enemy units in Area of Effect = ATK -10.", red, dagger, null, n, "  X\n XUX\n  X"}, /*bomb*/{"ATKb = 60", red, dagger, y, n, "   X\n   X\n XXTXX\n   X\n   X"},
/*skillShakedown*/{"(pATK - eDEF)/4, chance to steal a copy of one of the enemy's equipped skill stones.", red, dagger, null, y, null},
/*goldShakedown*/{"(pATK - eDEF)/2, steals gold roughly equal to the normal death drop.", red, dagger, null, y, null},
/*aeroDagger*/{"ATKm = 1.0, strikes closest enemy in Area of Effect", red, dagger, y, n, " UXXXXXXX"},
/*provoke*/{"Colet is \"marked\" for one turn. Enemies will attack Colet rather than other targets. If they cannot attack him, they will attack other units. Enemies may still use attacks that target multiple characters. If Colet and Rose are both \"marked\" and in range, enemies may attack either.", red, dagger, null, null, null},
/*goldSnatcher*/{"(pATK - eDEF)/2, steals gold roughly equal to the normal death drop.", red, whip, null, y, null},
/*stunWhip*/{"ATKm = 1.0, 25% chance to Paralyze", red, whip, null, y, null},
/*wildWhip*/{"ATKb = 40, strikes 10 times randomly in Area of Effect", red, whip, y, n, "   X\n  XXX\n XXUXX\n  XXX\n   X"},
/*skillSnatcher*/{"(pATK - eDEF)/4, chance to steal a copy of one of the enemy's equipped skill stones.", red, whip, null, y, null},
/*jezebelsSlave*/{"Rose is \"marked\" for one turn. Enemies will attack Rose rather than other targets. If they cannot attack her, they will attack other units. Enemies may still use attacks that target multiple characters. If Colet and Rose are both \"marked\" and in range, enemies may attack either.", red, whip, null, null, null},
/*jezebelsSlaveII*/{"Rose is \"marked\" for three turns. Enemies will attack Rose rather than other targets. If they cannot attack her, they will attack other units. Enemies may still use attacks that target multiple characters. If Colet and Rose are both \"marked\" and in range, enemies may attack either.", red, whip, null, null, null},
/*tailWhip*/{null, red, other, null, null, null}, /*poisonBreath*/{null, red, other, null, null, null}, /*breath*/{null, red, other, null, null, null},
/*wallop*/{null, red, other, null, null, null}, /*bodySlam*/{null, red, other, null, null, null},
/*counter*/{"~30% chance to cancel an enemy attack that can be countered.", purple, sword, null, null, null},
/*counterII*/{"~30% chance to cancel an enemy attack that can be countered and respond with a boosted counterattack.", purple, sword, null, null, null},
/*adroit*/{"Turns unit toward an attacking enemy before damage calculation. (100%)", purple, sword, null, null, null},
/*piercingPower*/{"Increases damage to the back target when striking two enemies from 50% to 70%.", purple, spear, null, null, null},
/*piercingPowerII*/{"Increases damage to the back target when striking two enemies from 50% to 100%.", purple, spear, null, null, null},
/*piercingPowerIII*/{"Increases damage of all basic attacks, counters, and REV skills to 120%, expands damage cap to 120% of base ATK, applies to front and back targets.", purple, spear, null, null, null},
/*desperation*/{"Adds 10% to basic attacks and counters. Increases damage cap for basic attacks and counters to 110%. Decreases unit DEF during damage calculation by 10%.", purple, axe, null, null, null},
/*desperationII*/{"Adds 20% to basic attacks and counters. Increases damage cap for basic attacks and counters to 120%. Decreases unit DEF during damage calculation by 20%.", purple, axe, null, null, null},
/*desperationIII*/{"Adds 30% to basic attacks and counters. Increases damage cap for basic attacks and counters to 130%. Decreases unit DEF during damage calculation by 30%.", purple, axe, null, null, null},
/*rangePlusOne*/{"Adds 1 to basic attack range and skills that rely on weapon for range.", purple, bow, null, null, null},
/*rangePlusTwo*/{"Adds 2 to basic attack range and skills that rely on weapon for range.", purple, bow, null, null, null},
/*mindbreaker*/{"Inflicts damage from basic attacks and counters to enemy HP and MP.", purple, staff, null, null, null},
/*sneakBy*/{"Allows unit to move through enemy-occupied panels.", purple, dagger, null, null, null},
/*healingPerfume*/{"Heals all allied units by 10% at the beginning of each turn.", purple, whip, null, null, null},
/*slipThrough*/{"Allows unit to move through enemy-occupied panels.", purple, whip, null, null, null},
/*fireball*/{"MATKb = 50, elemental (1.2x damage vs. Stella, 0.8 damage vs. Luna)", green, any, null, n, null},
/*fireballII*/{"MATKb = 90, elemental (1.3x damage vs. Stella, 0.7 damage vs. Luna)", green, any, null, n, null},
/*flame*/{"MATKb = 35, elemental (1.2x damage vs. Stella, 0.8 damage vs. Luna)", green, any, null, n, "  X\n XTX\n  X"},
/*flameII*/{"MATKb = 55, elemental (1.3x damage vs. Stella, 0.7 damage vs. Luna)", green, any, y, n, "   X\n   X\n XXTXX\n   X\n   X"},
/*iceBullet*/{"MATKb = 50, elemental (1.2x damage vs. Sol, 0.8 damage vs. Stella)", green, any, null, n, null},
/*iceBulletII*/{"MATKb = 90, elemental (1.3x damage vs. Sol, 0.7 damage vs. Stella)", green, any, null, n, null},
/*blizzard*/{"MATKb = 35, elemental (1.2x damage vs. Sol, 0.8 damage vs. Stella)", green, any, null, n, " X X\n  T\n X X"},
/*blizzardII*/{"MATKb = 55, elemental (1.3x damage vs. Sol, 0.7 damage vs. Stella)", green, any, y, n, " X   X\n  X X\n   T  \n  X X\n X   X"},
/*thunderbolt*/{"MATKb = 50, elemental (1.2x damage vs. Luna, 0.8 damage vs. Sol)", green, any, null, n, null},
/*thunderboltII*/{"MATKb = 90, elemental (1.3x damage vs. Luna, 0.7 damage vs. Sol)", green, any, null, n, null},
/*cyclone*/{"MATKb = 35, elemental (1.2x damage vs. Luna, 0.8 damage vs. Sol)", green, any, null, n, "  XX    n\n  T    w+e\n XX     s"},
/*cycloneII*/{"MATKb = 55, elemental (1.3x damage vs. Luna, 0.7 damage vs. Sol)", green, any, null, n, " XXX\n XTX\n XXX"},
/*heal*/{"Heals for pMATK*0.1 + 60", green, any, null, null, null}, /*healII*/{"Heals for pMATK*0.1 + 100", green, any, null, null, null},
/*healingWind*/{"Heals allies in area of effect for pMATK*0.1 + 50", green, any, null, null, "  X\n XTX\n  X"},
/*healingWindII*/{"Heals allies in area of effect for pMATK*0.1 + 120", green, any, y, null, "   X\n  XXX\n XXTXX\n  XXX\n   X"},
/*cure*/{"Removes Poison, Paralysis.", green, any, null, null, null}, /*raiseForce*/{"Attack +10", green, any, null, null, null},
/*raiseDefenses*/{"Defense +10", green, any, null, null, null}, /*magicShield*/{"Magic Defense +10", green, any, null, null, null},
/*raiseMobility*/{"Mobility +1", green, any, null, null, null}, /*lowerMobility*/{"Mobility -1", green, any, null, n, null},
/*poison*/{"Inflicts Poison Status. Poison damages the unit for 10% max HP, at the beginning of each turn.", green, any, null, n, null},
/*lowerForce*/{"Attack -10", green, any, null, n, null}, /*lowerDefenses*/{"Defense -10", green, any, null, n, null},
/*magicRust*/{"Defense -10", green, any, null, n, null}, /*hpRecovery*/{"Restores 10% HP at the start of each turn.", blue, any, null, null, null},
/*hpRecoveryII*/{"Restores 20% HP at the start of each turn.", blue, any, null, null, null},
/*hpRecoveryIII*/{"Restores 30% HP at the start of each turn.", blue, any, null, null, null}, /*expBonus*/{"120% EXP gain.", blue, any, null, null, null},
/*expBonusII*/{"150% EXP gain.", blue, any, null, null, null}, /*expBonusIII*/{"200% EXP gain.", blue, any, null, null, null},
/*expBonusIV*/{"300% EXP gain.", blue, any, null, null, null},
/*preemptive*/{"Character will counterattack before the enemy's attack, if a counter is possible. (100%)", blue, any, null, null, null},
/*twoRounds*/{"~30% chance to execute basic attack twice. Enemy also counters twice, if a counter is possible.", blue, any, null, null, null},
/*threeRounds*/{"~30% chance to execute basic attack three times. Enemy also counters twice, if a counter is possible.", blue, any, null, null, null},
/*beastSlayer*/{"Increases pATK vs. Beast type by 15% for basic attacks and counters.", blue, any, null, null, null},
/*manEater*/{"Increases pATK vs. Human type by 15% for basic attacks and counters.", blue, any, null, null, null},
/*goliathSlayer*/{"Increases pATK vs. Goliath type by 15% for basic attacks and counters.", blue, any, null, null, null},
/*undeadSlayer*/{"Increases pATK vs. Undead type by 15% for basic attacks and counters.", blue, any, null, null, null},
/*devilSlayer*/{"Increases pATK vs. Devil type by 15% for basic attacks and counters.", blue, any, null, null, null},
/*dragonSlayer*/{"Increases pATK vs. Wyvern type by 15% for basic attacks and counters.", blue, any, null, null, null},
/*godspeed*/{"If the unit kills an enemy unit, it may take another turn (including move and attack), no additional MP/HP regen, etc. occurs.", blue, any, null, null, null},
/*criticalEdge*/{"CRIT +30", blue, any, null, null, null}, /*treasureHunter*/{"Reveals all item points on the map. Colet only.", blue, dagger, null, null, null},
/*treasureLover*/{"Reveals all item points on the map. Rose only.", blue, whip, null, null, null}, /*hpPlusTwenty*/{"Adds 20 to max HP.", blue, any, null, null, null},
/*hpPlusThirty*/{"Adds 30 to max HP.", blue, any, null, null, null}, /*hpPlusFifty*/{"Adds 50 to max HP.", blue, any, null, null, null},
/*hpPlusOneHundred*/{"Adds 100 to max HP.", blue, any, null, null, null}, /*hpPlusOneFifty*/{"Adds 150 to max HP.", blue, any, null, null, null},
/*hpPlusThreeHundred*/{"Adds 300 to max HP.", blue, any, null, null, null}, /*mpPlusTen*/{"Adds 10 to max MP.", blue, any, null, null, null},
/*mpPlusTwenty*/{"Adds 20 to max MP.", blue, any, null, null, null}, /*mpPlusThirty*/{"Adds 30 to max MP.", blue, any, null, null, null},
/*mpPlusFifty*/{"Adds 50 to max MP.", blue, any, null, null, null}, /*mpPlusOneHundred*/{"Adds 100 to max MP.", blue, any, null, null, null},
/*mpPlusOneFifty*/{"Adds 150 to max MP.", blue, any, null, null, null}, /*attackPlusThree*/{"Adds 3 to ATK.", blue, any, null, null, null},
/*attackPlusFive*/{"Adds 5 to ATK.", blue, any, null, null, null}, /*attackPlusTen*/{"Adds 10 to ATK.", blue, any, null, null, null},
/*attackPlusTwenty*/{"Adds 20 to ATK.", blue, any, null, null, null}, /*attackPlusThirty*/{"Adds 30 to ATK.", blue, any, null, null, null},
/*magicAttackPlusThree*/{"Adds 3 to MATK.", blue, any, null, null, null}, /*magicAttackPlusFive*/{"Adds 5 to MATK.", blue, any, null, null, null},
/*magicAttackPlusTen*/{"Adds 10 to MATK.", blue, any, null, null, null}, /*magicAttackPlusTwenty*/{"Adds 20 to MATK.", blue, any, null, null, null},
/*accuracyPlusFive*/{"Adds 5 to ACC.", blue, any, null, null, null}, /*accuracyPlusTen*/{"Adds 10 to ACC.", blue, any, null, null, null},
/*accuracyPlusThirty*/{"Adds 30 to ACC.", blue, any, null, null, null}, /*evadePlusFive*/{"Adds 5 to EVA.", blue, any, null, null, null},
/*evadePlusTen*/{"Adds 10 to EVA.", blue, any, null, null, null}, /*evadePlusThirty*/{"Adds 30 to EVA.", blue, any, null, null, null},
/*mobilityPlusOne*/{"Adds 1 to Mobility.", blue, any, null, null, null}, /*mobilityPlusTwo*/{"Adds 2 to Mobility.", blue, any, null, null, null},
/*mobilityPlusThree*/{"Adds 3 to Mobility.", blue, any, null, null, null}, /*defensePlusThree*/{"Adds 3 to DEF.", blue, any, null, null, null},
/*defensePlusFive*/{"Adds 5 to DEF.", blue, any, null, null, null}, /*magicDefensePlusThree*/{"Adds 3 to MDEF.", blue, any, null, null, null},
/*magicDefensePlusFive*/{"Adds 5 to MDEF.", blue, any, null, null, null},
/*solSpiritPlusOne*/{"For counters, basic attacks, and REV skills, increases pATK vs. Stella type by 10% and increases eATK vs. unit by 10%/20%/30% for Luna +1/+2/+3 enemy types.", blue, any, null, null, null},
/*solSpiritPlusTwo*/{"For counters, basic attacks, and REV skills, increases pATK vs. Stella type by 20% and increases eATK vs. unit by 10%/20%/30% for Luna +1/+2/+3 enemy types.", blue, any, null, null, null},
/*solSpiritPlusThree*/{"For counters, basic attacks, and REV skills, increases pATK vs. Stella type by 30% and increases eATK vs. unit by 10%/20%/30% for Luna +1/+2/+3 enemy types.", blue, any, null, null, null},
/*lunaSpiritPlusOne*/{"For counters, basic attacks, and REV skills, increases pATK vs. Sol type by 10% and increases eATK vs. unit by 10%/20%/30% for Stella +1/+2/+3 enemy types.", blue, any, null, null, null},
/*lunaSpiritPlusTwo*/{"For counters, basic attacks, and REV skills, increases pATK vs. Sol type by 20% and increases eATK vs. unit by 10%/20%/30% for Stella +1/+2/+3 enemy types.", blue, any, null, null, null},
/*lunaSpiritPlusThree*/{"For counters, basic attacks, and REV skills, increases pATK vs. Sol type by 30% and increases eATK vs. unit by 10%/20%/30% for Stella +1/+2/+3 enemy types.", blue, any, null, null, null},
/*stellaSpiritPlusOne*/{"For counters, basic attacks, and REV skills, increases pATK vs. Luna type by 10% and increases eATK vs. unit by 10%/20%/30% for Sol +1/+2/+3 enemy types.", blue, any, null, null, null},
/*stellaSpiritPlusTwo*/{"For counters, basic attacks, and REV skills, increases pATK vs. Luna type by 20% and increases eATK vs. unit by 10%/20%/30% for Sol +1/+2/+3 enemy types.", blue, any, null, null, null},
/*stellaSpiritPlusThree*/{"For counters, basic attacks, and REV skills, increases pATK vs. Luna type by 30% and increases eATK vs. unit by 10%/20%/30% for Sol +1/+2/+3 enemy types.", blue, any, null, null, null}};

//rarity, level, mp, duration, range
const int skillStats[174][5] = {/*followme*/{2, 5, 20, 2, self}, /*followMeII*/{4, 25, 30, 2, self},
/*jugulaire*/{3, 28, 55, 2, self}, /*bloodSword*/{4, 25, 30, 0, 1}, /*bloodSwordII*/{5, 42, 82, 0, 1},
/*flashStrike*/{1, 3, 28, 0, 1}, /*tripleSlash*/{2, 18, 51, 0, 1}, /*heavensGate*/{3, 37, 100, 0, 1},
/*crescentArc*/{1, 10, 34, 0, 1}, /*spiritSword*/{2, 19, 52, 0, self}, /*tempestSword*/{3, 26, 75, 0, 1},
/*warReverie*/{4, 39, 94, 0, self}, /*hymnOfGlory*/{5, 45, 115, 0, 1}, /*impale*/{2, 11, 35, 0, 1},
/*takeFlight*/{4, 20, 60, 0, 5}, /*sweep*/{3, 19, 55, 0, 1}, /*legStrike*/{3, 18, 45, 0, weapon},
/*pierce*/{3, 19, 55, 0, weapon}, /*pierceII*/{4, 36, 155, 0, weapon}, /*ravage*/{4, 28, 82, 0, self},
/*destroy*/{5, 44, 103, 0, 1}, /*woodChop*/{1, 3, 22, 0, 1}, /*helmSplitter*/{3, 18, 62, 0, 1},
/*mightyRoar*/{2, 5, 45, 0, 1}, /*compass*/{3, 15, 53, 0, self}, /*direSwing*/{3, 31, 49, 0, 1},
/*sniper*/{2, 5, 21, 0, weapon}, /*sniperII*/{3, 14, 53, 0, weapon}, /*sniperIII*/{4, 27, 78, 0, weapon},
/*sniperIV*/{5, 40, 103, 0, weapon}, /*skewerShot*/{4, 31, 55, 0, 1}, /*poisonArrow*/{2, 9, 32, 0, weapon},
/*stunArrow*/{3, 15, 52, 0, weapon}, /*recoveryShot */{3, 15, 32, 0, weapon}, /*meteorBolt*/{4, 23, 56, 0, weapon},
/*salvo*/{5, 42, 110, 0, weapon}, /*skyDart*/{4, 30, 70, 0, map}, /*toxicArrow*/{3, 27, 74, 3, weapon},
/*revivify*/{4, 33, 180, 0, 1}, /*mindEater*/{3, 36, 5, 0, 3}, /*swapSpell*/{3, 25, 58, 0, 8},
/*meteor*/{4, 40, 210, 0, map}, /*lightning*/{3, 30, 132, 0, 4}, /*inferno*/{5, 36, 260, 0, map},
/*angelTear*/{5, 36, 260, 0, map}, /*thorsHammer*/{5, 36, 260, 0, map}, /*sinisterStorm*/{5, 36, 260, 0, map},
/*earthquake*/{4, 29, 225, 0, map}, /*shadowStitch*/{2, 4, 20, 0, self}, /*venomEdge*/{2, 5, 25, 0, weapon},
/*twoHits*/{3, 12, 42, 0, weapon}, /*threeHits*/{4, 30, 71, 0, weapon}, /*fourHits*/{5, 46, 115, 0, weapon},
/*strangeDance*/{3, 14, 29, 3, self}, /*bomb*/{3, 19, 60, 0, 5}, /*skillShakedown*/{2, 20, 31, 0, weapon},
/*goldShakedown*/{2, 3, 15, 0, weapon}, /*aeroDagger*/{3, 14, 38, 0, self}, /*provoke*/{2, 8, 35, 1, self},
/*goldSnatcher*/{3, 3, 15, 0, weapon}, /*stunWhip*/{3, 5, 33, 0, weapon}, /*wildWhip*/{4, 24, 105, 0, self},
/*skillSnatcher*/{4, 17, 31, 0, weapon}, /*jezebelsSlave*/{2, 6, 31, 1, self}, /*jezebelsSlaveII*/{3, 21,54, 3, self},
/*tailWhip*/{3, 0, 0, 0, -1}, /*poisonBreath*/{5, 0, 0, 0, -1}, /*breath*/{3, 0, 0, 0, -1}, /*wallop*/{3, 0, 0, 0, -1},
/*bodySlam*/{3, 0, 0, 0, -1}, /*counter*/{2, 10, 0, 0, -1}, /*counterII*/{4, 34, 0, 0, -1}, /*adroit*/{4, 20, 0, 0, -1},
/*piercingPower*/{2, 7, 0, 0, -1}, /*piercingPowerII*/{3, 18, 0, 0, -1}, /*piercingPowerIII*/{4, 30, 0, 0, -1},
/*desperation*/{2, 4, 0, 0, -1}, /*desperationII*/{3, 13, 0, 0, -1}, /*desperationIII*/{4, 30, 0, 0, -1},
/*rangePlusOne*/{4, 28, 0, 0, -1}, /*rangePlusTwo*/{5, 46, 0, 0, -1}, /*mindbreaker*/{3, 12, 0, 0, -1},
/*sneakBy*/{2, 10, 0, 0, -1}, /*healingPerfume*/{3, 20, 0, 0, map}, /*slipThrough*/{2, 10, 0, 0, -1},
/*fireball*/{2, 5, 36, 0, 5}, /*fireballII*/{3, 15, 65, 0, 5}, /*flame*/{3, 7, 52, 0, 5}, /*flameII*/{4, 18, 105, 0, 5},
/*iceBullet*/{2, 6, 36, 0, 5}, /*iceBulletII*/{3, 16, 65, 0, 5}, /*blizzard*/{3, 11, 52, 0, 5},
/*blizzardII*/{4, 20, 105, 0, 5}, /*thunderbolt*/{2, 7, 36, 0, 5}, /*thunderboltII*/{3, 17, 65, 0, 5},
/*cyclone*/{3, 11, 52, 0, 5}, /*cycloneII*/{4, 22, 105, 0, 5}, /*heal*/{2, 3, 28, 0, 4}, /*healII*/{3, 16, 56, 0, 4},
/*healingWind*/{3, 9, 68, 0, 4}, /*healingWindII*/{4, 24, 103, 0, 4}, /*cure*/{2, 7, 29, 0, 4}, /*raiseForce*/{3, 17, 18, 3, 4},
/*raiseDefenses*/{3, 14, 21, 3, 4}, /*magicShield*/{3, 18, 18, 3, 4}, /*raiseMobility*/{3,20, 51, 3, 4},
/*lowerMobility*/{3, 10, 21, 3, 4}, /*poison*/{3, 10, 32, 3, 4}, /*lowerForce*/{3, 13, 25, 3, 4},
/*lowerDefenses*/{3, 21, 23, 3, 4}, /*magicRust*/{3, 18, 23, 3, 4}, /*hpRecovery*/{3, 10, 0, 0, -1},
/*hpRecoveryII*/{4, 21, 0, 0, -1}, /*hpRecoveryIII*/{5, 35, 0, 0, -1}, /*expBonus*/{2, 7, 0, 0, -1},
/*expBonusII*/{3, 15, 0, 0, -1}, /*expBonusIII*/{4, 22, 0, 0, -1}, /*expBonusIV*/{5, 29, 0, 0, -1},
/*preemptive*/{4, 38, 0, 0, -1}, /*twoRounds*/{4, 31, 0, 0, -1}, /*threeRounds*/{5, 45, 0, 0, -1},
/*beastSlayer*/{2, 24, 0, 0, -1}, /*manEater*/{3, 25, 0, 0, -1}, /*goliathSlayer*/{3, 27, 0, 0, -1},
/*undeadSlayer*/{3, 27, 0, 0, -1}, /*devilSlayer*/{4, 30, 0, 0, -1}, /*dragonSlayer*/{4, 30, 0, 0, -1},
/*godspeed*/{5, 50, 0, 0, -1}, /*criticalEdge*/{3, 20, 0, 0, -1}, /*treasureHunter*/{2, 9, 0, 0, map},
/*treasureLover*/{1, 3, 0, 0, map}, /*hpPlusTwenty*/{2, 11, 0, 0, -1}, /*hpPlusThirty*/{3, 13, 0, 0, -1},
/*hpPlusFifty*/{3, 17, 0, 0, -1}, /*hpPlusOneHundred*/{4, 23, 0, 0, -1}, /*hpPlusOneFifty*/{4, 35, 0, 0, -1},
/*hpPlusThreeHundred*/{5, 50, 0, 0, -1}, /*mpPlusTen*/{1, 7, 0, 0, -1}, /*mpPlusTwenty*/{2, 15, 0, 0, -1},
/*mpPlusThirty*/{3, 19, 0, 0, -1}, /*mpPlusFifty*/{3, 27, 0, 0, -1}, /*mpPlusOneHundred*/{4, 34, 0, 0, -1},
/*mpPlusOneFifty*/{5, 45, 0, 0, -1}, /*attackPlusThree*/{1, 1, 0, 0, -1}, /*attackPlusFive*/{2, 6, 0, 0, -1},
/*attackPlusTen*/{3, 13, 0, 0, -1}, /*attackPlusTwenty*/{4, 21, 0, 0, -1}, /*attackPlusThirty*/{5, 30, 0, 0, -1},
/*magicAttackPlusThree*/{2, 8, 0, 0, -1}, /*magicAttackPlusFive*/{3, 11, 0, 0, -1}, /*magicAttackPlusTen*/{4, 16, 0, 0, -1},
/*magicAttackPlusTwenty*/{5, 21, 0, 0, -1}, /*accuracyPlusFive*/{2, 7, 0, 0, -1}, /*accuracyPlusTen*/{3, 21, 0, 0, -1},
/*accuracyPlusThirty*/{4, 21, 0, 0, -1}, /*evadePlusFive*/{2, 4, 0, 0, -1}, /*evadePlusTen*/{3, 16, 0, 0, -1},
/*evadePlusThirty*/{4, 23, 0, 0, -1}, /*mobilityPlusOne*/{3, 24, 0, 0, -1}, /*mobilityPlusTwo*/{4, 32, 0, 0, -1},
/*mobilityPlusThree*/{5, 40, 0, 0, -1}, /*defensePlusThree*/{1, 5, 0, 0, -1}, /*defensePlusFive*/{2, 10, 0, 0, -1},
/*magicDefensePlusThree*/{1, 5, 0, 0, -1}, /*magicDefensePlusFive*/{2, 10, 0, 0, -1}, /*solSpiritPlusOne*/{1, 5, 0, 0, -1},
/*solSpiritPlusTwo*/{2, 10, 0, 0, -1}, /*solSpiritPlusThree*/{4, 20, 0, 0, -1}, /*lunaSpiritPlusOne*/{1, 5, 0, 0, -1},
/*lunaSpiritPlusTwo*/{2, 10, 0, 0, -1}, /*lunaSpiritPlusThree*/{4, 20, 0, 0, -1}, /*stellaSpiritPlusOne*/{1, 5, 0, 0, -1},
/*stellaSpiritPlusTwo*/{2, 10, 0, 0, -1}, /*stellaSpiritPlusThree*/{4, 20, 0, 0, -1}};

const int formulae[205][3] = {{accuracyPlusTen, accuracyPlusFive, accuracyPlusFive},{adroit, counter, evadePlusTen},{adroit, preemptive, expBonus},
{aeroDagger, cycloneII, accuracyPlusTen}, {aeroDagger, cycloneII, skewerShot}, {angelTear, healingPerfume, magicAttackPlusTwenty},
{attackPlusTen, attackPlusFive, attackPlusFive}, {attackPlusTen, attackPlusFive, solSpiritPlusTwo}, {attackPlusTwenty, attackPlusTen, attackPlusTen},
{attackPlusTwenty, attackPlusTen, solSpiritPlusThree}, {attackPlusThree, raiseForce, solSpiritPlusOne}, {attackPlusFive, attackPlusThree, solSpiritPlusOne},
{beastSlayer, tripleSlash, solSpiritPlusTwo}, {blizzard, lunaSpiritPlusTwo, lunaSpiritPlusTwo}, {blizzardII, blizzard, lunaSpiritPlusThree},
{blizzardII, crescentArc, spiritSword}, {blizzardII, lunaSpiritPlusThree, desperationIII}, {bloodSword, hpPlusFifty, spiritSword},
{bloodSword, hpRecovery, spiritSword}, {bloodSwordII, bloodSword, hpRecoveryII}, {bloodSwordII, bloodSword, magicAttackPlusTen},
{bomb, fireballII, aeroDagger}, {bomb, fireballII, flame}, {bomb, solSpiritPlusTwo, aeroDagger}, {compass, crescentArc, woodChop},
{compass, cyclone, woodChop}, {counter, expBonus, raiseMobility}, {counter, raiseMobility, tripleSlash}, {counterII, evadePlusTen, sneakBy},
{counterII, preemptive, counter}, {crescentArc, flashStrike, lunaSpiritPlusOne}, {crescentArc, lunaSpiritPlusOne, attackPlusThree},
{cyclone, stellaSpiritPlusTwo, stellaSpiritPlusTwo}, {cycloneII, compass, sweep}, {cycloneII, stellaSpiritPlusThree, compass},
{cycloneII, stellaSpiritPlusThree, sweep}, {defensePlusThree, raiseDefenses, stellaSpiritPlusOne}, {defensePlusFive, defensePlusThree, stellaSpiritPlusTwo},
{desperationII, desperation, raiseForce}, {desperationII, lowerDefenses, attackPlusThree}, {desperationIII, desperationII, mightyRoar},
{desperationIII, desperationII, provoke}, {destroy, ravage, sinisterStorm}, {devilSlayer, sniperIII, stellaSpiritPlusTwo}, {direSwing, criticalEdge, woodChop},
{direSwing, woodChop, helmSplitter}, {dragonSlayer, ravage, lunaSpiritPlusTwo}, {earthquake, bodySlam, thorsHammer}, {evadePlusTen, evadePlusFive, evadePlusFive},
{expBonusII, expBonus, expBonus}, {expBonusIII, expBonusII, expBonusII}, {expBonusIV, expBonusIII, expBonusIII}, {fireball, solSpiritPlusOne, solSpiritPlusOne},
{fireballII, fireball, solSpiritPlusTwo}, {fireballII, fireball, sniperII}, {flame, solSpiritPlusTwo, solSpiritPlusTwo}, {flameII, flame, bomb},
{flameII, flame, solSpiritPlusThree}, {flameII, solSpiritPlusThree, mightyRoar}, {followMe, mightyRoar, raiseForce}, {followMe, raiseForce, attackPlusThree},
{followMeII, followMe, attackPlusTen}, {followMeII, followMe, mightyRoar}, {fourHits, threeHits, threeHits}, {fourHits, threeHits, threeRounds},
{goliathSlayer, helmSplitter, stellaSpiritPlusTwo}, {healII, heal, hpPlusTwenty}, {healII, heal, magicAttackPlusThree}, {healingPerfume, healingWindII, jezebelsSlave},
{healingPerfume, hpRecoveryII, jezebelsSlave}, {healingWind, heal, cycloneII}, {healingWind, healII, cyclone}, {healingWindII, breath, healII},
{healingWindII, healingWind, hpRecovery}, {healingWindII, hpPlusFifty, mightyRoar}, {heavensGate, healII, tripleSlash}, {heavensGate, spiritSword, undeadSlayer},
{helmSplitter, takeFlight, lowerDefenses}, {helmSplitter, woodChop, thunderboltII}, {hpPlusOneHundred, hpPlusFifty, hpPlusFifty},
{hpPlusOneHundred, hpPlusFifty, lunaSpiritPlusTwo}, {hpPlusOneFifty, hpPlusOneHundred, hpPlusOneHundred}, {hpPlusOneFifty, hpPlusOneHundred, lunaSpiritPlusThree},
{hpPlusThirty, hpPlusTwenty, lunaSpiritPlusOne}, {hpPlusFifty, hpPlusThirty, hpPlusThirty}, {hpPlusFifty, hpPlusThirty, lunaSpiritPlusOne},
{hpRecoveryII, hpRecovery, hpRecovery}, {hpRecoveryIII, hpRecoveryII, hpPlusOneHundred}, {hpRecoveryIII, hpRecoveryII, hpRecoveryII}, {hymnOfGlory, inferno, warReverie},
{iceBullet, lunaSpiritPlusOne, lunaSpiritPlusOne}, {iceBulletII, iceBullet, crescentArc}, {iceBulletII, lunaSpiritPlusTwo, magicDefensePlusFive},
{iceBulletII, lunaSpiritPlusTwo, magicShield}, {impale, iceBullet, attackPlusThree}, {impale, piercingPower, iceBullet}, {inferno, warReverie, magicAttackPlusTwenty},
{jezebelsSlave, lowerForce, provoke}, {jezebelsSlave, magicAttackPlusFive, goldSnatcher}, {jezebelsSlave, stunWhip, lowerDefenses},
{jezebelsSlaveII, jezebelsSlave, bloodSwordII}, {jezebelsSlaveII, jezebelsSlave, mindEater}, {jugulaire, sniperII, woodChop}, {jugulaire, tripleSlash, criticalEdge},
{legStrike, goldShakedown, goldSnatcher}, {legStrike, lowerForce, crescentArc}, {lightning, piercingPowerII, mpPlusThirty}, {lightning, piercingPowerII, thunderboltII},
{magicAttackPlusTen, magicAttackPlusFive, magicAttackPlusFive}, {magicAttackPlusTen, magicAttackPlusFive, solSpiritPlusTwo},
{magicAttackPlusTwenty, magicAttackPlusTen, magicAttackPlusTen}, {magicAttackPlusTwenty, magicAttackPlusTen, solSpiritPlusThree},
{magicAttackPlusFive, magicAttackPlusThree, solSpiritPlusOne}, {magicDefensePlusThree, magicShield, stellaSpiritPlusOne},
{magicDefensePlusFive, magicDefensePlusThree, stellaSpiritPlusTwo}, {manEater, twoHits, lunaSpiritPlusTwo}, {meteor, salvo, fireballII},
{meteor, skyDart, flameII}, {meteorBolt, fireballII, impale}, {meteorBolt, stellaSpiritPlusTwo, fireballII}, {mightyRoar, followMe, lowerForce},
{mightyRoar, lowerForce, flashStrike}, {mindEater, mindbreaker, impale}, {mindEater, mpPlusTwenty, bloodSword}, {mindbreaker, magicRust, helmSplitter},
{mindbreaker, magicRust, jezebelsSlave}, {mobilityPlusTwo, mobilityPlusOne, mobilityPlusOne}, {mobilityPlusTwo, mobilityPlusOne, raiseMobility},
{mpPlusOneHundred, mpPlusFifty, lunaSpiritPlusThree}, {mpPlusOneHundred, mpPlusFifty, mpPlusFifty}, {mpPlusTwenty, mpPlusTen, lunaSpiritPlusOne},
{mpPlusThirty, mpPlusTwenty, lunaSpiritPlusOne}, {mpPlusThirty, mpPlusTwenty, mpPlusTwenty}, {mpPlusFifty, mpPlusThirty, lunaSpiritPlusTwo},
{mpPlusFifty, mpPlusThirty, mpPlusThirty}, {pierce, impale, attackPlusFive}, {pierce, lowerDefenses, piercingPower}, {pierceII, pierce, skewerShot},
{pierceII, piercingPowerII, attackPlusTen}, {piercingPowerII, piercingPower, attackPlusTen}, {piercingPowerII, piercingPower, expBonus},
{piercingPowerIII, piercingPowerII, attackPlusTwenty}, {piercingPowerIII, piercingPowerII, expBonusII}, {poisonArrow, sniper, poison}, {preemptive, counter, raiseMobility},
{preemptive, evadePlusTen, accuracyPlusTen}, {provoke, desperation, evadePlusFive}, {provoke, lowerDefenses, evadePlusFive}, {ravage, desperationIII, accuracyPlusTen},
{ravage, jugulaire, raiseMobility}, {recoveryShot, healII, impale}, {recoveryShot, healII, sniperII}, {recoveryShot, hpRecovery, skewerShot}, {revivify, healingWindII, cure},
{revivify, hpRecoveryII, magicAttackPlusTen}, {salvo, meteor, skyDart}, {shadowStitch, lowerForce, sniperII}, {shadowStitch, lowerForce, twoHits},
{sinisterStorm, ravage, magicAttackPlusTwenty}, {skewerShot, fireballII, sniperII}, {skewerShot, piercingPowerII, aeroDagger}, {skewerShot, sniperII, piercingPowerII},
{skillShakedown, shadowStitch, expBonusII}, {skillSnatcher, shadowStitch, jezebelsSlave}, {skyDart, takeFlight, meteorBolt}, {skyDart, takeFlight, mobilityPlusOne},
{sneakBy, evadePlusTen, mobilityPlusOne}, {sniper, accuracyPlusFive, lowerForce}, {sniperII, accuracyPlusTen, sniper}, {sniperII, sniper, attackPlusFive},
{sniperIII, accuracyPlusThirty, sniperII}, {sniperIII, sniperII, skewerShot}, {sniperIV, sniperIII, attackPlusTwenty}, {sniperIV, sniperIII, lightning},
{spiritSword, iceBulletII, attackPlusFive}, {spiritSword, skewerShot, crescentArc}, {strangeDance, lowerForce, goldShakedown}, {strangeDance, lowerForce, goldSnatcher},
{stunArrow, sniper, lowerForce}, {stunWhip, lowerForce, tailWhip}, {swapSpell, takeFlight, magicAttackPlusThree}, {sweep, bodySlam, raiseMobility}, {sweep, tripleSlash, legStrike},
{takeFlight, accuracyPlusTen, thunderbolt}, {takeFlight, sniper, thunderbolt}, {tempestSword, cycloneII, sweep}, {tempestSword, spiritSword, cycloneII},
{thorsHammer, skyDart, magicAttackPlusTwenty}, {threeHits, twoHits, twoHits}, {threeHits, twoHits, twoRounds}, {threeRounds, twoRounds, twoRounds},
{thunderbolt, stellaSpiritPlusOne, stellaSpiritPlusOne}, {thunderboltII, thunderbolt, stellaSpiritPlusTwo}, {thunderboltII, thunderbolt, takeFlight}, {toxicArrow, poisonArrow, sniperII},
{tripleSlash, flashStrike, crescentArc}, {tripleSlash, flashStrike, cyclone}, {twoHits, twoRounds, raiseMobility}, {undeadSlayer, healingWindII, solSpiritPlusTwo},
{venomEdge, poison, flashStrike}, {warReverie, manEater, followMeII}, {warReverie, tempestSword, fourHits}, {wildWhip, meteor, compass}, {wildWhip, tailWhip, meteor},
{wildWhip, threeHits, twoRounds}};

void generate_list(), skill_binding(), display_attributes(), fill_lowercaseSkills(), input_output(), print_description(),
wrap_string(const string &, unsigned int);

int main()
{
    fill_lowercaseSkills();

    cout << "-----------------JEANNE D'ARC SKILL STONE QUICK-REFERENCE GUIDE-----------------" << endl << endl;

    for(;;)
    {
        input_output();
    }

    return 0;
}

void generate_list()
{
    vector <string> list(174);

    const string nameInputDirections = "With the exception of case, enter the skill stone's name exactly as it appears in the list above "
    "(i.e. \"Sniper II\" instead of \"Sniper 2\", \"Impale!\" instead of \"Impale\", \"Man-Eater\" instead of \"Man Eater\"). "
    "Pay special attention to spaces as well (\"MP +100\" instead of \"MP+100\" or \"MP + 100\").";

    for(int x = 0; x < 174; x++)
    {
        list[x] = skillNames[x];
    }

    sort(list.begin(), list.end());

    cout << "---List of Skill Stones" << endl << endl;

    for(int x = 0; x < 174; x++)
    {
        cout << list[x];

        if(x % 3 != 2)
        {
            if(list[x].length() < 8)
            {
                cout << "\t\t\t";
            }

            else if(list[x].length() >= 8 && list[x].length() < 16)
            {
                cout << "\t\t";
            }
            else
            {
                cout << "\t";
            }
        }
        else
        {
            cout << endl;
        }
    }

    cout << endl;

    wrap_string(nameInputDirections, 80);
}

void skill_binding()
{
    bool noResults = true, noComponents = true;

    cout << "-----Skillbinding" << endl << endl << "---Skill stones required to create " << requestedStone << endl << endl;

    for(int x = 0; x < 205; x++)
    {
        if(skillNames[formulae[x][0]] == requestedStone)
        {
            cout << skillNames[formulae[x][0]] << " = " << skillNames[formulae[x][1]] << " + " << skillNames[formulae[x][2]] << endl;
            noResults = false;
        }
    }

    if(noResults)
    {
        cout << "N/A" << endl;
    }

    cout << endl << "---" << requestedStone << " as a component" << endl << endl;

    for(int x = 0; x < 205; x++)
    {
        if(skillNames[formulae[x][1]] == requestedStone)
        {
            cout << skillNames[formulae[x][1]] << " + " << skillNames[formulae[x][2]] << " = " << skillNames[formulae[x][0]] << endl;
            noComponents = false;
        }

        if(skillNames[formulae[x][2]] == requestedStone && formulae[x][1] != formulae[x][2])
        {
            cout << skillNames[formulae[x][2]] << " + " << skillNames[formulae[x][1]] << " = " << skillNames[formulae[x][0]] << endl;
            noComponents = false;
        }
    }

    if(noComponents)
    {
        cout << "N/A" << endl;
    }
}

void display_attributes()
{
    cout << "-----Attributes" << endl << endl;

    for(int x = 0; x < 174; x++)
    {
        if(skillNames[x] == requestedStone)
        {
            cout << "Type: ";

            if(skillProperties[x][1] == red)
            {
                cout << "Coup de Gr";
                cout << char(131);
                cout << "ce (Red)" << endl;
            }
            else
            {
                cout << skillProperties[x][1] << endl;
            }

            cout << "Rarity: ";

            for(int y = 0; y < skillStats[x][0]; y++)
            {
                cout << "*";
            }

            cout << endl;

            if(skillProperties[x][0] != null)
            {
                cout << "Effect: ";
                wrap_string(skillProperties[x][0], 72);
            }

            if(skillStats[x][1] != 0)
            {
                cout << "Required level: " << skillStats[x][1] << endl;
            }
            if(skillStats[x][2] != 0)
            {
                cout << "MP cost: " << skillStats[x][2] << endl;
            }

            if(skillProperties[x][2] != null)
            {
                cout << "Weapon: " << skillProperties[x][2] << endl;
            }

            if(skillStats[x][3] != 0)
            {
                cout << "Duration: " << skillStats[x][3] << " turn";

                if(skillStats[x][3] > 1)
                {
                    cout << "s";
                }

                cout << endl;
            }

            if(skillProperties[x][1] == purple || skillProperties[x][1] == blue)
            {
                cout << "Duration: Permanent while equipped" << endl;
            }

            if(skillStats[x][4] >= 0)
            {
                cout << "Range: ";

                if(skillStats[x][4] == self)
                {
                    cout << "Self" << endl;
                }
                else if(skillStats[x][4] == weapon)
                {
                    cout << "Weapon" << endl;
                }
                else if(skillStats[x][4] == map)
                {
                    cout << "Map" << endl;
                }
                else
                {
                    cout << skillStats[x][4] << endl;
                }
            }

            if(skillProperties[x][3] != null)
            {
                cout << "Goes through obstacles: " << skillProperties[x][3] << endl;
            }

            if(skillProperties[x][4] != null)
            {
                cout << "Reversible: " << skillProperties[x][4] << endl;
            }

            if(skillProperties[x][5] != null)
            {
                cout << "Area of effect: " << endl << endl << skillProperties[x][5] << endl;
            }

            break;
        }
    }

    cout << endl;
}

void fill_lowercaseSkills()
{
    for(int x = 0; x < 174; x++)
    {
        lowercaseSkills[x] = skillNames[x];

        for(unsigned int y = 0; y < skillNames[x].length(); y++)
        {
            lowercaseSkills[x][y] = tolower(skillNames[x][y]);
        }
    }
}

void input_output()
{
    string input;

    bool matchNotFound = true;

    cout << "Enter the name of a skill stone or enter \"special\" to view alternate commands: " << endl;

    getline(cin, input);

    for(unsigned int x = 0; x < input.length(); x++)
    {
        input[x] = tolower(input[x]);
    }

    if(input == "list" || input == "special" || input == "about" || input == "shorthand")
    {
        matchNotFound = false;
    }
    else
    {
        for(int x = 0; x < 174; x++)
        {
            if(input == lowercaseSkills[x])
            {
                requestedStone = skillNames[x];
                matchNotFound = false;
                break;
            }
        }
    }

    if(matchNotFound)
    {
        cout << endl << "*** No match found. Retry input or enter \"List\" to view acceptable inputs. ***" << endl;
    }
    else if(input == "list")
    {
        cout << endl << "--------------------------------------------------------------------------------";
        generate_list();
        cout << "--------------------------------------------------------------------------------";
    }
    else if(input == "special")
    {
        cout << endl << "--------------------------------------------------------------------------------";
        cout << "---Special Commands\n\nEnter one of the following commands to receive its respective information:\n\n"
        "List - Names of all skill stones found in the game.\nAbout - Sources, legal info, and other stuff you probably don't care about.\n"
        "Shorthand - A guide to the shorthand and abbreviations used in this guide.\nSpecial - See this exact same information again." << endl;
        cout << "--------------------------------------------------------------------------------";
    }
    else if(input == "about")
    {
        cout << endl << "--------------------------------------------------------------------------------";
        cout << "-----About\n\n---Sources\n\nAll information in this program comes from:\n\nChaotic_Fusion's FAQ/Walkthrough "
        "(skill descriptions and rarity values)\n"
        "http://www.cheatcc.com/psp/sg/jeanne_darc.txt\n\nMyself (reversibility values and other odds and ends)\n\nDarklao's FAQ/Walkthrough "
        "(everything else)\nhttp://www.gamefaqs.com/psp/934454-jeanne-darc/faqs/50626\n\n"
        "---Legal\n\n   Jeanne d'Arc and all its components are the property of Level 5 and SCEA. "
        "Alltrademarks and copyrights contained in this program are owned by their \nrespective trademark and copyright holders. "
        "This program is meant for personal \nuse only.\n\n"
        "---Appreciation\n\n"
        "   Thanks go to Chaotic_Fusion and especially Darklao for their terrific FAQs, \ncheatcc.com and gamefaqs.com for hosting said FAQs, "
        "Level 5 and SCEA for \ndeveloping and publishing this fantastic game, Sony for making the great \nPlaystation Portable system, and, of "
        "course, you for having wonderful taste in \ngames."<< endl;
        cout << "--------------------------------------------------------------------------------";
    }
    else if(input == "shorthand")
    {
        cout << endl << "--------------------------------------------------------------------------------";
        cout << "---Shorthand" << endl << endl;
        cout << "   Shorthand used in the \"Effects\" subsection of the \"Attributes\" section are \ntaken directly "
        "from Darklao's FAQ with some of my own added.  Refer to the \n\"Skills and Damage Calculation\" section of the FAQ "
        "for more detailed \ndescriptions.\n\nATK - Physical Attack\nDEF - Physical Defense\nMATK - Magic Attack\nMDEF - Magic Defense\n"
        "ACC - Accuracy\nEVA - Evasion\nATKm - pATK * ATKm - eDEF\nATKb - (pATK + ATKb - eDEF) / 2\nMATKb - (pMATK + MATKb - eMDEF) / 2\n\n"
        "A \'p\' (player) in front of a stat (e.g. pATK) represents the stat of the \ncharacter unit using the attack.\nAn \'e\' (enemy) "
        "in front of a stat (e.g. eMDEF) represents the stat of the \nopponent unit receiving the attack." << endl;
        cout << "--------------------------------------------------------------------------------";
    }
    else
    {
        cout << endl << "--------------------------------------------------------------------------------";
        cout << "-------" << requestedStone << endl << endl;
        print_description();
        display_attributes();
        skill_binding();

        cout << "--------------------------------------------------------------------------------";
    }

    cout << endl;
}

void print_description()
{
    cout << "-----Description" << endl << endl;

    for(int x = 0; x < 174; x++)
    {
        if(requestedStone == skillNames[x])
        {
            wrap_string(skillDescriptions[x], 80);

            cout << endl;

            break;
        }
    }
}

void wrap_string(const string & stringToWrap, unsigned int maxCharsPerLine)
{
    vector<int> wrapMarkerNeeded;
    vector<unsigned int> wrapMarkerLocation;
    unsigned int lineNumber = 1, totalWrappedSpaces = 0;
    //last character of line:  (((lineNumber * (maxCharsPerLine - 1) + (lineNumber - 1)) - totalWrappedSpaces)  //nested functions in c++ plz

    if(stringToWrap.length() < maxCharsPerLine)
    {
        cout << stringToWrap << endl;
    }
    else
    {
        for(; lineNumber <= (double(stringToWrap.length() + totalWrappedSpaces) / maxCharsPerLine); lineNumber++)
        {
            if(stringToWrap.length() > lineNumber * maxCharsPerLine && stringToWrap[((lineNumber * (maxCharsPerLine - 1) + (lineNumber - 1)) - totalWrappedSpaces)] != ' ')
            {
                int i = 1;
                bool wrapMarkerNotFound = true;
                wrapMarkerNeeded.push_back(1);

                do
                {
                    if(stringToWrap[((lineNumber * (maxCharsPerLine - 1) + (lineNumber - 1)) - totalWrappedSpaces) - i] == ' ')
                    {
                        wrapMarkerLocation.push_back(((lineNumber * (maxCharsPerLine - 1) + (lineNumber - 1)) - totalWrappedSpaces) - i);
                        totalWrappedSpaces += i;

                        wrapMarkerNotFound = false;
                    }

                    i++;
                }
                while(wrapMarkerNotFound);
            }
            else
            {
                wrapMarkerNeeded.push_back(0);
                wrapMarkerLocation.push_back((lineNumber * (maxCharsPerLine - 1) + (lineNumber - 1)) - totalWrappedSpaces);
            }
        }

        lineNumber = 1;

        for(unsigned int y = 0; y < stringToWrap.length(); y++)
        {
            cout << stringToWrap[y];

            if(wrapMarkerNeeded[lineNumber - 1] == 1 && y == wrapMarkerLocation[lineNumber - 1])
            {
                cout << endl;
            }

            if(maxCharsPerLine != 80 && y == wrapMarkerLocation[lineNumber - 1] && (stringToWrap.length() + totalWrappedSpaces != lineNumber * maxCharsPerLine))
            {
                for(unsigned int z = 0; z < (80 - maxCharsPerLine); z++)
                {
                    cout << " ";
                }
            }

            if(y == wrapMarkerLocation[lineNumber - 1] && (stringToWrap.length() + totalWrappedSpaces != lineNumber * maxCharsPerLine))
            {
                lineNumber++;
            }
        }

        if(stringToWrap.length() + totalWrappedSpaces != lineNumber * maxCharsPerLine)
        {
            cout << endl;
        }
    }
}
