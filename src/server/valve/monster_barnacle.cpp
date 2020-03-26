/*
 * Copyright (c) 2016-2019 Marco Hladik <marco@icculus.org>
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

/*QUAKED monster_barnacle (0 0.8 0.8) (-16 -16 -36) (16 16 0)

Barnacle

*/

enum {
	BARN_IDLE,
	BARN_IDLE2,
	BARN_IDLE3,
	BARN_FLINCH,
	BARN_ATTACK,
	BARN_CHEW,
	BARN_DEATH
};

class monster_barnacle:CBaseMonster
{
	void() monster_barnacle;
};

void monster_barnacle::monster_barnacle(void)
{
	netname = "Barnacle";
	model = "models/barnacle.mdl";
	base_mins = [-16,-16,-36];
	base_maxs = [16,16,0];
	CBaseMonster::CBaseMonster();
}