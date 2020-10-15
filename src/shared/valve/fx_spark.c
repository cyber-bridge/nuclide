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

#ifdef CLIENT
var float PARTICLE_SPARK;

void
FX_Spark_Init(void)
{
	precache_sound("buttons/spark1.wav");
	precache_sound("buttons/spark2.wav");
	precache_sound("buttons/spark3.wav");
	precache_sound("buttons/spark4.wav");
	precache_sound("buttons/spark5.wav");
	precache_sound("buttons/spark6.wav");
	PARTICLE_SPARK = particleeffectnum("fx_spark.effect");
}
#endif

void
FX_Spark(vector pos, vector ang)
{
#ifdef SERVER
	WriteByte(MSG_MULTICAST, SVC_CGAMEPACKET);
	WriteByte(MSG_MULTICAST, EV_SPARK);
	WriteCoord(MSG_MULTICAST, pos[0]);
	WriteCoord(MSG_MULTICAST, pos[1]);
	WriteCoord(MSG_MULTICAST, pos[2]);
	WriteCoord(MSG_MULTICAST, ang[0]);
	WriteCoord(MSG_MULTICAST, ang[1]);
	WriteCoord(MSG_MULTICAST, ang[2]);
	msg_entity = self;
	multicast(pos, MULTICAST_PVS);
#else
	pointparticles(PARTICLE_SPARK, pos, ang, 1);
	pointsound(pos, sprintf("buttons/spark%d.wav", floor(random() * 6) + 1), 1, ATTN_STATIC);
#endif
} 
