#pragma once
#include "../APatern.h"

class PaternVSpread :
    public APatern
{
	// H�rit� via Patern
	virtual void DoPatern(AMovable* shoot, IPaternData* data) override;

	// Inherited via Patern
	virtual void SetDefault(AMovable* shoot) override;
};

