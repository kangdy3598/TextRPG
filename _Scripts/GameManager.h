#pragma once

#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "NPC/NPC.h"

#include "Map/Map.h"
#include "Enemy/BattleField.h"
#include "Engine/Graphics.h"

enum GAME_PROCESSING
{
	RUNNING = 1,
	EXIT,
	ERROR
};

class CGameManger
{
private:
	CPlayer* m_CPlayer = nullptr;
	CEnemy* m_CEnemy = nullptr;
	CNPC* m_CNPC = nullptr;

	CMap* m_CMap = nullptr;
	CBattleField* m_CBattleField = nullptr;
	CGraphics m_CGraphics;
private:

	// 게임 초기값을 설정합니다.
	void InitGame();

	// 행동을 선택합니다.
	bool SelectAction();

	// 입장할 전투맵를 선택합니다.
	void SelectBattleMap();

	// 전투맵을 초기화 합니다.
	bool InitBattleMap(int _iSelectNum);

	// 공격을 할지, 도망을 칠지 선택합니다.
	bool SelectBattle();

	// 전투를 진행합니다.
	void ProcessBattle();


public:

	// 게임을 시작합니다.
	void StartGame();

	// 게임을 진행합니다.
	void UpdateGame();

	// 할당된 메모리를 해제합니다.
	void EndGame(); 

};