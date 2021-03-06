#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineSound.h>
#include "GameEngineBase/GameEngineRandom.h"
#include "ContentsEnum.h"

class Player;
class EnemyFSM;
class PuyoDestroyEffect;
class Puyo : public GameEngineActor
{
public:
	Puyo();
	~Puyo();

	Puyo(const Puyo& _Other) = delete;
	Puyo(Puyo&& _Other) noexcept = delete;
	Puyo& operator=(const Puyo& _Other) = delete;
	Puyo& operator=(Puyo&& _Other) noexcept = delete;

	void Start() override;
	void Update() override;

	//내부 좌표 이동 관련 처리
	inline bool GetLand()
	{
		return IsLand_;
	}

	inline void SetLand(bool _Land)
	{
		IsLand_ = _Land;
	}

	inline void SetFall(bool _Fall)
	{
		IsFall_ = _Fall;
	}

	inline bool GetFall()
	{
		return IsFall_;
	}

	inline bool GetDestroy()
	{
		return IsDestroy_;
	}

	inline float4 GetIndex()
	{
		return float4(static_cast<float>(X_), static_cast<float>(Y_));
	}

	inline int GetX()
	{
		return X_;
	}

	inline int GetY()
	{
		return Y_;
	}

	inline void SetX(int _X)
	{
		X_ = _X;
	}

	inline void SetY(int _Y)
	{
		Y_ = _Y;
	}

	void SetIndex(int _X, int _Y);
	void InitAllAnimation();
	void SetColorImage(PuyoColor _Color);

	void ChangeState(PuyoState _State);
	void ChangeHindraceState(PuyoState _State);

	void DestroyHindracePuyo(Puyo* Map[15][6]);

	void FallingPuyo();

	void Init(Player* _Player, int x, int y, PuyoColor _Color);
	void Init(EnemyFSM* _Enemy, int x, int y, PuyoColor _Color);
	void CoordinateMove(Player* _Player, int x, int y);
	void CoordinateMove(EnemyFSM* _Enemy, int x, int y);
	float4 CoordinatePos(Player* _Player, int x, int y);
	float4 CoordinatePos(EnemyFSM* _Enemy, int x, int y);

	inline GameEngineRenderer* GetMyRenderer()
	{
		return MyRenderer_;
	}

	inline void SetMyRenderer(GameEngineRenderer* _Renderer)
	{
		MyRenderer_ = _Renderer;
	}

	inline void SetColor(PuyoColor _Color)
	{
		MyColor_ = _Color;
	}

	inline PuyoColor GetColor()
	{
		return MyColor_;
	}

	inline void SetDir(PuyoDir _Dir)
	{
		CurDir_ = _Dir;
	}

	inline PuyoState GetState()
	{
		return PuyoState_;
	}

	inline bool GetIsNewPuyo()
	{
		return IsNewPuyo_;
	}

	inline void SetIsNewPuyo(bool _IsNew)
	{
		IsNewPuyo_ = _IsNew;
	}

	//이동 관련 함수
	bool LeftPuyo(Puyo* Map[15][6], Puyo* _Other);
	void JustLeftMove(Puyo* Map[15][6], Puyo* _Other);

	bool RightPuyo(Puyo* Map[15][6], Puyo* _Other);
	void JustRightMove(Puyo* Map[15][6], Puyo* _Other);

	Puyo* DownPuyo(Puyo* Map[15][6], Puyo* _Other);
	Puyo* RotatePuyo(Puyo* Map[15][6], Puyo* _Center);
	void LandPuyo(Puyo* Map[15][6], Puyo* _Other);
	void AloneFallPuyo(Puyo* Map[15][6]);
	void FallPuyo(Puyo* Map[15][6], Player* _Player);
	void FallPuyo(Puyo* Map[15][6], EnemyFSM* _Enemy);
	float4 LerpPuyo(float4 A, float4 B, float Alpha);

	//애니메이션 관련 처리
	void RenderToNormal();
	void RenderToLeft();
	void RenderToRight();
	void RenderToUp();
	void RenderToDown();

	void RenderToLeftRight();
	void RenderToLeftRightDown();
	void RenderToLefttUp();
	void RenderToLeftRightUp();
	void RenderToLeftUpDown();
	void RenderToLeftDown();

	void RenderToRightUp();
	void RenderToRightUpDown();
	void RenderToRightDown();

	void RenderToUpDown();
	void RenderToLeftRightUpDown();

	void RenderToDestroy();
	void RenderToLand();

	void RandomIdleAnimation();
	void RenderToIdle();
	void RenderToOtherIdle();

	void IdleToNomal();
	void LandToNormal();

	void SelfDestroy();

	void InitAnimation(PuyoColor color);
	void LinkedPuyoAnimtaion(Puyo* Map[15][6]);
	int GradeLinkAnimation(Puyo* Map[15][6]);

	void LoseFall();
	void TwinklePuyo();

	void DestroyEffect();

protected:

private:
	PuyoState PuyoState_;

	GameEngineRandom Random_;

	GameEngineRenderer* MyRenderer_;

	Player* Player_;
	EnemyFSM* Enemy_;

	PuyoColor MyColor_;
	PuyoDir CurDir_;

	int X_;
	int Y_;

	int OffsetX_;
	int TwinkleCount_;

	int AloneCount_;

	float4 StartPos_;
	float4 EndPos_;

	float Alpha_;
	float IdleTime_;
	float NormalTime_;
	
	bool IsNewPuyo_;
	bool IsIdle_;
	bool IsLand_;
	bool IsDestroy_;
	bool IsFall_;

	bool IsLoseFall_;
	bool IsSoundPlay_;
	bool IsEffectOn_;

	GameEngineSound PuyoSound_; //방해뿌요 낙하 사운드, 파괴 사운드

	PuyoDestroyEffect* Effect_;
};