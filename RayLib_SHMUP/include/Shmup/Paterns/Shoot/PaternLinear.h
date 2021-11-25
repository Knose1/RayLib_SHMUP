#pragma once
#include "../Patern.h"
class PaternLinear :
    public Patern
{
	// Hérité via Patern
	virtual void DoPatern(AMovable* shoot, IPaternData* data) override;

	// Inherited via Patern
	virtual void SetDefault(AMovable* shoot) override;
};

