#pragma once
#include "raylib.h"
#include "APatern.h"

class AOffsetablePatern :
	public APatern
{

	public:
		struct IOffserablePaternData : public IPaternData
		{
			Vector2 positionOffset;
			Vector2 scaleCenter;
			Vector2 scaleOffset;
			Vector2 rotationCenter;
			float rotationOffset;
		};

	protected:
		void ComputerOffset(float& rotation, Vector2& localPosition, IOffserablePaternData data, bool scaleRotation = false);
};

