#pragma once


class Shoot;
class Patern
{

	public:
		struct IPaternData {};
	
	virtual void SetDefault(Shoot* shoot) = 0;
	virtual void DoPatern(Shoot* shoot, IPaternData* data) = 0;
};

