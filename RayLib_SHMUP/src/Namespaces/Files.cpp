#include "raylib.h"
#include "Namespaces/Files.h"

constexpr float PADDING = 0.30f;

void Files::Init()
{
	SHIP_IMAGE = LoadImage(SHIP_PATH);
	TILES_IMAGE = LoadImage(TILES_PATH);
}

Rectangle Files::GetSourceRect(const Texture2D texture, const Vector2 size, const Vector2 position)
{
	Vector2 pixelSize = { texture.width / size.x , texture.height / size.y };

	return {
		pixelSize.x * position.x + PADDING, pixelSize.y * position.y + PADDING,
		pixelSize.x - PADDING*2, pixelSize.y - PADDING*2
	};
}

Texture2D Files::GetShipTexture() { return LoadTextureFromImage(SHIP_IMAGE); }

Texture2D Files::GetTilesTexture() { return LoadTextureFromImage(TILES_IMAGE); }
