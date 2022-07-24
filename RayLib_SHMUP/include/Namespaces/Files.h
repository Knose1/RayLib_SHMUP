#pragma once
#include "raylib.h"

namespace Files
{
	constexpr auto SHIP_PATH = "./assets/kenney_pixelshmup/Tilemap/ships_packed.png";
	static Image SHIP_IMAGE;
	constexpr Vector2 SHIP_TEXTURE_SIZE = { 4,6 };

	constexpr auto TILES_PATH = "./assets/kenney_pixelshmup/Tilemap/tiles_packed.png";
	static Image TILES_IMAGE;
	constexpr Vector2 TILES_TEXTURE_SIZE = { 12,10 };

	void Init();
	Rectangle GetSourceRect(const Texture2D texture, const Vector2 size, const Vector2 position);

	Texture2D GetShipTexture();
	Texture2D GetTilesTexture();
}