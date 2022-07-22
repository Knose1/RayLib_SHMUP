#include "Shmup/Collision/ColliderCalculation.h"
#include "Shmup/Collision/Collider.h"
#include "raymath.h"

//? vs ?
bool ColliderCalculation::Calculation(ACollider* me, Transform2D meT, ACollider* it, Transform2D itT)
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

float CircleRectInternalTest(float a, float b)
{
	if (a < 0)       return a;
	else if (b > 0)  return b;
	else             return 0;
}

//Circle vs Rect
bool ColliderCalculation::Calculation(CircleCollider* me, Transform2D meT, RectCollider* it, Transform2D itT)
{
	// B - - - - D
	// |         |
	// A - - - - C
	Vector2 a, b, c, d;
	it->GetWorldPoints(itT, a, b, c, d);

	/*
#if _DEBUG
	DrawCircleLines(meT.position.x, meT.position.y, me->radius, GREEN);
	DrawLine(a.x, a.y, b.x, b.y, GREEN);
	DrawLine(b.x, b.y, d.x, d.y, GREEN);
	DrawLine(c.x, c.y, d.x, d.y, GREEN);
	DrawLine(a.x, a.y, c.x, c.y, GREEN);
#endif // _DEBUG
	*/

	//Get rect's axis on the circle
	Vector2 ab = Vector2Subtract(b, a);
	Vector2 bd = Vector2Subtract(d, b);
	Vector2 dc = Vector2Subtract(c, d);
	Vector2 ca = Vector2Subtract(a, c);

	//Let's dot
	Vector2 pa = Vector2Subtract(a, meT.position);
	Vector2 pb = Vector2Subtract(b, meT.position);
	Vector2 pc = Vector2Subtract(c, meT.position);
	Vector2 pd = Vector2Subtract(d, meT.position);

	float
		left   = Vector2DotProduct(bd, pb) / it->width,
		right  = Vector2DotProduct(ca, pc) / it->width,
		top    = Vector2DotProduct(dc, pd) / it->height,
		bottom = Vector2DotProduct(ab, pa) / it->height;

	float
		testX  = CircleRectInternalTest(-left, right ),
		testY  = CircleRectInternalTest(-top , bottom),
		radius = me->radius;

	return testX*testX + testY*testY < radius*radius;
}

//Circle vs Circle
bool ColliderCalculation::Calculation(CircleCollider* me, Transform2D meT, CircleCollider* it, Transform2D itT)
{
	float halfRadiusSum = (me->radius + it->radius);
	float squareDistance = Vector2LengthSqr(Vector2Subtract(meT.position, itT.position));

	return halfRadiusSum * halfRadiusSum > squareDistance;
}

//Rect vs Circle (redirected to Circle Collider class)
bool ColliderCalculation::Calculation(RectCollider* me, Transform2D meT, CircleCollider* it, Transform2D itT)
{
	return it->Calculation(itT, me, meT);
}

//Rect vs Rect
bool ColliderCalculation::Calculation(RectCollider* me, Transform2D meT, RectCollider* it, Transform2D itT)
{
	return false;
}