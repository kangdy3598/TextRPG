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

	cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
	cin >> iSelectNum;

	
	switch (iSelectNum)
	{
	case LOW_MAP:
		
		break;
	case MID_MAP:
		m_CEnemy->InitInfo("중급 몬스터", 70, 7);
		break;
	case HIGH_MAP:
		m_CEnemy->InitInfo("고급 몬스터", 100, 10);
		break;
	case END:
		return END;
	default:
		cout << "잘못 입력" << endl;
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

		cout << "앗!! 야생의 " << m_CEnemy->GetStateInfo().szName << "가 튀어나왔다!!" << endl;
		cout << "무엇을 할까?" << endl << endl;
	}
	m_CEnemy->ShowInfo();

	cout << "1. 공격한다. 2. 도망간다. : ";
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
		cout << "잘못 입력" << endl;
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
		cout << "승리" << endl;
		system("pause");

		return false; // 몬스터를 처치했다면 캐릭터가 죽어도 승리 처리
	}

	if (!_CPlayer->CheckBattleAble())
	{
		cout << "사망" << endl;
		system("pause");

		return false;
	}
	
	return true;
}