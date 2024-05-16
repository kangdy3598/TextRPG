#include "../_stdafx.h"
#include "Enemy.h"

void CEnemy::InputInfo()
{
	int iInput(0);
	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
	cin >> iInput;

	switch (iInput - 1)
	{
	case LOW_MAP:
		InitInfo("�ʱ�", 50, 5);
		return;
	case MID_MAP:
		InitInfo("�߱�", 70, 7);
		return;
	case HIGH_MAP:
		InitInfo("���", 100, 10);
		return;
	case 4:
		return;
	default:
		cout << "�߸� �Է�" << endl;
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
		InitInfo("�ʱ� ����", 50, 5);
		break;
	case MID_MAP:
		InitInfo("�߱� ����", 70, 7);
		break;
	case HIGH_MAP:
		InitInfo("��� ����", 100, 10);
		break;
	case END:
		return;
	default:
		cout << "�߸� �Է�" << endl;
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
	cout << "�̸� :" << m_StateInfo.szName << endl;
	cout << "ü�� :" << m_StateInfo.iNowHP << " / " << m_StateInfo.iMaxHP << endl;
	cout << "���ݷ� :" << m_StateInfo.iAttackPower << endl;
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
