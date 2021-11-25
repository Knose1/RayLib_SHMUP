#include "raylib.h"
#include "Namespaces/Files.h"

constexpr float PADDING = 0.5f;
Rectangle Files::GetSourceRect(const Texture2D texture, const Vector2 size, const Vector2 position)
{
	Vector2 pixelSize = { texture.width / size.x , texture.height / size.y };

	return {
		pixelSize.x * position.x + PADDING, pixelSize.y * position.y + PADDING,
		pixelSize.x - PADDING, pixelSize.y - PADDING
	};
}