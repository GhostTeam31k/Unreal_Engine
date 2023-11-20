#include "SimpleEngine.h"
#include "Player.h"
#include "World.h"
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


class NHR
{
public:
	NHR(int NewMoney) { Money = NewMoney; }
	virtual ~NHR() {}

	int Money;

	//연산자 오버로딩
	bool operator>(const NHR& RHS) const
	{
		return this->Money > RHS.Money;
	}
	bool operator<(const NHR& RHS) const
	{
		return this->Money < RHS.Money;
	}

};

// compare []'무명함수' int~~람다함수
bool compaere(const NHR& LHS, const NHR& RHS)
{
	if (LHS.Money > RHS.Money)
	{
		return 1;
	}
	else if (LHS.Money == RHS.Money)
	{
		return true;
	}
	return false;
}


int main()
{
	vector<NHR> NHRS;

	NHRS.push_back(NHR(20));
	NHRS.push_back(NHR(110));
	NHRS.push_back(NHR(40));
	NHRS.push_back(NHR(50));
	//sort(NHRS.begin(), NHRS.end(), greater<NHR>()); // greater = 큰것부터 , less = 작은것부터 정렬
	sort(NHRS.begin(), NHRS.end(), [](const NHR& LHS, const NHR& RHS)
		{
			return LHS.Money > RHS.Money;
		});

	for (const auto& Data : NHRS)
	{
		cout << Data.Money << endl;
	}
	//cout << (NHRS[1] > NHRS[2]) << endl;

	//SimpleEngine* MyEngine = new SimpleEngine();

	//MyEngine->LoadLevel("a.smap"); 	//MyEngine->GetWorld()->SpawnActor(new APlayer(1, 1));
	//MyEngine->Run();

	//delete MyEngine;

	return 0;
}