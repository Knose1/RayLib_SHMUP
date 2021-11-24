#pragma once
#include "raylib.h"
#include "Shmup/InstanceList.h"

class GraphicObject : 
	public InstanceList<GraphicObject>
{
	public:
		Vector2 position = {0,0}, scale = {0,0}, center = {0,0};
		float orientation = 0;

	protected:
		Texture2D texture;
		Rectangle source;
		Color tint = WHITE;

	public: 
		/// <summary>
		/// Called each frame to draw the object
		/// </summary>
		virtual void Draw();
		
		/// <summary>
		/// Called each frame to update the status of the object
		/// </summary>
		virtual void Update() = 0;

		explicit GraphicObject();
		~GraphicObject();

	protected:
		static void DefaultDrawMethod(
			Texture2D texture,
			Vector2 position,
			Rectangle source,
			Vector2 center,
			Vector2 scale,
			float orientation,
			Color tint
		);
};

std::vector<GraphicObject*> GraphicObject::instances;