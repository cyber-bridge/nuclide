typedef enumflags
{
	SPECFL_ORIGIN,
	SPECFL_VELOCITY,
	SPECFL_TARGET,
	SPECFL_MODE,
	SPECFL_FLAGS
} spectatorFlags_t;

typedef enum
{
	SPECMODE_FREE,
	SPECMODE_THIRDPERSON,
	SPECMODE_FIRSTPERSON,
	SPECMODE_OVERVIEW
} spectatorMode_t;

#ifdef SERVER
class spectator:NSEntity
#else
class spectator
#endif
{
	vector origin_net;
	vector velocity_net;
	float spec_ent; float spec_ent_net;
	float spec_flags; float spec_flags_net;
	spectatorMode_t spec_mode; spectatorMode_t spec_mode_net;

	vector spec_org;

	int sequence;

	void(void) spectator;

	virtual void(void) InputNext;
	virtual void(void) InputPrevious;
	virtual void(void) InputMode;

	virtual void(void) PreFrame;
	virtual void(void) PostFrame;

	virtual void(void) SpectatorInput;

	virtual void(void) WarpToTarget;

#ifdef SERVER
	virtual float(entity, float) SendEntity;
	virtual void(void) RunClientCommand;
#else
	virtual void(float) ReceiveEntity;
	virtual float(void) predraw;
#endif
}; 
