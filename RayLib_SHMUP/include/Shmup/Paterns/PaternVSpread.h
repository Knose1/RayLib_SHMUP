#pragma once
#include "Patern.h"

class PaternVSpread :
    public Patern
{
	// Hérité via Patern
	virtual void DoPatern(Shoot* shoot, IPaternData* data) override;
};

