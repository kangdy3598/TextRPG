#pragma once
#include "Enemy.h"

class CBattleField
{
private:
	CEnemy* m_CEnemy = nullptr;

	POSITION m_Position = POSITION(24, 12);

public:

	// 현재 전투맵 위치를 설정 합니다.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// 현재 전투맵 위치를 불러옵니다.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// OBJECT : 전투맵 의 상호작용을 실행합니다.
	void InteractAction();

private:
	
	// 입장할 전투맵를 선택합니다.
	void SelectBattleMap();

	// 전투맵을 초기화 합니다.
	bool InitBattleMap(int _iSelectNum);

	// 공격을 할지, 도망을 칠지 선택합니다.
	bool SelectBattle();

	// 전투를 진행합니다.
	void ProcessBattle();
};

