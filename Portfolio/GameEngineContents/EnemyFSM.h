#pragma once
#include <GameEngine/GameEngineActor.h>
#include "ContentsEnum.h"
#include "Puyo.h"
#include "GameEngineBase/GameEngineRandom.h"
#include <set>

class Player;
class Fire;
class HindrancePuyo;
class EnemyFSM : public GameEngineActor
{
public:
	EnemyFSM();
	~EnemyFSM();

	EnemyFSM(const EnemyFSM& _Other) = delete;
	EnemyFSM(EnemyFSM&& _Other) noexcept = delete;
	EnemyFSM& operator=(const EnemyFSM& _Other) = delete;
	EnemyFSM& operator=(EnemyFSM&& _Other) noexcept = delete;

	void Start() override;
	void Update() override;

	//NewPuyo ���� �Լ�
	void NewPuyoPair();
	void InitNextPair();
	Puyo* CreatePuyo(int _X, int _Y, PuyoColor _Color);
	void RenderToCenterPuyo();
	void RenderToLinkedPuyo();
	void ResetLinkedPuyo();

	//MovePuyo ���� �Լ�
	void GreedyPuyoMove();
	void AutoDown();
	void LandCheck();
	void OtherPuyoLandCheck();

	//PuyoCheck ���� �Լ�
	void SearchPuyo();
	void OnePuyoSearch(Puyo* _Puyo, std::vector<Puyo*>& _Out);
	bool IsOver(float4 _Index);

	//PuyoDestroy ���� �Լ�
	void DestroyPuyo();

	//PuyoLand ���� �Լ�
	void LandPuyo();

	//HindrancePuyo ���� �Լ�
	void EnemyToPlayerAttack(float4 _FromPos);
	void CreateHindrancePuyo();
	void HindrancePuyoCheck();
	void FallHindrancePuyo();

	void DigitScore(int _Score);
	void RenderToScore();

	inline void SetPlayer(Player* _Player)
	{
		Player_ = _Player;
	}

	inline EnemyState GetState()
	{
		return EnemyState_;
	}
	
protected:

private:
	Puyo* EnemyMap_[15][6];

	EnemyState EnemyState_;

	Player* Player_;

	std::vector<std::vector<Puyo*>> AllDestroyPuyo_;
	std::set<Puyo*> FindAllDestroy_;
	std::vector<HindrancePuyo*> Hindrances_;

	GameEngineRandom Random_;

	Fire* Fire_;
	float4 PlayerPoint_;

	Puyo* CenterPuyo_;
	Puyo* SecondPuyo_;
	Puyo* NextCenterPuyo_;
	Puyo* NextSecondPuyo_;
	Puyo* NextNextCenterPuyo_;
	Puyo* NextNextSecondPuyo_;

	float AutoDownTime_;
	float InputDownTime_;
	float CheckTime_;
	float LandTime_;

	unsigned int Score_;
	unsigned int ScoreDigits_[10];
	unsigned int DigitSize_;
	GameEngineRenderer* ScoreRenderers_[10];

	unsigned int Chain_;

};

