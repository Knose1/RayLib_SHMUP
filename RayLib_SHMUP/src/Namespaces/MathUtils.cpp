#include "Namespaces/MathUtils.h"

float MathUtils::signf(float f)
{
	return signbit(f) ? -1 : 1;
}

float MathUtils::scalePolarVec2DNoChecking(float angle, Vector2 cartesianScale) 
{
	angle *= DEG2RAD;
	return atan2f(sinf(angle) * cartesianScale.y, cosf(angle) * cartesianScale.x) * RAD2DEG;
}

float MathUtils::scalePolarVec2D(float angle, Vector2 cartesianScale)
{
	if (cartesianScale.x == 0 && cartesianScale.y == 0) return INFINITY;
	
	//Theses line will transform the angle into a -180 to 180 angle
	float modulo180 = fmodf(angle, 180.0f);
	float modulo360 = fmodf(angle, 360.f);
	angle = 2*modulo180-modulo360;
	
	angle = angle * DEG2RAD;
	if		(angle >  PI / 2) angle = atanf(tan(angle) * cartesianScale.y / cartesianScale.x)+PI;
	else if (angle < -PI / 2) angle = atanf(tan(angle) * cartesianScale.y / cartesianScale.x)-PI;
	else					  angle = atanf(tan(angle) * cartesianScale.y / cartesianScale.x);	 

	return angle * RAD2DEG;
}

float MathUtils::cartesianToPolar(Vector2 cartesian)
{
	float result = atan2(cartesian.y, cartesian.x);
	result *= RAD2DEG;
	if (result < 0) result += 360.0f;
	return result;
}

Vector2 MathUtils::polarToCartesian(float polar)
{
	return {cosf(polar*DEG2RAD), sinf(polar*DEG2RAD)};
}
