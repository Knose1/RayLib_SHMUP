#pragma once
#include "Patern.h"

class PaternVSpread :
    public Patern
{
	// Hérité via Patern
	virtual void DoPatern(Shoot* shoot, IPaternData* data) override;

	// Inherited via Patern
	virtual void SetDefault(Shoot* shoot) override;
};

