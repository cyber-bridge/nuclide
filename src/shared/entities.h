/*
 * Copyright (c) 2016-2020 Marco Hladik <marco@icculus.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* entity update identifiers */
enum
{
	ENT_NONE,
	ENT_ENTITY,
	ENT_MONSTER,
	ENT_PLAYER,
	ENT_SPECTATOR,
	ENT_AMBIENTSOUND,
	ENT_DLIGHT,
	ENT_PROJECTEDTEXTURE,
	ENT_ENVLASER,
	ENT_PARTSYSTEM,
	ENT_SPRITE,
	ENT_SPRAY,
	ENT_DECAL,
	ENT_OLDCAMERA,
	ENT_MONITOR,
	ENT_VEHICLE,
	ENT_VEH_TANKMORTAR,
	ENT_VEH_4WHEEL,
	ENT_SEPARATOR,
};

/* entity update flags */
enumflags
{
	NPC_MODELINDEX,
	NPC_ORIGIN_X,
	NPC_ORIGIN_Y,
	NPC_ORIGIN_Z,
	NPC_ANGLES_X,
	NPC_ANGLES_Y,
	NPC_ANGLES_Z,
	NPC_VELOCITY_X,
	NPC_VELOCITY_Y,
	NPC_VELOCITY_Z,
	NPC_FRAME,
	NPC_SKIN,
	NPC_BODY
};
