#pragma once
#include<cstdlib>


static int generateClampedRandom(int min, int max) {
	int result = min + rand() % ((max + 1) - 1);
	return result;
}