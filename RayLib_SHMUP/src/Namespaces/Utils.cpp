#include <iostream>
#include "Namespaces/Utils.h"

float Utils::randMToN(float M, float N)
{
	return M + (rand() / (RAND_MAX / (N - M)));
}

float Utils::randMToN(int M, int N)
{
	float Mf = M;
	float Nf = N;
	return Mf + (rand() / (RAND_MAX / (Nf - Mf)));
}

float Utils::rand01()
{
	return rand() / (RAND_MAX + 1.);
}