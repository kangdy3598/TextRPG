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

void CBattleField::InteractAction()
{
	SelectBattleMap();
}

void CBattleField::SelectBattleMap()
{
	int iSelectNum(0);

	while (true)
	{
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
		cin >> iSelectNum;
		
		if (!m_CEnemy) m_CEnemy = new CEnemy;
		switch (iSelectNum)
		{
		case LOW_MAP:
			m_CEnemy->InitInfo("�ʱ� ����", 50, 5);
			break;
		case MID_MAP:
			m_CEnemy->InitInfo("�߱� ����", 70, 7);
			break;
		case HIGH_MAP:
			m_CEnemy->InitInfo("��� ����", 100, 10);
			break;
		case END:
			return;
		default:
			cout << "�߸� �Է�" << endl;
			system("pause");
			system("cls");
			continue;
		}
		
		system("cls");
		while (SelectBattle())
		{
			ProcessBattle();
		}
		
	}
}

bool CBattleField::InitBattleMap(int _iSelectNum)
{
	return true;
}

bool CBattleField::SelectBattle()
{
	/*if (!m_CPlayer->CheckBattleAble())
	{
		m_CPlayer->UpdateHP(m_CPlayer->GetStateInfo().iMaxHP);
		return false;
	}*/

	if (!m_CEnemy->CheckBattleAble())
		return false;


	int iSelectNum(0);
	do
	{
		//m_CPlayer->ShowStateInfo();
		cout << "=================" << endl;
		m_CEnemy->ShowInfo();

		cout << "1. ���� 2. ���� : ";
		cin >> iSelectNum;

		switch (iSelectNum)
		{
		case 1:
			system("cls");
			return true;
		case 2:
			system("cls");
			return false;
		default:
			cout << "�߸� �Է�" << endl;
			system("pause");
			system("cls");
			break;
		}

	} while (iSelectNum != 1 && iSelectNum != 2);
	
	return true;
}

void CBattleField::ProcessBattle()
{
	//m_CPlayer->UpdateHP(-m_CEnemy->GetInfo().iAttackPower);
	//m_CEnemy->UpdateHP(-m_CPlayer->GetStateInfo().iAttackPower);

	if (!m_CEnemy->CheckBattleAble())
	{
		cout << "�¸�" << endl;
		system("pause");

		return; // ���͸� óġ�ߴٸ� ĳ���Ͱ� �׾ �¸� ó��
	}

	/*if (!m_CPlayer->CheckBattleAble())
	{
		cout << "���" << endl;
		system("pause");
	}*/
	
}