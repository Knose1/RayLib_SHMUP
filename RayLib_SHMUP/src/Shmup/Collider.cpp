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
	// (it - me).normalised * radius + me
	Vector2 closestPointToRect = Vector2Add(Vector2Scale(Vector2Normalize(Vector2Subtract(itT->position, meT->position)), me->radius), meT->position);

	Vector2 a1 = { it->rectangle.x,  it->rectangle.y };
	Vector2 b1 = { it->rectangle.x,  it->rectangle.y + it->rectangle.height };
	Vector2 c1 = { it->rectangle.x + it->rectangle.width, it->rectangle.y };
	Vector2 d1 = { it->rectangle.x + it->rectangle.width, it->rectangle.y + it->rectangle.height };

	a1 = Vector2Subtract(a1, it->pivot);
	b1 = Vector2Subtract(b1, it->pivot);
	c1 = Vector2Subtract(c1, it->pivot);
	d1 = Vector2Subtract(d1, it->pivot);
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
	//Local Rectangle me
	// B - - - - D
	// |         |
	// A - - - - C
	Vector2 a1 = { 0, 0};
	Vector2 b1 = { 0, 1};
	Vector2 c1 = { 1, 0};
	Vector2 d1 = { 1, 1};
	
	a1 = Vector2Subtract(a1, me->pivot);
	b1 = Vector2Subtract(b1, me->pivot);
	c1 = Vector2Subtract(c1, me->pivot);
	d1 = Vector2Subtract(d1, me->pivot);
	
	Vector2Rotate()

	a1 = Vector2Subtract(a1, me->pivot);
	b1 = Vector2Subtract(b1, me->pivot);
	c1 = Vector2Subtract(c1, me->pivot);
	d1 = Vector2Subtract(d1, me->pivot);

	//Local Rectangle it
	// B - - - - D
	// |         |
	// A - - - - C
	Vector2 a2 = { it->rectangle.x, it->rectangle.y };
	Vector2 b2 = { it->rectangle.x, it->rectangle.y + it->rectangle.height };
	Vector2 c2 = { it->rectangle.x + it->rectangle.width, it->rectangle.y };
	Vector2 d2 = { it->rectangle.x + it->rectangle.width, it->rectangle.y + it->rectangle.height };

	a2 = Vector2Subtract(a2, it->pivot);
	b2 = Vector2Subtract(b2, it->pivot);
	c2 = Vector2Subtract(c2, it->pivot);
	d2 = Vector2Subtract(d2, it->pivot);

}