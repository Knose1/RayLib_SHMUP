#pragma once
#include "Patern.h"
class PaternLinear :
    public Patern
{
	// Hérité via Patern
	virtual void DoPatern(Shoot* shoot, IPaternData* data) override;
};

