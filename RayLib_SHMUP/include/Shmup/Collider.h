#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Shmup/Transform2D.h"
enum class EColliderType
{
	None,
	Circle,
	Rect
};

class ACollider;
class CircleCollider;
class RectCollider;

namespace ColliderCalculation {
	//? vs ?
	bool Calculation(ACollider* me, Transform2D* meT, ACollider* it, Transform2D* itT);

	//Circle vs Rect
	bool Calculation(CircleCollider* me, Transform2D* meT, RectCollider* it, Transform2D* itT);

	//Circle vs Circle
	bool Calculation(CircleCollider* me, Transform2D* meT, CircleCollider* it, Transform2D* itT);

	//Rect vs Circle (redirected to Circle Collider class)
	bool Calculation(RectCollider* me, Transform2D* meT, CircleCollider* it, Transform2D* itT);

	//Rect vs Rect
	bool Calculation(RectCollider* me, Transform2D* meT, RectCollider* it, Transform2D* itT);
}

class ACollider
{
	public:
		Vector2 pivot;

		ACollider(Vector2 pivot) { this->pivot = pivot; }

		virtual EColliderType GetType() { return EColliderType::None; }

		bool Calculation(Transform2D* meT, ACollider* it, Transform2D* itT) 
		{
			return ColliderCalculation::Calculation(this, meT, it, itT);
		}
};

class CircleCollider : 
	public ACollider
{
	public:
		float radius;

		CircleCollider(Vector2 pivot, float radius) : ACollider(pivot)
		{
			this->radius = radius;
		}

		virtual EColliderType GetType() override { return EColliderType::Circle; }
};

class RectCollider : 
	public ACollider
{
	public:
		float width, height;

		RectCollider(Vector2 pivot, float width, float height) : ACollider(pivot)
		{
			this->width  = width;
			this->height = height;
		}

		virtual EColliderType GetType() override { return EColliderType::Rect; }
		
		/// <summary>
		/// Get the points that compose the rectangle
		/// </summary>
		/// <param name="transform">of the collider</param>
		/// <param name="a">Lower Left corner</param>
		/// <param name="b">Upper Left corner</param>
		/// <param name="c">Lower Right corner</param>
		/// <param name="d">Upper Right corner</param>
		void GetWorldPoints(Transform2D* transform, Vector2& a, Vector2& b, Vector2& c, Vector2& d)
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

			a = Vector2Rotate(a, transform->rotation);
			b = Vector2Rotate(b, transform->rotation);
			c = Vector2Rotate(c, transform->rotation);
			d = Vector2Rotate(d, transform->rotation);

			Vector2 ab = Vector2Scale(Vector2Subtract(b, a), height);
			Vector2 ac = Vector2Scale(Vector2Subtract(c, a), width);
			
			//ac * pivot.x + ab * pivot.y
			Vector2 p = Vector2Add( Vector2Scale(ac, pivot.x), Vector2Scale(ab, pivot.y));

			a = Vector2Negate(p);                  //-p
			b = Vector2Add(ab, a);                 //ab + a
			c = Vector2Add(ac, a);                 //ac + a
			d = Vector2Add(Vector2Add(ab, ac), a); //ab + ac + a
		}
};