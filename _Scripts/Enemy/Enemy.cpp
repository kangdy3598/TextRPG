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

void CEnemy::InitInfo(int _battleFieldNum)
{
	switch (_battleFieldNum)
	{
	case LOW_MAP:
		InitInfo("초급 몬스터", 50, 5);
		break;
	case MID_MAP:
		InitInfo("중급 몬스터", 70, 7);
		break;
	case HIGH_MAP:
		InitInfo("고급 몬스터", 100, 10);
		break;
	case END:
		return;
	default:
		cout << "잘못 입력" << endl;
		system("pause");
		system("cls");
	}
}

void CEnemy::InitInfo(const char _szName[], int _iMaxHP, int _iAttackPower)
{
	strcpy_s(m_StateInfo.szName, _szName);
	m_StateInfo.iMaxHP = _iMaxHP;
	m_StateInfo.iNowHP = _iMaxHP;
	m_StateInfo.iAttackPower = _iAttackPower;
}

//tagStateInfo CEnemy::GetInfo()
//{
//	return m_StateInfo;
//}

void CEnemy::ShowInfo()
{
	cout << "이름 :" << m_StateInfo.szName << endl;
	cout << "체력 :" << m_StateInfo.iNowHP << " / " << m_StateInfo.iMaxHP << endl;
	cout << "공격력 :" << m_StateInfo.iAttackPower << endl;
}

void CEnemy::UpdateHP(int _iAmount)
{
	m_StateInfo.iNowHP += _iAmount;
	if (m_StateInfo.iNowHP > m_StateInfo.iMaxHP)
		m_StateInfo.iNowHP = m_StateInfo.iMaxHP;
}

bool CEnemy::CheckBattleAble()
{
	return m_StateInfo.iNowHP > 0;
}

void CEnemy::Release()
{
	// delete m_enemyInfo;
}
