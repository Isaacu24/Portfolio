#pragma once
#include "ContentsEnum.h"
#include "InGameActor.h"
#include "GameEngineBase/GameEngineRandom.h"
#include <GameEngineBase/GameEngineSound.h>
#include <set>

class InGame;
class Puyo;
class EnemyFSM;
class Fire;
class Offset;
class OffsetStar;
class WarningPuyo;
class Player : public GameEngineActor
{
	friend Puyo;

public:
	Player();
	~Player();

	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void OffsetEffect();

	//NewPuyo 관련 함수
	void NewPuyoPair();
	void InitNextPair();
	Puyo* CreatePuyo(int _X, int _Y, PuyoColor _Color);
	void RenderToCenterPuyo();
	
	//MovePuyo 관련 함수
	void InputPuyoMove();
	void AutoDown();
	void InputDown();
	void LandCheck();
	void OtherPuyoLandCheck();

	//PuyoCheck 관련 함수
	void SearchPuyo();
	void OnePuyoSearch(Puyo* _Puyo, std::vector<Puyo*>& _Out);
	bool IsOver(float4 _Index);
	//PuyoDestroy 관련 함수
	void DestroyPuyo();

	//PuyoLand 관련 함수
	void LandPuyo();

	//HindrancePuyo 관련 함수
	void PlayerToEnemyAttack(float4 _FromPos);
	void CreateHindrancePuyo(int _Count);
	void HindrancePuyoCheck();
	void FallHindrancePuyo();
	void AddWarningPuyo(int _Count);
	void PopWarningPuyo();
	void CountPopWarningPuyo(int _Count);
	void DivisionWarningPuyo();

	//스코어 관련 함수
	void ScoreInit();
	void DigitScore(int _Score);
	void RenderToScore();

	void DangerCheck();
	void LoseFallPuyo();

	//휴식 관련 함수
	void BehindPlayer();
	void FrontPlayer();
	void BehindPuyo();
	void FrontPuyo();

	void DestroyPlayer();


	void Win();
	void Lose();

	inline void SetEnemyFSM(EnemyFSM* _Enemy)
	{
		Enemy_ = _Enemy;
	}

	inline PlayerState GetCurrentState()
	{
		return PlayerState_;
	}

	inline void SetCurrentState(PlayerState _PlayerState)
	{
		PlayerState_ = _PlayerState;
	}

	inline PlayerState GetPrevState()
	{
		return PrevState_;
	}

	inline void SetPrevState(PlayerState _PrevState)
	{
		PrevState_ = _PrevState;
	}

	inline int GetRandomInt(int _At, int _Untill)
	{
		int Value = Random_.RandomInt(_At, _Untill);
		return Value;
	}

	inline float GetRandomFloat(float _At, float _Untill)
	{
		float Value = Random_.RandomFloat(_At, _Untill);
		return Value;
	}

	inline bool GetDanger()
	{
		return IsDanger_;
	}

	inline void SetExp(int _Value)
	{
		Exp_ = _Value;
	}

	inline void SetNext(int _Value)
	{
		Next_ = _Value;
	}

	inline void SetRest(int _Value)
	{
		Rest_ = _Value;
	}

	inline int GetExp()
	{
		return Exp_;
	}

	inline int GetNext()
	{
		return Next_;
	}

	inline int GetRest()
	{
		return Rest_;
	}

	inline int GetScore()
	{
		return Score_;
	}

	inline void SetScore(int _Score)
	{
		Score_ = _Score;
	}

	inline void PlusScore(int _Score)
	{
		Score_ += _Score;
	}

protected:
	void Start() override;
	void Update() override;

private:
	Puyo* PlayerMap_[15][6];

	PlayerState PrevState_;
	PlayerState PlayerState_;

	EnemyFSM* Enemy_;

	GameEngineRenderer* Name_;

	InGame* InGameLevel_;
	bool IsStart_;

	std::vector<std::vector<Puyo*>> AllDestroyPuyo_;
	std::set<Puyo*> FindAllDestroy_;

	std::vector<Puyo*> Hindrances_;
	std::vector<WarningPuyo*> WarningPuyos_;

	GameEngineRandom Random_;

	Fire* Fire_;
	float4 EnemeyPoint_;

	Puyo* CenterPuyo_;
	Puyo* SecondPuyo_;
	Puyo* NextCenterPuyo_;
	Puyo* NextSecondPuyo_;
	Puyo* NextNextCenterPuyo_;
	Puyo* NextNextSecondPuyo_;

	float AutoDownTime_;
	float InputDownTime_;
	float InputDownAcc_;
	float CheckTime_;
	float LandTime_;

	unsigned int Score_;
	unsigned int ScoreDigits_[10];
	unsigned int DigitSize_;
	GameEngineRenderer* ScoreRenderers_[10];

	unsigned int Chain_;

	GameEngineSound PlayerSound_;
	GameEngineSound EffectSound_;

	bool IsStartPuyoOn_;
	bool IsDanger_;
	bool IsWinPlay_;
	bool IsLosePlay_;

	int Exp_;
	int Next_;
	int Rest_;
};

