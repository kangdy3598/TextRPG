#pragma once

#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "NPC/NPC.h"
#include "Shop/Shop.h"

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

	CObject* m_CPlayer; CObject* m_CEnemy;
	
	CShop* m_Shop;
	CNPC* m_CNPC;
	CMap* m_CMap;
	
	CBattleField* m_CBattleField;
	CGraphics m_CGraphics;

	bool m_bIsDrawingMap;
private:

	// ���� �ʱⰪ�� �����մϴ�.
	void InitGame();

	// �ε��� ������Ʈ�� ��ȣ�ۿ��� �մϴ�.
	void InteractionObject(int _objectNum);

public:

	// ������ �����մϴ�.
	bool StartGame();

	// ������ �����մϴ�.
	void UpdateGame();

	// �Ҵ�� �޸𸮸� �����մϴ�.
	void EndGame(); 

};