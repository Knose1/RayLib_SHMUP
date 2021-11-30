#pragma once

class AMovable;
class APatern
{

	public:
		struct IPaternData {};
	
	virtual void SetDefault(IPaternData* data) = 0;
	virtual void DoPatern(AMovable* movable, IPaternData* data) = 0;
};

