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
public:
	CGameManger();
	~CGameManger();
private:

	CObject* m_CPlayer;
	CPlayer* m_CDownPlayer;
	CObject* m_CEnemy;

	CNPC* m_CNPC;

	CMap* m_CMap;
	
	CBattleField* m_CBattleField;
	CGraphics m_CGraphics;

	bool m_bIsDrawingMap;
private:

	// 게임 초기값을 설정합니다.
	void InitGame();

	// 부딪힌 오브젝트와 상호작용을 합니다.
	void InteractionObject(int _objectNum);

public:

	// 게임을 시작합니다.
	bool StartGame();

	// 게임을 진행합니다.
	void UpdateGame();

	// 할당된 메모리를 해제합니다.
	void EndGame(); 

};