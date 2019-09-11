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

/*QUAKED env_shooter (1 0 0) (-8 -8 -8) (8 8 8)
"targetname"    Name
"target"        Target when triggered.
"killtarget"    Target to kill when triggered.
"angles"        Sets the pitch, yaw and roll direction of the shooter.
"shootmodel"    Model file to shoot.
"shootsounds"   PCM sample to play whenever a piece shoots out.
"m_iGibs"       Amount of models shot in total.
"m_flDelay"     Delay before being able to be fired again.
"m_flVelocity"  Speed of the models in units per second.
"m_flVariance"  Delay between shots.
"m_flGibLife"   Life of the individual model piece.
"scale"         Scale modifier of the model pieces.

Shoots model entities from its location.
*/

class env_shooter : CBaseTrigger
{
	int m_iGibs;
	int m_iGibsLeft;

	float m_flDelay;
	float m_flVelocity;
	float m_flVariance;
	float m_flGibLife;
	string m_strShootModel;
	float m_flShootSounds;
	float m_flScale;
	float m_flSkin;
	
	void() env_shooter;
	virtual void() Respawn;
	virtual void() ShootGib;
	virtual void() Trigger;
};

void env_shooter::ShootGib(void)
{
	static void Gib_Remove ( void ) { remove( self ); }

	entity eGib = spawn();
	eGib.movetype = MOVETYPE_BOUNCE;
	setmodel(eGib, m_strShootModel);
	setorigin(eGib, origin);

	makevectors(angles);
	eGib.velocity = v_forward * m_flVelocity + [0,0,64 + (random()*64)];
	eGib.avelocity[0] = Math_CRandom() * 32;
	eGib.avelocity[1] = Math_CRandom() * 32;
	eGib.avelocity[2] = Math_CRandom() * 32;

	eGib.think = Gib_Remove;
	eGib.nextthink = time + m_flGibLife;
	eGib.angles = angles;

	m_iGibsLeft--;

	if (m_iGibsLeft) {
		nextthink = time + m_flVariance;
	}
}

void env_shooter :: Trigger ( void )
{
	think = ShootGib;
	nextthink = time + m_flVariance;
}

void env_shooter :: Respawn ( void )
{
	m_iGibsLeft = m_iGibs;
}

void env_shooter :: env_shooter ( void )
{
	for ( int i = 1; i < ( tokenize( __fullspawndata ) - 1 ); i += 2 ) {
		switch ( argv( i ) ) {
		case "m_iGibs":
			m_iGibs = stoi( argv( i + 1 ) );
			break;
		case "m_flDelay":
			m_flDelay = stof( argv( i + 1 ) );
			break;
		case "m_flVelocity":
			m_flVelocity = stof( argv( i + 1 ) );
			break;
		case "m_flVariance":
			m_flVariance = stof( argv( i + 1 ) );
			break;
		case "m_flGibLife":
			m_flGibLife = stof( argv( i + 1 ) );
			break;
		case "shootmodel":
			m_strShootModel = argv( i + 1 );
			break;
		case "shootsounds":
			m_flShootSounds = stof( argv( i + 1 ) );
			break;
		case "scale":
			m_flScale = stof( argv( i + 1 ) );
			break;
		case "skin":
			m_flSkin = stof( argv( i + 1 ) );
			break;
		default:
			break;
		}
	}
	
	precache_model( m_strShootModel );
	CBaseTrigger::CBaseTrigger();
	env_shooter::Respawn();
}