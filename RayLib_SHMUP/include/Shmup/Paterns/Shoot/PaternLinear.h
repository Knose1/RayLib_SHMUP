#pragma once
#include "../APatern.h"
/// <summary>
/// A patern that goes in a straight line
/// </summary>
class PaternLinear :
    public APatern
{
	virtual void DoPatern(AMovable* shoot, IPaternData* data) override;
	virtual void SetDefault(IPaternData* data) override;
};

