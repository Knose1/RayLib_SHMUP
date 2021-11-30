#include <iostream>
#include "Namespaces/Random.h"

float Random::randMToN(float M, float N)
{
	return M + (rand() / (RAND_MAX / (N - M)));
}

float Random::randMToN(int M, int N)
{
	float Mf = (float)M;
	float Nf = (float)N;
	return Mf + (rand() / (RAND_MAX / (Nf - Mf)));
}

float Random::rand01()
{
	return rand() / (RAND_MAX + 1.);
}