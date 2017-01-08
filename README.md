# OpenCS
Open-Source implementation of CS running on FTE QuakeWorld

# Goals
The goal of this project is to provide an open-source implementation of Counter-Strike 1.5.
Counter-Strike, being one of the most popular multiplayer games to exist, surprisingly hasn't had
a free-software implementation done until now. 

Some of the cool things you can do with this:
* Play/Host CS and CS Servers on virtually every platform. ( Main selling point )
* Customize the game to whatever extent you like.
* Create entirely new weapons!
* Create completely new and refreshing gamemodes!
* Have a guarantee to be able to play it 20 years into the future!
* Use it as a base for your own games/mods! (As long as you own the rights to the assets)

# Status
All the weapons are implemented, so are the gamemodes: Hostage Rescue (cs), Bomb Defusal (de), Assassination (as) and Escape (es).
Not all equipment is implemented and no map radar/overview is recreated.
Basically, the game is playable as long as you don't care about grenades (for now).

# Installing
1. Download the latest version of FTE QuakeWorld.
2. Download csv15full.exe and to get the cstrike folder.
3. Move both the cstrike folder and FTE QuakeWorld into a folder
4. Clone this repository into that same folder, so that opencs, default.fmf and cstrike co-exist
5. Run FTE QuakeWorld

Optional step: Copy the 'valve' folder from your Half-Life installation in order for all features to work.

# Notes
You might get away with using the cstrike folder from the Steam version of CS 1.6, or any older version
than 1.5 - but they are not supported. I will not try to recreate 1.6 or any other earlier versions specifically.
I may however add additional, optional features that will emulate behaviour of later versions of CS.

# Special Thanks
Spike - Creator of FTE QuakeWorld and FTEQCC ( http://fte.triptohell.info/ )

TWHL - Mapping Community with CS/HL entity information (  http://twhl.info )

This repository uses no content from Half-Life nor the original CS, for credits
as to who created the ORIGINAL Counter-Strike, please visit
http://web.archive.org/web/20021016230745/http://counter-strike.net/csteam.html
