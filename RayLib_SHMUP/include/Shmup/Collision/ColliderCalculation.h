#pragma once
#include "Shmup/Transform2D.h"

class ACollider;
class CircleCollider;
class RectCollider;

namespace ColliderCalculation {
	//? vs ?
	bool Calculation(ACollider* me, Transform2D meT, ACollider* it, Transform2D itT);

	//Circle vs Rect
	bool Calculation(CircleCollider* me, Transform2D meT, RectCollider* it, Transform2D itT);

	//Circle vs Circle
	bool Calculation(CircleCollider* me, Transform2D meT, CircleCollider* it, Transform2D itT);

	//Rect vs Circle
	bool Calculation(RectCollider* me, Transform2D meT, CircleCollider* it, Transform2D itT);

	//Rect vs Rect
	bool Calculation(RectCollider* me, Transform2D meT, RectCollider* it, Transform2D itT);
}