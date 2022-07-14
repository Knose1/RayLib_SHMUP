#pragma once
#include "../APatern.h"

/// <summary>
/// A bullet patern that spreads in a V shape
/// </summary>
class PaternVSpread :
    public APatern
{
	virtual void DoPatern(AMovable* shoot, IPaternData* data) override;
	virtual void SetDefault(IPaternData* data) override;
};

