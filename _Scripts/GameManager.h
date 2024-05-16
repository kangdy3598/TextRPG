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
	// ★상속성 : CPlayer와 CEnemy의 부모인 CObject로 변수를 선언한다.
	CObject* m_CPlayer = nullptr;
	CObject* m_CEnemy = nullptr;

	CNPC* m_CNPC = nullptr;

	CMap* m_CMap = nullptr;
	
	CBattleField* m_CBattleField = nullptr;
	CGraphics m_CGraphics;

	bool m_bIsDrawingMap = false;
private:

	// 게임 초기값을 설정합니다.
	void InitGame();

	void InteractionObject(int _objectNum);

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