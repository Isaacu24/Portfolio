#include "Title.h"
#include "Puyo.h"
#include "BackGround.h"
#include "GameEngine/GameEngineLevel.h"

Title::Title() 
{
}

Title::~Title() 
{
}

void Title::Loading()
{
	CreateActor<Puyo>("CompanyLogo", 0);
	CreateActor<BackGround>("BackGround1", 0);
	CreateActor<BackGround>("BackGround2", 0);
	CreateActor<BackGround>("BackGround3", 0);
	CreateActor<Puyo>("GameLogo", 0);

	//CreateActor<Puyo>("Puyo", 0); //뿌요 같은 경우 해당 조건이 되면 함수를 호출해서 다시 Crate
}

void Title::Update()
{

}


