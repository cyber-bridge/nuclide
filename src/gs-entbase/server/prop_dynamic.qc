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

/*QUAKED prop_dynamic (0 0.2 1) (-8 -8 -8) (8 8 8) SF_BASIC_COL
Client-side decorative model entity.

-------- KEYS --------
"model" : Model file that will be displayed by the entity.
"modelscale" : Scale modifier of the model. Default is "1".
"angles" : Sets the pitch, yaw and roll angles of the model.
"_cs" : Toggles if the prop casts a shadow or not.

-------- TRIVIA --------
This entity was introduced in Half-Life 2 (2004).
*/

class prop_dynamic:NSSurfacePropEntity
{
	void(void) prop_dynamic;

	virtual void(void) Respawn;
};

void
prop_dynamic::Respawn(void)
{
	super::Respawn();
	SetModel(GetSpawnModel());
	SetSolid(SOLID_CORPSE);
}

void
prop_dynamic::prop_dynamic(void)
{
	super::NSSurfacePropEntity();
}
