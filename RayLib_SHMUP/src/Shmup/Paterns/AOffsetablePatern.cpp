#include "Shmup/Paterns/AOffsetablePatern.h";

void AOffsetablePatern::ComputerOffset(float& rotation, Vector2& localPosition, IOffserablePaternData data, bool scaleRotation)
{
	rotation += data.rotationOffset;

}