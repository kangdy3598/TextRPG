#pragma once
#include "Enemy.h"

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
	void InteractAction();

private:
	
	// ������ �����ʸ� �����մϴ�.
	void SelectBattleMap();

	// �������� �ʱ�ȭ �մϴ�.
	bool InitBattleMap(int _iSelectNum);

	// ������ ����, ������ ĥ�� �����մϴ�.
	bool SelectBattle();

	// ������ �����մϴ�.
	void ProcessBattle();
};

