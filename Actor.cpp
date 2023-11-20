#include "Actor.h"

AActor::AActor() : X(0), Y(0)
{
	//X = 0;
	//Y = 0;
}

AActor::AActor(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
}

AActor::~AActor()
{
}

void AActor::BeginPlay()
{
}

void AActor::Tick(int KeyCode)
{
}

void AActor::Render()
{
}
