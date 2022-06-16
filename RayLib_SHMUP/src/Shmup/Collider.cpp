#include "Shmup/Collider.h"
#include "raymath.h"

//? vs ?
bool ColliderCalculation::Calculation(ACollider* me, Transform2D* meT, ACollider* it, Transform2D* itT)
{
	switch (me->GetType())
	{
		case EColliderType::Circle:
		{
			CircleCollider* castedMe = static_cast<CircleCollider*>(me);
			switch (it->GetType())
			{
				case EColliderType::Circle: return Calculation(castedMe, meT, static_cast<CircleCollider*>(it), itT);
				case EColliderType::Rect:   return Calculation(castedMe, meT, static_cast<RectCollider*>(it), itT);
				default: return false;
			}
		}
		case EColliderType::Rect:
		{
			RectCollider* castedMe = static_cast<RectCollider*>(me);
			switch (it->GetType())
			{
				case EColliderType::Circle: return Calculation(castedMe, meT, static_cast<CircleCollider*>(it), itT);
				case EColliderType::Rect:   return Calculation(castedMe, meT, static_cast<RectCollider*>(it), itT);
				default: return false;
			}
		}
		default:
			return false;
	}
}

//Circle vs Rect
bool ColliderCalculation::Calculation(CircleCollider* me, Transform2D* meT, RectCollider* it, Transform2D* itT)
{
	// Point on the circle oriented toward the center of the rec.
	// 
	// (it - me).normalised * radius + me
	Vector2 closestPointToRect = Vector2Add(Vector2Scale(Vector2Normalize(Vector2Subtract(itT->position, meT->position)), me->radius), meT->position);

	return false;
}

//Circle vs Circle
bool ColliderCalculation::Calculation(CircleCollider* me, Transform2D* meT, CircleCollider* it, Transform2D* itT)
{
	float halfRadiusSum = (me->radius + it->radius);
	float squareDistance = Vector2LengthSqr(Vector2Subtract(meT->position, itT->position));

	return halfRadiusSum * halfRadiusSum > squareDistance;
}

//Rect vs Circle (redirected to Circle Collider class)
bool ColliderCalculation::Calculation(RectCollider* me, Transform2D* meT, CircleCollider* it, Transform2D* itT)
{
	return it->Calculation(itT, me, meT);
}

//Rect vs Rect
bool ColliderCalculation::Calculation(RectCollider* me, Transform2D* meT, RectCollider* it, Transform2D* itT)
{
	return true;
}