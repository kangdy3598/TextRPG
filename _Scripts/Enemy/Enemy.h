#pragma once

enum MAPNAME
{
	LOW_MAP = 1,
	MID_MAP,
	HIGH_MAP,
	END
};

struct tagEnemyInfo
{
	char szName[32]; // 몬스터 이름

	int iNowHP; // 현재 체력
	int iMaxHP; // 최대 체력

	int iAttackPower; // 공격력
	int iDefensePower; // 방어력

	int iDropGold; // 처지 시 드랍될 골드량
};

class CEnemy
{
private:
	tagEnemyInfo m_enemyInfo;

private:

public:
	void InputInfo();

	// 몬스터의 정보를 초기화 합니다.
	void InitInfo(const char _szName[], int _iMaxHP, int _iAttackPower);

	// 전투 중인 몬스터의 정보를 불러옵니다.
	tagEnemyInfo GetInfo();

	// 전투 중인 몬스터의 정보를 보여줍니다.
	void ShowInfo();

	// _iAmount 만큼 현재 체력을 변경합니다.
	void UpdateHP(int _iAmount);

	// 현재 전투 가능한지 판단합니다.
	bool CheckBattleAble();

	// 메모리를 해제 합니다.
	void Release();
};
