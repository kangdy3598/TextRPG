#include "../_stdafx.h"
#include "Player.h"

void CPlayer::SelectJob()
{
	int iSelectNumber = 0;
	system("cls");
	while (1)
	{
		cout << "직업 선택 (1. 전사 2. 마법사 3. 도적) : ";
		cin >> iSelectNumber;

		switch (iSelectNumber)
		{
		case WARRIOR:
			InitInfo("전사", 100, 50, 8, 10);
			return;
		case MAGICIAN:
			InitInfo("마법사", 80, 130, 15, 5);
			return;
		case THIEF:
			InitInfo("도적", 100, 100, 10, 7);
			return;
		default:
			cout << "잘못 선택" << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
	//SaveInfo(_playerInfo);
	//LoadInfo(_playerInfo);

}

//void CPlayer::ShowObjectInfo()
//{
//}

tagPlayerInfo CPlayer::GetObjectInfo()
{
	return m_tagPlayerInfo;
}

void CPlayer::InitInfo(const char _szJobName[],
					   int _iMaxHP, int _iMaxMP,
					   int _iAttackPower, int _iDefensePower)
{
	m_tagPlayerInfo.iLevel = 1;
	m_tagPlayerInfo.iNowExp = 0;

	strcpy_s(m_tagPlayerInfo.szName, _szJobName);

	m_tagPlayerInfo.iMaxHP = _iMaxHP;
	m_tagPlayerInfo.iNowHP = _iMaxHP;

	m_tagPlayerInfo.iMaxMP = _iMaxMP;
	m_tagPlayerInfo.iNowMP = _iMaxMP;

	m_tagPlayerInfo.iAttackPower = _iAttackPower;
	m_tagPlayerInfo.iDefensePower = _iDefensePower;
}

void CPlayer::SaveInfo()
{
	FILE* pSaveFile = NULL;
	errno_t err = fopen_s(&pSaveFile, "_Data/PlayerInfo.txt", "wb");

	if (err)
		return;

	fwrite((void*) &m_tagPlayerInfo, sizeof(m_tagPlayerInfo), 1, pSaveFile);

	fclose(pSaveFile);
}

bool CPlayer::LoadInfo()
{
	FILE* pLoadFile = NULL;
	errno_t err = fopen_s(&pLoadFile, "_Data/PlayerInfo.txt", "rb");

	if (err)
	{
		return false;
	}

	fread((void*)&m_tagPlayerInfo, sizeof(m_tagPlayerInfo), 1, pLoadFile);

	return true;
}

void CPlayer::UpdateHP(int _iAmount)
{
	m_tagPlayerInfo.iNowHP += _iAmount;
	if (m_tagPlayerInfo.iNowHP > m_tagPlayerInfo.iMaxHP)
		m_tagPlayerInfo.iNowHP = m_tagPlayerInfo.iMaxHP;
}

bool CPlayer::CheckBattleAble()
{
	return m_tagPlayerInfo.iNowHP > 0;
}

void CPlayer::Release()
{
	//SaveInfo();
	
	// delete m_playerInfo;
}
