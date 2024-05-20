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
	return SelectBattleMenu(_iSelectNum, _CPlayer);
}

bool CBattleField::SelectBattleMenu(int _battleFieldNum, CPlayer* _CPlayer)
{
	int iSelectNum(0);

	if (!m_CEnemy)
	{
		m_CEnemy = new CEnemy;
		((CEnemy*)m_CEnemy)->InitInfo(_battleFieldNum);
		//m_CEnemy->UpdateHP(10);

		cout << "앗!! 야생의 " << ((CEnemy*)m_CEnemy)->GetObjectInfo().szName << "가 튀어나왔다!!" << endl;
		cout << "무엇을 할까?" << endl << endl;
	}
	((CEnemy*)m_CEnemy)->ShowObjectInfo();

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
	int playerAttackPower = _CPlayer->GetObjectInfo().iAttackPower;
	int enemyAttackPower = ((CEnemy*)m_CEnemy)->GetObjectInfo().iAttackPower;

	_CPlayer->GetObjectInfo()->iAttackPower;

	cout << ((CEnemy*)m_CEnemy)->GetObjectInfo().szName << "에게 피해를 "
		<< playerAttackPower << " 주었다!" << endl;
	cout << ((CEnemy*)m_CEnemy)->GetObjectInfo().szName << "에게 피해를 "
		<< enemyAttackPower << " 받았다!" << endl;

	_CPlayer->UpdateHP(-enemyAttackPower);
	m_CEnemy->UpdateHP(-playerAttackPower);
	
	system("pause");

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