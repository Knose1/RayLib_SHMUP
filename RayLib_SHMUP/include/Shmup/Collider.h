#pragma once
#include "raylib.h"
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

		void GetWorldPoints(Transform2D* transform, Vector2& a1, Vector2& b1, Vector2& c1, Vector2& d1)
		{
			a1 = { 0, 0 };
			b1 = { 0, 1 };
			c1 = { 1, 0 };
			d1 = { 1, 1 };

			a1 = Vector2Subtract(a1, pivot);
			b1 = Vector2Subtract(b1, pivot);
			c1 = Vector2Subtract(c1, pivot);
			d1 = Vector2Subtract(d1, pivot);

			a1 = Vector2Rotate(a1, transform->rotation);
			b1 = Vector2Rotate(b1, transform->rotation);
			c1 = Vector2Rotate(c1, transform->rotation);
			d1 = Vector2Rotate(d1, transform->rotation);

		}
		virtual EColliderType GetType() override { return EColliderType::Rect; }
};