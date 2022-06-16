#pragma once
#include "raylib.h"

namespace Files
{
	constexpr auto SHIP_TEXTURE = "./assets/kenney_pixelshmup/Tilemap/ships_packed.png";
	static Image SHIP_IMAGE = LoadImage(SHIP_TEXTURE);
	constexpr Vector2 SHIP_TEXTURE_SIZE = { 4,6 };

	constexpr auto TILES_TEXTURE = "./assets/kenney_pixelshmup/Tilemap/tiles_packed.png";
	static Image TILES_IMAGE = LoadImage(TILES_TEXTURE);
	constexpr Vector2 TILES_TEXTURE_SIZE = { 12,10 };

	Rectangle GetSourceRect(const Texture2D texture, const Vector2 size, const Vector2 position);
}