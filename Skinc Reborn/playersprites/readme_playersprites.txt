Usage and creation of playersprites:

A playermodel is an image of 40x70pixels.
Each playerprite consists of a 3x3 grid of 9 playermodels.
The first row is shown when the player is moving up (the left one if he is moving left-up, the irght one if right-up and the middle one if just up)
The second row is shown if he has no ,very little or negative y-axis momentum. (the left one if he is moving left, right one of he is moving right and middle one if he is standing still)
The last row only applies to Cheating-bots: the left one is the model of the player when he goes super-saiyan, the middle one is the model while cloaked and the right one is the cloaking-aniamtion.

You can easily create these playersprites yourself or alter the existing ones.
Note: the game will not load in any additional playermodels but the existing ones.
So if you whish to use one of your own, replace an existing file and give it the same exact name.
Only the png-fileformat is supported.
If you whish to add additional playermodels you will have to alter the source-code in severl files including
GameContainer.cpp
bot/player.cpp
custom_menu.h
global_values.h
(and any other where you choose a skin)

If you whish to create a playersprite of bigger or smaller dimensions than 40x70
you will have to change playerheigth, playerwidth, botheigth and botwidth in global_values.h (in the source code).
Please look at weapon.cpp aswell to make sure the hitbox is properly adjusted for both sizes.