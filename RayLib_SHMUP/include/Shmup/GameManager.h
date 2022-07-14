#pragma once
/// <summary>
/// Expose game related methods to be called by the main class
/// </summary>
class GameManager
{
	public:
		/// <summary>
		/// Called before after the creation of the window
		/// </summary>
		static void Init();
		/// <summary>
		/// Called at start of the frame loop to destroy the objects marked for delete
		/// </summary>
		const static void DeleteLoop() {};
		/// <summary>
		/// Called after DeleteLoop. Show the visual of the objects
		/// </summary>
		const static void Render();
		/// <summary>
		/// Called after render. Update the status of the objects
		/// </summary>
		const static void Update();
		/// <summary>
		/// Called at the end to test the collision between objects
		/// </summary>
		const static void TestCollisions();
};

