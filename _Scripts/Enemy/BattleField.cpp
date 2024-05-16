#include "../_stdafx.h"
#include "BattleField.h"

void CBattleField::SetPosition(int _posX, int _posY)
{
	m_Position.x = _posX;
	m_Position.y = _posY;
}
void CBattleField::SetPosition(POSITION _position)
{
	m_Position = _position;
}

void CBattleField::GetPosition(int& _posX, int& _posY)
{
	m_Position.x = _posX;
	m_Position.y = _posY;
}
void CBattleField::GetPosition(POSITION& _position)
{
	_position = m_Position;
}
POSITION CBattleField::GetPosition()
{
	return m_Position;
}

int CBattleField::InteractAction(int _iSelectNum, CPlayer* _CPlayer)
{
	//return SelectBattleMap();
	return SelectBattleMenu(_iSelectNum, _CPlayer);
}

// x
int CBattleField::SelectBattleMap()
{
	return 0;
	/*int iSelectNum(0);

	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
	cin >> iSelectNum;

	
	switch (iSelectNum)
	{
	case LOW_MAP:
		
		break;
	case MID_MAP:
		m_CEnemy->InitInfo("�߱� ����", 70, 7);
		break;
	case HIGH_MAP:
		m_CEnemy->InitInfo("��� ����", 100, 10);
		break;
	case END:
		return END;
	default:
		cout << "�߸� �Է�" << endl;
		system("pause");
		return -1;
	}*/

	/*while (SelectBattle())
	{
		ProcessBattle();
	}*/
}

bool CBattleField::InitBattleMap(int _iSelectNum)
{
	return true;
}

bool CBattleField::SelectBattleMenu(int _battleFieldNum, CPlayer* _CPlayer)
{
	int iSelectNum(0);

	if (!m_CEnemy)
	{
		m_CEnemy = new CEnemy(1);
		m_CEnemy->InitInfo(_battleFieldNum);

		cout << "��!! �߻��� " << m_CEnemy->GetStateInfo().szName << "�� Ƣ��Դ�!!" << endl;
		cout << "������ �ұ�?" << endl << endl;
	}
	m_CEnemy->ShowInfo();

	cout << "1. �����Ѵ�. 2. ��������. : ";
	cin >> iSelectNum;

	switch (iSelectNum)
	{
	case 1:
		if (ProcessBattle(_CPlayer))
			break;
	case 2:
		if (m_CEnemy) SAFE_DELETE(m_CEnemy);
		return false;
	default:
		cout << "�߸� �Է�" << endl;
		system("pause");
		system("cls");
		break;
	}

	return true;
}

bool CBattleField::ProcessBattle(CPlayer* _CPlayer)
{
	_CPlayer->UpdateHP(-m_CEnemy->GetStateInfo().iAttackPower);
	m_CEnemy->UpdateHP(-_CPlayer->GetStateInfo().iAttackPower);

	if (!m_CEnemy->CheckBattleAble())
	{
		cout << "�¸�" << endl;
		system("pause");

		return false; // ���͸� óġ�ߴٸ� ĳ���Ͱ� �׾ �¸� ó��
	}

	if (!_CPlayer->CheckBattleAble())
	{
		cout << "���" << endl;
		system("pause");

		return false;
	}
	
	return true;
}