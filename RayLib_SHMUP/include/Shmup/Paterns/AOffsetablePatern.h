#pragma once
#include "raylib.h"
#include "APatern.h"

/// <summary>
/// A patern that can have an offset (rotation, position, rotation)
/// </summary>
class AOffsetablePatern :
	public APatern
{

	public:
		/// <summary>
		/// Datas for AOffsetablePatern.
		/// </summary>
		struct IOffserablePaternData : public IPaternData
		{
			Vector2 positionOffset = {0,0};
			Vector2 scaleCenter = {0, 0};
			Vector2 scaleOffset = {0, 0};
			Vector2 rotationCenter = {0, 0};
			float rotationOffset;
		};

	protected:
		/// <summary>
		/// Compute the offset from the local rotation and position.
		/// </summary>
		/// <param name="rotation">[in;out] The rotation of the movable</param>
		/// <param name="localPosition">[in;out] The position of the movable.<br/>The world position is returned after the method has been called.</param>
		/// <param name="data">The offset datas</param>
		/// <param name="scaleRotation">If true, the rotation will be scalled using the scale offset</param>
		void ComputerOffset(float& rotation, Vector2& localPosition, IOffserablePaternData data, bool scaleRotation = false);
};

