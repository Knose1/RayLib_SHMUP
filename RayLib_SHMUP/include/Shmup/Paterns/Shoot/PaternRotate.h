#pragma once
#include "../APatern.h"
/// <summary>
/// 
/// </summary>
class PaternRotate :
    public APatern
{
	virtual void DoPatern(AMovable* shoot, IPaternData* data) override;
	virtual void SetDefault(IPaternData* data) override;
};

