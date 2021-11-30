#pragma once
#include "raylib.h"
#include "APatern.h"

class AOffsetablePatern :
	public APatern
{

	public:
		struct IOffserablePaternData : public IPaternData
		{
			Vector2 positionOffset = {0,0};
			Vector2 scaleCenter = {0, 0};
			Vector2 scaleOffset = {0, 0};
			Vector2 rotationCenter = {0, 0};
			float rotationOffset;
		};

	protected:
		void ComputerOffset(float& rotation, Vector2& localPosition, IOffserablePaternData data, bool scaleRotation = false);
};

