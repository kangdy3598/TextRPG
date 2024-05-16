#pragma once
#include "../Object/Object.h"
enum MAPNAME
{
	LOW_MAP = 1,
	MID_MAP,
	HIGH_MAP,
	END
};

class CEnemy : public CObject
{
private:
	//tagEnemyInfo m_enemyInfo;

private:
	void SetEnemyInfo(const char _szName[], int _iMaxHP, int _iAttackPower);

public:

	CEnemy() { cout << "Enemy 생성자" << endl; }
	CEnemy(int _num) { cout << "Enemy 생성자 Num :" << _num << endl; }
	~CEnemy() {}

	void InputInfo();

	void InitInfo(int _battleFieldNum);
	// 몬스터의 정보를 초기화 합니다.
	void InitInfo(const char _szName[], int _iMaxHP, int _iAttackPower);

	// 전투 중인 몬스터의 정보를 불러옵니다.
	//tagStateInfo GetInfo();

	// 전투 중인 몬스터의 정보를 보여줍니다.
	void ShowInfo();

	// _iAmount 만큼 현재 체력을 변경합니다.
	void UpdateHP(int _iAmount);

	// 현재 전투 가능한지 판단합니다.
	bool CheckBattleAble();

	// 메모리를 해제 합니다.
	void Release();
};
