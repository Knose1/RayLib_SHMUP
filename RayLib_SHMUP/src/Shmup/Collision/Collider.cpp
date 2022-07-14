#include "Shmup/Collision/ColliderCalculation.h"
#include "Shmup/Collision/Collider.h"
#include "raymath.h"

bool ACollider::Calculation(Transform2D meT, ACollider* it, Transform2D itT)
{
	return ColliderCalculation::Calculation(this, meT, it, itT);
}

bool CircleCollider::IsPointInCollider(Transform2D meT, Vector2 point)
{
	float squareDistance = Vector2LengthSqr(Vector2Subtract(meT.position, point));

	return radius > squareDistance;
};

bool RectCollider::IsPointInCollider(Transform2D meT, Vector2 point)
{
	// B - - - - D
	// |         |
	// A - - - - C
	Vector2 a, b, c, d;
	GetWorldPoints(meT, a, b, c, d);

	//Get rect's axis on the circle
	Vector2 ab = Vector2Subtract(b, a);
	Vector2 bd = Vector2Subtract(c, a);
	
	//Let's dot
	Vector2 pa = Vector2Subtract(a, point);
	Vector2 pb = Vector2Subtract(b, point);

	float 
		left  = Vector2DotProduct(bd,pb) / width,
		right = -(left + width),
		top   = Vector2DotProduct(ab,pa) / height,
		up    = -(top + height);
	
	return
		left  < 0 &&
		right < 0 &&
		top   < 0 &&
		up    < 0;
}

/// <summary>
/// Get the points that compose the rectangle
/// </summary>
/// <param name="transform">of the collider</param>
/// <param name="a">Lower Left corner</param>
/// <param name="b">Upper Left corner</param>
/// <param name="c">Lower Right corner</param>
/// <param name="d">Upper Right corner</param>

inline void RectCollider::GetWorldPoints(Transform2D transform, Vector2& a, Vector2& b, Vector2& c, Vector2& d)
{
	//Local Rectangle
	// B - - - - D
	// |    P    |
	// A - - - - C

	a = { 0, 0 };
	b = { 0, 1 };
	c = { 1, 0 };
	d = { 1, 1 };

	a = Vector2Subtract(a, pivot);
	b = Vector2Subtract(b, pivot);
	c = Vector2Subtract(c, pivot);
	d = Vector2Subtract(d, pivot);

	a = Vector2Rotate(a, transform.rotation);
	b = Vector2Rotate(b, transform.rotation);
	c = Vector2Rotate(c, transform.rotation);
	d = Vector2Rotate(d, transform.rotation);

	Vector2 ab = Vector2Scale(Vector2Subtract(b, a), height);
	Vector2 ac = Vector2Scale(Vector2Subtract(c, a), width);

	//ac * pivot.x + ab * pivot.y
	Vector2 p = Vector2Add(Vector2Scale(ac, pivot.x), Vector2Scale(ab, pivot.y));

	a = Vector2Negate(p);                  //-p
	b = Vector2Add(ab, a);                 //ab + a
	c = Vector2Add(ac, a);                 //ac + a
	d = Vector2Add(Vector2Add(ab, ac), a); //ab + ac + a

	a = Vector2Add(a, transform.position);                  
	b = Vector2Add(b, transform.position);                 
	c = Vector2Add(c, transform.position);                 
	d = Vector2Add(d, transform.position); 
}

;