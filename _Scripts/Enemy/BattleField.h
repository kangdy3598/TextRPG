#pragma once
#include "Enemy.h"
#include "../Player/Player.h"

class CBattleField
{
private:
	CEnemy* m_CEnemy = nullptr;

	POSITION m_Position = POSITION(24, 12);

public:

	// ���� ������ ��ġ�� ���� �մϴ�.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// ���� ������ ��ġ�� �ҷ��ɴϴ�.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// OBJECT : ������ �� ��ȣ�ۿ��� �����մϴ�.
	int InteractAction(int _iSelectNum, CPlayer* _CPlayer);

	
private:
	
	// ������ �����ʸ� �����մϴ�.
	int SelectBattleMap();

	// �������� �ʱ�ȭ �մϴ�.
	bool InitBattleMap(int _iSelectNum);

	// ���� �޴��� �����մϴ�.
	bool SelectBattleMenu(int _battleFieldNum, CPlayer* _CPlayer);

	// ������ �����մϴ�.
	bool ProcessBattle(CPlayer* _CPlayer);
};

