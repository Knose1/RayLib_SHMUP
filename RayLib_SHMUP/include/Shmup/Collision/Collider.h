#pragma once
#include "raylib.h"
#include "Shmup/Transform2D.h"
#include "Shmup/Collision/ColliderSettings.h"

enum class EColliderType
{
	None,
	Circle,
	Rect
};

class ACollider
{
	public:
		Vector2 pivot;
		CollisionLayer layer = CollisionLayer::Default;

		explicit ACollider(Vector2 pivot, CollisionLayer layer = CollisionLayer::Default) 
		{ 
			this->pivot = pivot; 
			this->layer = layer;
		}

		virtual EColliderType GetType() { return EColliderType::None; }

		bool Calculation(Transform2D meT, ACollider* it, Transform2D itT);
		virtual bool IsPointInCollider(Transform2D tr, Vector2 point) = 0;
};

class CircleCollider : 
	public ACollider
{
	public:
		float radius;

		explicit CircleCollider(Vector2 pivot, float radius, CollisionLayer layer = CollisionLayer::Default) : ACollider(pivot, layer)
		{
			this->radius = radius;
		}

		virtual EColliderType GetType() override { return EColliderType::Circle; }
		virtual bool IsPointInCollider(Transform2D meT, Vector2 point) override;
};

class RectCollider : 
	public ACollider
{
	public:
		float width, height;

		explicit RectCollider(Vector2 pivot, float width, float height, CollisionLayer layer = CollisionLayer::Default) : ACollider(pivot, layer)
		{
			this->width  = width;
			this->height = height;
		}

		virtual EColliderType GetType() override { return EColliderType::Rect; }
		virtual bool IsPointInCollider(Transform2D meT, Vector2 point) override;
		
		/// <summary>
		/// Get the points that compose the rectangle
		/// </summary>
		/// <param name="transform">of the collider</param>
		/// <param name="a">Lower Left corner</param>
		/// <param name="b">Upper Left corner</param>
		/// <param name="c">Lower Right corner</param>
		/// <param name="d">Upper Right corner</param>
		inline void GetWorldPoints(Transform2D transform, Vector2& a, Vector2& b, Vector2& c, Vector2& d);
};