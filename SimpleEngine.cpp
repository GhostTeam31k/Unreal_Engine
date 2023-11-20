#include "SimpleEngine.h"
#include "World.h"
#include <conio.h>
#include "Player.h"
#include "Wall.h"
#include "Monster.h"
#include "Goal.h"


//**********
//*P       *
//*        *
//*        *
//*     M  *
//*        *
//*        *
//*        *
//*       G*
//**********

SimpleEngine::SimpleEngine()
{
	Init();
}

SimpleEngine::~SimpleEngine()
{
	Term();
}

void SimpleEngine::Init()
{
	IsRunning = true;
	World = new UWorld();
}

void SimpleEngine::Run()
{
	while (IsRunning)
	{
		int KeyCode = Input();
		Tick(KeyCode);
		//Clear Screen
		system("cls");
		Render();
	}
}

void SimpleEngine::Stop()
{
	IsRunning = false;
}

void SimpleEngine::Term()
{
	IsRunning = false;
	delete World;
}

void SimpleEngine::LoadLevel(std::string Filename)
{
	//Save
	//Memory -> Disk : Serialize(세로정렬), Text(JSON,csv), binary(umap)

	//Load
	//Disk -> Memory : Deserialize

	std::string Map[10] =
	{
		"*********",
		"*P      *",
		"*       *",
		"*   M   *",
		"*   M   *",
		"*   M   *",
		"* MMMMM *",
		"*       *",
		"*      G*",
		"*********"
	};

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (Map[Y][X] == '*')
			{
				//Wall
				GetWorld()->SpawnActor(new AWall(X, Y));
			}
			else if (Map[Y][X] == 'P')
			{
				//Player
				GetWorld()->SpawnActor(new APlayer(X, Y));
			}
			else if (Map[Y][X] == 'M')
			{
				//Monster
				GetWorld()->SpawnActor(new AMonster(X, Y));
			}
			else if (Map[Y][X] == 'G')
			{
				//Goal
				GetWorld()->SpawnActor(new AGoal(X, Y));
			}
		}

	}

	//GetWorld()->SpawnActor(new APlayer(10, 10));
	//GetWorld()->SpawnActor(new AWall(0, 0));
	//GetWorld()->SpawnActor(new AWall(1, 0));
	//GetWorld()->SpawnActor(new AWall(0, 1));
}

int SimpleEngine::Input()
{
	int KeyCode = _getch();

	return KeyCode;
}

void SimpleEngine::Tick(int KeyCode)
{
	GetWorld()->Tick(KeyCode);
}

void SimpleEngine::Render()
{
	GetWorld()->Render();
}

