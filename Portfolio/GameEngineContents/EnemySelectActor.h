
#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class EnemySelectActor : public GameEngineActor
{
public:
	EnemySelectActor();
	~EnemySelectActor();

	EnemySelectActor(const EnemySelectActor& _Other) = delete;
	EnemySelectActor(EnemySelectActor&& _Other) noexcept = delete;
	EnemySelectActor& operator=(const EnemySelectActor& _Other) = delete;
	EnemySelectActor& operator=(EnemySelectActor&& _Other) noexcept = delete;

	void Start() override;
	void Update() override;
	void Render() override;


	inline GameEngineRenderer* GetMyRenderer()
	{
		return MyRenderer_;
	}

	inline void SetMyRenderer(GameEngineRenderer* _Renderer)
	{
		MyRenderer_ = _Renderer;
	}

protected:

private:
	GameEngineRenderer* MyRenderer_;

};
