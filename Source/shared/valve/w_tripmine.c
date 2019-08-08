/***
*
*	Copyright (c) 2016-2019 Marco 'eukara' Hladik. All rights reserved.
*
*	See the file LICENSE attached with the sources for usage details.
*
****/

enum
{
	TRIPMINE_IDLE1,
	TRIPMINE_IDLE2,
	TRIPMINE_FIRE1,
	TRIPMINE_FIRE2,
	TRIPMINE_FIDGET,
	TRIPMINE_HOLSTER,
	TRIPMINE_DRAW,
	TRIPMINE_WORLD,
	TRIPMINE_GROUND,
};

void w_tripmine_precache(void)
{
	precache_model("models/v_tripmine.mdl");
	precache_model("models/p_tripmine.mdl");
}
string w_tripmine_vmodel(void)
{
	return "models/v_tripmine.mdl";
}
string w_tripmine_wmodel(void)
{
	return "models/v_tripmine.mdl";
}
string w_tripmine_pmodel(void)
{
	return "models/p_tripmine.mdl";
}
string w_tripmine_deathmsg(void)
{
	return "";
}

void w_tripmine_draw(void)
{
#ifdef CSQC
	Weapons_ViewAnimation(TRIPMINE_DRAW);
#else
	player pl = (player)self;
	Weapons_UpdateAmmo(pl, __NULL__, pl.ammo_tripmine, __NULL__);
#endif
}
void w_tripmine_holster(void)
{
	
}
void w_tripmine_primary(void)
{
	player pl = (player)self;
	if (pl.w_attack_next > 0.0) {
		return;
	}

	
	Weapons_MakeVectors();
	traceline(Weapons_GetCameraPos(), Weapons_GetCameraPos() + v_forward * 64, FALSE, pl);

	if (trace_fraction == 1.0f) {
		return;
	}
	
#ifdef CSQC
	Weapons_ViewAnimation(TRIPMINE_FIRE2);
#else
	entity mine = spawn();
	setmodel(mine, "models/v_tripmine.mdl");
	setorigin(mine, trace_endpos);
	mine.frame = TRIPMINE_WORLD;
	vector norm = trace_plane_normal;
   	norm_x = 0 - norm_x;
   	norm_y = 0 - norm_y;
	
   	mine.angles = vectoangles( [0,0,0.5] - norm );
   	setorigin(mine, trace_endpos - (v_forward * 4));
#endif

	pl.w_attack_next = 0.5f;
	pl.w_idle_next = 2.5f;
}
void w_tripmine_secondary(void)
{
	
}
void w_tripmine_reload(void)
{
	
}
void w_tripmine_release(void)
{
	int r;
	player pl = (player)self;
	if (pl.w_idle_next > 0.0) {
		return;
	}

	r = floor(random(0,3));

	switch (r) {
	case 0:
		Weapons_ViewAnimation(TRIPMINE_IDLE1);
		pl.w_idle_next = 3.0f;
		break;
	case 1:
		Weapons_ViewAnimation(TRIPMINE_IDLE2);
		pl.w_idle_next = 2.0f;
		break;
	default:
		Weapons_ViewAnimation(TRIPMINE_FIDGET);
		pl.w_idle_next = 3.333333f;
		break;
	}
}

float w_tripmine_aimanim(void)
{
#ifdef SSQC
	return self.flags & FL_CROUCHING ? ANIM_CR_AIMTRIPMINE : ANIM_AIMTRIPMINE;
#endif
}

void w_tripmine_hudpic(int s, vector pos)
{
#ifdef CSQC
	if (s) {
		drawsubpic(pos, [170,45], "sprites/640hud6.spr_0.tga", [0,90/256], [170/256,45/256], g_hud_color, 1, DRAWFLAG_ADDITIVE);
	} else {
		drawsubpic(pos, [170,45], "sprites/640hud3.spr_0.tga", [0,90/256], [170/256,45/256], g_hud_color, 1, DRAWFLAG_ADDITIVE);
	}
#endif
}

weapon_t w_tripmine =
{
	ITEM_TRIPMINE,
	4,
	2,
	w_tripmine_draw,
	w_tripmine_holster,
	w_tripmine_primary,
	w_tripmine_secondary,
	w_tripmine_reload,
	w_tripmine_release,
	__NULL__,
	w_tripmine_precache,
	__NULL__,
	w_tripmine_vmodel,
	w_tripmine_wmodel,
	w_tripmine_pmodel,
	w_tripmine_deathmsg,
	w_tripmine_aimanim,
	w_tripmine_hudpic
};

#ifdef SSQC
void weapon_tripmine(void) {
	Weapons_InitItem(WEAPON_TRIPMINE);
}
#endif
