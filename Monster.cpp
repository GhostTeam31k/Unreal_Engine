#include "Monster.h"

AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Shape = 'M';
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
}


AMonster::~AMonster()
{
}
