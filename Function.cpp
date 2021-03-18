#include "Function.h"
#include "GV.h"

double angle2(int mx, int my) {
	double aa;

	aa = atan2((double)my - (double)(FIELD_HEIGHT - 16), (double)mx - (FIELD_WIDTH / 2));

	return aa;
}