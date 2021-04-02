#include "Function.h"
#include "GV.h"

double angle2(int mx, int my) {
	double aa;

	aa = atan2((double)my - (double)(FIELD_HEIGHT - BALL_SHOT_POS_OFFSET), (double)mx - (FIELD_WIDTH / 2));//ïœçXâ”èä

	return aa;
}