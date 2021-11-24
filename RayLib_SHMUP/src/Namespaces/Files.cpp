#include "raylib.h"
#include "Namespaces/Files.h"

Rectangle GetSourceRect(Texture2D texture, const Vector2 size, const Vector2 position)
{
	Vector2 pixelSize = { texture.width / size.x , texture.height / size.y };

	return {
		pixelSize.x * position.x, pixelSize.y * position.y,
		pixelSize.x * (position.x + 1), pixelSize.y * (position.y + 1)
	};
}