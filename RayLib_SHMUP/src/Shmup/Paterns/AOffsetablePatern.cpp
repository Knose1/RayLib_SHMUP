#include "raylib.h";
#include "raymath.h";
#include "Namespaces/MathUtils.h";
#include "Shmup/Paterns/AOffsetablePatern.h";

void AOffsetablePatern::ComputerOffset(float& rotation, Vector2& localPosition, IOffserablePaternData data, bool scaleRotation)
{
	rotation += data.rotationOffset;

	//MathUtils::scalePolarVec2D();

	//end
	localPosition = Vector2Add(localPosition, data.positionOffset);
}