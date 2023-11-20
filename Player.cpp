#include "Player.h"

APlayer::APlayer()
{
	Shape = 'T';
	X = 10;
	Y = 10;
}

APlayer::APlayer(int NewX, int NewY)
{
	Shape = 'T';
	SetX(NewX);
	SetY(NewY);
}

APlayer::~APlayer()
{
}

void APlayer::Tick(int KeyCode)
{
	//AActor::Tick(KeyCode);
	__super::Tick(KeyCode); //Visual Studio 전용으로 사용함. super = 부모 class를 칭함

	if (KeyCode == 'A' || KeyCode == 'a')
	{
		X--;
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		X++;
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		Y--;
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		Y++;
	}
	else
	{

	}


}
