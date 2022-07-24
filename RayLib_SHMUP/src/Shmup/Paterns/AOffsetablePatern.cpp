#include "raylib.h";
#include "raymath.h";
#include "Namespaces/MathUtils.h";
#include "Shmup/Paterns/AOffsetablePatern.h";

void AOffsetablePatern::ComputerOffset(float& rotation, Vector2& localPosition, IOffserablePaternData data, bool scaleRotation)
{
	rotation += data.rotationOffset;
	localPosition = Vector2Add(Vector2Rotate(Vector2Subtract(localPosition, data.rotationCenter), data.rotationOffset), data.rotationCenter);
	localPosition = Vector2Add(Vector2Multiply(Vector2Subtract(localPosition, data.scaleCenter), data.scaleOffset), data.scaleCenter);

	if (scaleRotation) rotation = MathUtils::cartesianToPolar(Vector2Multiply(MathUtils::polarToCartesian(rotation), data.scaleOffset));

	//end
	localPosition = Vector2Add(localPosition, data.positionOffset);
}