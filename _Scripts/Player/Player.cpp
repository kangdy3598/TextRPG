#include "../_stdafx.h"
#include "Player.h"

//void CPlayer::SetPosition(int _posX, int _posY)
//{
//	m_Position.x = _posX;
//	m_Position.y = _posY;
//}
//void CPlayer::SetPosition(POSITION _position)
//{
//	m_Position = _position;
//}
//
//void CPlayer::GetPosition(int& _posX, int& _posY)
//{
//	m_Position.x = _posX;
//	m_Position.y = _posY;
//}
//void CPlayer::GetPosition(POSITION& _position)
//{
//	_position = m_Position;
//}
//POSITION CPlayer::GetPosition()
//{
//	return m_Position;
//}

//tagStateInfo CPlayer::GetStateInfo()
//{
//	return m_StateInfo;
//}

void CPlayer::SelectJob()
{
	int iSelectNumber = 0;
	system("cls");
	while (1)
	{
		cout << "���� ���� (1. ���� 2. ������ 3. ����) : ";
		cin >> iSelectNumber;

		switch (iSelectNumber)
		{
		case WARRIOR:
			InitStateInfo("����", 100, 50, 8, 10);
			return;
		case MAGICIAN:
			InitStateInfo("������", 80, 130, 15, 5);
			return;
		case THIEF:
			InitStateInfo("����", 100, 100, 10, 7);
			return;
		default:
			cout << "�߸� ����" << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
	//SaveInfo(_playerInfo);
	//LoadInfo(_playerInfo);

}

void CPlayer::InitStateInfo(const char _szJobName[],
					   int _iMaxHP, int _iMaxMP,
					   int _iAttackPower, int _iDefensePower)
{
	m_StateInfo.iLevel = 1;
	m_StateInfo.iNowExp = 0;

	strcpy_s(m_StateInfo.szName, _szJobName);

	m_StateInfo.iMaxHP = _iMaxHP;
	m_StateInfo.iNowHP = _iMaxHP;

	m_StateInfo.iMaxMP = _iMaxMP;
	m_StateInfo.iNowMP = _iMaxMP;

	m_StateInfo.iAttackPower = _iAttackPower;
	m_StateInfo.iDefensePower = _iDefensePower;
}

void CPlayer::SaveStateInfo()
{
	FILE* pSaveFile = NULL;
	errno_t err = fopen_s(&pSaveFile, "_Data/PlayerInfo.txt", "wb");

	if (err)
		return;

	fwrite((void*) &m_StateInfo, sizeof(m_StateInfo), 1, pSaveFile);

	fclose(pSaveFile);
}

bool CPlayer::LoadStateInfo()
{
	FILE* pLoadFile = NULL;
	errno_t err = fopen_s(&pLoadFile, "_Data/PlayerInfo.txt", "rb");

	if (err)
	{
		return false;
	}

	fread((void*)&m_StateInfo, sizeof(m_StateInfo), 1, pLoadFile);

	return true;
}

void CPlayer::ShowStateInfo()
{
	/*system("cls");
	cout << "�̸� :" << m_StateInfo.szJobName << endl;
	cout << "���� : " << m_StateInfo.iLevel << endl;
	cout << "����ġ : " << m_StateInfo.iNowExp << endl;
	cout << "ü�� :" << m_StateInfo.iNowHP << " / " << m_StateInfo.iMaxHP << endl;
	cout << "���� :" << m_StateInfo.iNowMP << " / " << m_StateInfo.iMaxMP << endl;
	cout << "���ݷ� :" << m_StateInfo.iAttackPower << endl;*/
}

void CPlayer::UpdateHP(int _iAmount)
{
	m_StateInfo.iNowHP += _iAmount;
	if (m_StateInfo.iNowHP > m_StateInfo.iMaxHP)
		m_StateInfo.iNowHP = m_StateInfo.iMaxHP;
}

bool CPlayer::CheckBattleAble()
{
	return m_StateInfo.iNowHP > 0;
}

void CPlayer::Release()
{
	SaveStateInfo();
	// delete m_playerInfo;
}
