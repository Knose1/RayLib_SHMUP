#pragma once
#include "Patern.h"

class PaternVSpread :
    public Patern
{
	// H�rit� via Patern
	virtual void DoPatern(Shoot* shoot, IPaternData* data) override;
};

