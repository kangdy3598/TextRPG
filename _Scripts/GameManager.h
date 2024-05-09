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

	// ���� �ʱⰪ�� �����մϴ�.
	void InitGame();

	// �ൿ�� �����մϴ�.
	bool SelectAction();

	// ������ �����ʸ� �����մϴ�.
	void SelectBattleMap();

	// �������� �ʱ�ȭ �մϴ�.
	bool InitBattleMap(int _iSelectNum);

	// ������ ����, ������ ĥ�� �����մϴ�.
	bool SelectBattle();

	// ������ �����մϴ�.
	void ProcessBattle();


public:

	// ������ �����մϴ�.
	void StartGame();

	// ������ �����մϴ�.
	void UpdateGame();

	// �Ҵ�� �޸𸮸� �����մϴ�.
	void EndGame(); 

};