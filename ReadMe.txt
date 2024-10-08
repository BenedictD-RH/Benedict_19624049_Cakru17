									ROBOT BATTLE 
								by Benedict Darrel Setiawan
						
									   GUIDE:

Creating a Robot : 
Pick a save slot for the Robot and pick out each part for it.
Each part decides an attribute for the robot which are:
- Main Body 		: Base Stats
- Engine 		: Passive Abilities
- Weapon/Equipment 	: Special attacks/moves
- Upgrade		: Bonus additional stats

You can see your Robot's Details in the 'Show Details' option


=========================================================================


Battling : 
Pick 2 Robots from the Save Slots to battle

When battling, it will display the following interface at the start of the turn :
_______________________________________________________

Turn 1!	<-[Turn amount]		[HP bar]
				   |
Test                               V          Test <- [Robot name]
____________________          ____________________
___________________/          \___________________
165/165                                    165/165 <- [true HP value]

______________________________________________________


When it's someone's turn it will display the following interface :

____________________________________________________________________
Test's Turn
<1>Attack <- [Deal a 50 base power attack]
<2>Defend <- [Reduce damage taken by 2/3 for 1 turn]
<3>Special <- [Special move based on the Robot's weapon/equipment]
Pick an action :
_____________________________________________________________________

Insert the number next to the action to select it.


The battle will end one or both of the Robots reach 0 HP

=========================================================================


											Battle Mechanics :

Attacking : deal damage to the opposing Robot

Damage dealt to the opponent follows the following formula:

  damageTaken = (pwr * (useratk / (oppdef * defend)) * random * crit * virus * engineBoost) + staticBoost;

pwr 		= move power (default for regular attacks is 35)
useratk 	= Attack stat of the user
oppdef		= Defense stat of the opponent
defend		= defend multiplier to the opponent's defense stat (1.5 if opponent defends in the previous turn)
random 		= random multiplier (1 - 1.1)
crit		= critical hit multiplier (1.2 if crit)
virus 		= virus multiplier (0.7 if user is inflicted with a virus)
engineBoost	= boosts gained from the Robot's engines
staticBoost	= additional set amount of damage

=========================================================================

Defending : reduces the damage taken for the opponent's next turn

=========================================================================

Turn priority: based on the Robots' speed stat (coin flip if the same)

=========================================================================

Specials : A special attack or move that usually only has one use per battle

(Details of each special is in the Robot parts details section)

=========================================================================

Healing : Heal a part of your lost HP

=========================================================================

Shields : An extension of the health bar that nullifies one attack per layer

Multiple layer of shields can be activated at the same time

Shields can be broken by critical hits

Most Specials secondary effects don't get nullified by Shields

=========================================================================

Debuffs : Effects that can be inflicted to Robots for a set number of turns

List of Debuffs and their effects are :
-Virus 		: Deal 1/12 of the inflicted's max HP and reduces the damage of their attacks by x0.7
-Disabled 	: Disables the inflicted's engines
-Inverse	: Swaps the inflicted's Attack and Defense stat values
-Stunned	: Skips the inflicted's turn after being stunned (only for one turn)

=========================================================================



									Robot Part Details:

Main Body (Base Stats):
<MB01> All Rounder
HP 	: 150
Attack 	: 50
Defense : 50 
Speed 	: 50


<MB02> Defender
HP 	: 170
Attack 	: 30
Defense : 75 
Speed 	: 25


<MB03> Crusader
HP 	: 155
Attack 	: 80
Defense : 40 
Speed 	: 25


<MB04> Striker
HP 	: 125
Attack 	: 70
Defense : 35 
Speed 	: 70


<MB05> Bruiser
HP 	: 175
Attack 	: 65
Defense : 55
Speed 	: 5


<MB06> Cruiser 
HP 	: 170
Attack 	: 35
Defense : 35 
Speed 	: 60

=========================================================================

Engine (Passive):
<EN01> Drain Engine
Heals the user after attacking by 30% of damage dealt in HP


<EN02> Reflect Engine
User deals 40% of HP lost to attacker


<EN03> Clutch Engine
User deals 30% more damage when below 50% HP


<EN04> Expansion Engine
User deals 50% damage at first turn but adds 30% to the multiplier each attack


<EN05> Conserve Engine
Gives the user a second Special usage


<EN06> Rejuvenation Engine(HP Regen)
Heals back 1/12 of the user's max HP every end of turn


<EN07> Dice Engine
User gets a random stat boost or debuff every end of turn
Effects are as follows:
-x1.2 Attack multiplier
-x1.2 Defense multiplier
-x1.2 Defense multiplier
-x0.83 Attack multiplier
-x0.83 Defense multiplier
-x0.83 Speed multiplier


<EN08> Precision Engine
Increase the chance of user landing a Critical Hit by 15%


<EN09> Damper Engine
User activates one layer of Shield at the start of the battle


<EN10> Contingency Engine
User ativates one layer of Shield when HP is below the 30% threshold (Only happens once per battle)


<EN11> Accelerator Engine
Boosts the user's Speed stat by 20% each turn


<EN12> Momentum Engine
User's attacks deal an additional set HP of damage based on 10% of the Speed stat


<EN13> Standby Engine
When an attack deals all of the user's remaining health, hangs on by 1 HP


<EN14> HailMary Engine(When below 10% HP, launches a special automatically even with no special usage left)
When the user is below 10% HP, automatically launches a Special even with no Special usage left (Only happens once per battle)


<EN15> Perpetuation Engine(The debuff it inflicts is 1 turn longer)
When the user is inflicting a debuff to the opponent (Virus, Inverse, Disabled), adds 1 turn to the total duration


<EN16> Debilitation Engine(1st Attack always stuns)
User's first attack always stuns the opponent

=========================================================================

Weapon/Equipment (Special):
<WP01> Electromagnetic Pulsar
Unleashes "E.M.P Burst", a 50 base power Special that disables the opponent's engines for 2 turns


<WP02> Malware Injector
Unleashes "Hot Singles in Your Area", a non damaging Special that inflicts a Virus to the opponent for 3 turns


<WP03> Repair Drones
Unleashes "Fixer Upper", a non damaging Special that heals the user for 50% of its max HP


<WP04> Stun Baton
Unleashes "Brutal Shock", a 50 base power Special that stuns the opponent on its next turn


<WP05> Comically Large Sword
Unleashes "Big Ass Swing", a 100 base power Special that has no secondary effect


<WP06> Light Ray
Unleashes "Flash Destruction", a 60 base power Special that bypasses through Defensive stance and breaks all Shields


<WP07> Slot Machine
Unleashes "All In", a Special that let's the slot machine decide the user's fate

Match 2 [O] : Deal a 50 base power attack
Match 3 [O] : Deal a 70 base power Critical Hit

Match 2 [^] : Multiplies the user's Attack stat by x1.1 permanently
Match 3 [^] : Multiplies the user's Attack stat by x1.4 permanently

Match 2 [*] : Inflicts the opponent with either a Virus, Disabled, or Inverse debuff for 2 turns
Match 3 [*] : Inflicts the opponent the Virus, Disabled, and Inverse debuff for 3 turns

Match 2 [X] : Does nothing
Match 3 [X] : User self destructs and loses all its HP

Match 2 [7] : Does nothing
Match 3 [7] : Opponent self destructs and loses all its HP

No matches :
- User deals a 50 base power attack to itself
- Lowers the user's Attack stat by x0.75
- Inflicts the user with either a Virus, Disabled, or Inverse debuff for 2 turns

Odds : 
[O] = 25%
[^] = 25%
[*] = 25%
[X] = 16.7%
[7] = 8.3%


<WP08> Messy Wiring
Unleashes "Safety Violations", a Special that deals damage based on the user's lost HP


<WP09> Battering Ram
Unleashes "Tank Charge", a 50 base power Special that deals damage using the user's Defense stat


<WP10> Water Gun (Inverse opponent's attack and defense stats)
Unleashes "Waterlog", a non damaging Special that swaps the opponent's Attack and Defense stats for 3 turns


<WP11> Riot Shield (Activate an amount of Shield based on defense)
Unleashes "Field of Barriers", a non damaging Special that activates a layer of Shield for every 30 points in the user's Defense stat

=========================================================================

Upgrade (Bonus Stats):
<UP01> (+5 Atk, -5 Spd)


<UP02> (+5 Def, -5 Atk)


<UP03> (+5 Atk, +5 Spd, -5 Def, -5 HP)


<UP04> (+5 HP, -5 Spd)


<UP05> (+15 HP, -5 Atk, -5 Def, -5 Spd)


<UP06> (+10 Spd, -5 Atk, -5 Def)


<UP07> (+5 HP, +5 Def, -5 Atk, -5 Spd)


<UP08> (+15 Atk, -5 HP, -5 Def, -5 Spd)


<UP09> (+5 Atk, +5 Def, -10 Spd)


<UP10> (+15 Def, -5 Atk, -5 HP, -5 Spd)
