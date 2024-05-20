#include "../_stdafx.h"
#include "Enemy.h"

void CEnemy::InitInfo(int _battleFieldNum)
{
	switch (_battleFieldNum)
	{
	case LOW_MAP:
		SetEnemyInfo("�ʱ� ����", 50, 5);
		break;
	case MID_MAP:
		SetEnemyInfo("�߱� ����", 70, 7);
		break;
	case HIGH_MAP:
		SetEnemyInfo("��� ����", 100, 10);
		break;
	case END:
		return;
	default:
		cout << "�߸� �Է�" << endl;
		system("pause");
		system("cls");
	}
}

void CEnemy::SetEnemyInfo(const char _szName[], int _iMaxHP, int _iAttackPower)
{
	strcpy_s(m_tagEnemyInfo.szName, _szName);
	m_tagEnemyInfo.iMaxHP = _iMaxHP;
	m_tagEnemyInfo.iNowHP = _iMaxHP;
	m_tagEnemyInfo.iAttackPower = _iAttackPower;
}

//tagStateInfo CEnemy::GetInfo()
//{
//	return m_StateInfo;
//}

tagEnemyInfo* CEnemy::GetObjectInfo()
{
	return &m_tagEnemyInfo;
}

void CEnemy::ShowObjectInfo()
{
	cout << "�̸� :" << m_tagEnemyInfo.szName << endl;
	cout << "ü�� :" << m_tagEnemyInfo.iNowHP << " / " << m_tagEnemyInfo.iMaxHP << endl;
	cout << "���ݷ� :" << m_tagEnemyInfo.iAttackPower << endl;
}

void CEnemy::UpdateHP(int _iAmount)
{
	m_tagEnemyInfo.iNowHP += _iAmount;
	if (m_tagEnemyInfo.iNowHP > m_tagEnemyInfo.iMaxHP)
		m_tagEnemyInfo.iNowHP = m_tagEnemyInfo.iMaxHP;
}

bool CEnemy::CheckBattleAble()
{
	return m_tagEnemyInfo.iNowHP > 0;
}


void CEnemy::Release()
{
	// delete m_enemyInfo;
}
