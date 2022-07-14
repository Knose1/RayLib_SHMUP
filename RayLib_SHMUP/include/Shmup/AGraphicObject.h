#pragma once
#include "raylib.h"
#include "Shmup/InstanceList.h"
#include "Shmup/Transform2D.h"

/// <summary>
/// An object that can be drawn and updated
/// </summary>
class AGraphicObject : 
	public InstanceList<AGraphicObject>
{
	public:
		Vector2 
			/// <summary>
			/// The position of the object
			/// </summary>
			position = {0,0},
			/// <summary>
			/// The scale of the visual
			/// </summary>
			scale = {0,0},
			/// <summary>
			/// The pivot for the rotation
			/// </summary>
			center = {0,0};
		/// <summary>
		/// The rotation of the visual
		/// </summary>
		float orientation = 0;

	protected:
		/// <summary>
		/// The texture for the rendering
		/// </summary>
		Texture2D texture;
		/// <summary>
		/// The source rectangle on the texture
		/// </summary>
		Rectangle source;
		/// <summary>
		/// The tint of the texture
		/// </summary>
		Color tint = WHITE;

	public: 
		/// <summary>
		/// Called every frame to draw the object
		/// </summary>
		virtual void Draw();
		
		/// <summary>
		/// Called every frame to update the status of the object
		/// </summary>
		virtual void Update()=0;

		/// <summary>
		/// Get a transform2D object from the object
		/// </summary>
		Transform2D GetTransform() {
			return 
			{ 
				position,
				orientation,
				scale
			};
		};

		explicit AGraphicObject();
		virtual ~AGraphicObject();

	protected:
		/// <summary>
		/// The default way of drawing an object
		/// </summary>
		/// <param name="texture">The texture to draw</param>
		/// <param name="position">The position of the object</param>
		/// <param name="source">The source rectangle on the texture</param>
		/// <param name="center">The pivot for the rotation</param>
		/// <param name="scale">The scale of the texture</param>
		/// <param name="orientation">The orientation of the texture</param>
		/// <param name="tint">The tint of the texture</param>
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