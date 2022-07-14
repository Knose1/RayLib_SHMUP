#pragma once
#include <vector>

/// <summary>
/// Contains every layers for collisions
/// </summary>
enum class CollisionLayer : int
{
	Default,
	Ennemy,
	Player,
	/// <summary>
	/// The number of layers
	/// </summary>
	COUNT
};

/// <summary>
/// Contains a table of collision (to decide which items collides with what)
/// </summary>
static class ColliderSettings
{
	public:
		/// <summary>
		/// (Readonly) The table of collision.<br/>
		/// When accessing the datas, the first index must be the minimum value and the 2nd must be the maximum.
		/// </summary>
		/// <example>
		/// <code>
		/// bool ColliderSettings::AreCollidableLayers(CollisionLayer a, CollisionLayer b)
		/// {
		///		return CollisionTable[(int)std::max(a, b)][(int)std::min(a, b)];
		/// }
		/// </code>
		/// </example>
		static const std::vector<std::vector<bool>> CollisionTable;
		/// <summary>
		/// Return true if the two layers are collidable
		/// </summary>
		static bool AreCollidableLayers(CollisionLayer a, CollisionLayer b);
};