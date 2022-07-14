#pragma once
#include "raylib.h"
#include "Shmup/Transform2D.h"
#include "Shmup/Collision/ColliderSettings.h"

/// <summary>
/// The type of collider (used for calculation's switch)
/// </summary>
enum class EColliderType
{
	None,
	Circle,
	Rect
};

/// <summary>
/// Contains collider's data the without the transform
/// </summary>
class ACollider
{
	public:
		/// <summary>
		/// The pivot for transformations
		/// </summary>
		Vector2 pivot;
		/// <summary>
		/// The layer of the collision.<br/>
		/// If want to modify the layer in runtime, don't forget to unregister your collidable before modifying the layer.
		/// </summary>
		CollisionLayer layer = CollisionLayer::Default;
		
		/// <param name="pivot">The pivot for transformations</param>
		/// <param name="layer"> The layer of the collision. </param>
		explicit ACollider(Vector2 pivot, CollisionLayer layer = CollisionLayer::Default) 
		{ 
			this->pivot = pivot; 
			this->layer = layer;
		}

		/// <summary>
		/// Get the type of collider
		/// </summary>
		virtual EColliderType GetType() { return EColliderType::None; }

		/// <summary>
		/// Test if 2 colliders are colliding
		/// </summary>
		/// <param name="meT">My transform</param>
		/// <param name="it">The other collider</param>
		/// <param name="itT">The other transform</param>
		/// <returns>True if the colliders are colliding</returns>
		bool Calculation(Transform2D meT, ACollider* it, Transform2D itT);
		/// <summary>
		/// Test if a point is in the collider
		/// </summary>
		/// <param name="tr">The transform of the collider</param>
		/// <param name="point">The point to test</param>
		/// <returns>True if the point is in the collider</returns>
		virtual bool IsPointInCollider(Transform2D tr, Vector2 point) = 0;
};

/// <summary>
/// A round collider
/// </summary>
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

/// <summary>
/// A rectangular collider
/// </summary>
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