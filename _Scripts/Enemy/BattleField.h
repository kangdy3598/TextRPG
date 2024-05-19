#pragma once
#include "Enemy.h"
#include "../Player/Player.h"

class CBattleField
{
private:
	CObject* m_CEnemy = nullptr;

	POSITION m_Position;

public:
	CBattleField() { m_Position = POSITION(24, 2); }
	~CBattleField() {}

	// 현재 전투맵 위치를 설정 합니다.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// 현재 전투맵 위치를 불러옵니다.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// OBJECT : 전투맵 의 상호작용을 실행합니다.
	int InteractAction(int _iSelectNum, CPlayer* _CPlayer);

	
private:
	
	// 입장할 전투맵를 선택합니다.
	//int SelectBattleMap();

	// 전투맵을 초기화 합니다.
	//bool InitBattleMap(int _iSelectNum);

	// 전투 메뉴를 선택합니다.
	bool SelectBattleMenu(int _battleFieldNum, CPlayer* _CPlayer);

	// 전투를 진행합니다.
	bool ProcessBattle(CPlayer* _CPlayer);
};

