#include "../_stdafx.h"
#include "Enemy.h"

void CEnemy::InputInfo()
{
	int iInput(0);
	cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
	cin >> iInput;

	switch (iInput - 1)
	{
	case LOW_MAP:
		InitInfo("초급", 50, 5);
		return;
	case MID_MAP:
		InitInfo("중급", 70, 7);
		return;
	case HIGH_MAP:
		InitInfo("고급", 100, 10);
		return;
	case 4:
		return;
	default:
		cout << "잘못 입력" << endl;
		system("pause");
		system("cls");
		break;
	}
}

void CEnemy::InitInfo(const char _szName[], int _iMaxHP, int _iAttackPower)
{
	strcpy_s(m_enemyInfo.szName, _szName);
	m_enemyInfo.iMaxHP = _iMaxHP;
	m_enemyInfo.iNowHP = _iMaxHP;
	m_enemyInfo.iAttackPower = _iAttackPower;
}

tagEnemyInfo CEnemy::GetInfo()
{
	return m_enemyInfo;
}

void CEnemy::ShowInfo()
{
	cout << "이름 :" << m_enemyInfo.szName << endl;
	cout << "체력 :" << m_enemyInfo.iNowHP << " / " << m_enemyInfo.iMaxHP << endl;
	cout << "공격력 :" << m_enemyInfo.iAttackPower << endl;
}

void CEnemy::UpdateHP(int _iAmount)
{
	m_enemyInfo.iNowHP += _iAmount;
	if (m_enemyInfo.iNowHP > m_enemyInfo.iMaxHP)
		m_enemyInfo.iNowHP = m_enemyInfo.iMaxHP;
}

bool CEnemy::CheckBattleAble()
{
	return m_enemyInfo.iNowHP > 0;
}

void CEnemy::Release()
{
	// delete m_enemyInfo;
}
