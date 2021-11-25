#pragma once

class AMovable;
class Patern
{

	public:
		struct IPaternData {};
	
	virtual void SetDefault(AMovable* shoot) = 0;
	virtual void DoPatern(AMovable* shoot, IPaternData* data) = 0;
};

