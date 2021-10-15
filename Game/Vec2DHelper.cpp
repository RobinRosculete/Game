#include "Vec2DHelper.h"
#include <cmath>


bool IsEqual(float x, float y) {
	return fabs(x - y) < EPSILON;
}

bool IsGreateThanOrEqual(float x, float y) {

	return (x > y || IsEqual(x, y));
}

bool IsLessThanOrEqual(float x, float y) {
	return (x < y || IsEqual(x, y));

}