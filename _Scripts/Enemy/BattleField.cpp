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
		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iSelectNum;
		
		if (!m_CEnemy) m_CEnemy = new CEnemy;
		switch (iSelectNum)
		{
		case LOW_MAP:
			m_CEnemy->InitInfo("초급 몬스터", 50, 5);
			break;
		case MID_MAP:
			m_CEnemy->InitInfo("중급 몬스터", 70, 7);
			break;
		case HIGH_MAP:
			m_CEnemy->InitInfo("고급 몬스터", 100, 10);
			break;
		case END:
			return;
		default:
			cout << "잘못 입력" << endl;
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

		cout << "1. 공격 2. 도망 : ";
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
			cout << "잘못 입력" << endl;
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
		cout << "승리" << endl;
		system("pause");

		return; // 몬스터를 처치했다면 캐릭터가 죽어도 승리 처리
	}

	/*if (!m_CPlayer->CheckBattleAble())
	{
		cout << "사망" << endl;
		system("pause");
	}*/
	
}