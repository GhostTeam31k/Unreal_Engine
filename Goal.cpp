#include "Goal.h"

AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
}

AGoal::~AGoal()
{
}
