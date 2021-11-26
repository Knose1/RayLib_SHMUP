#include "Testing/MainTesting.h"
#include "Testing/Testing.h"

#include "Namespaces/MathUtils.h"

void Testing::ExecuteTesting()
{
	Vector2 minCoordinates = { -180 * 4, -180 * 4 };
	Vector2 maxCoordinates = { 180 * 4, 180 * 4 };
	DebugCurveAxes(minCoordinates, maxCoordinates, 2, GRAY);
	DebugCurve([](float value)->float {return MathUtils::scalePolarVec2D(value, { 2,5 });        }, minCoordinates, maxCoordinates, 300, 5, RED);
	DebugCurve([](float value)->float {return MathUtils::scalePolarVec2DNonOpti(value, { 2,5 }); }, minCoordinates, maxCoordinates, 300, 2, BLUE);
}