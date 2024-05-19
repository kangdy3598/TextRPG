#pragma once
#include "../Object/Object.h"
enum MAPNAME
{
	LOW_MAP = 1,
	MID_MAP,
	HIGH_MAP,
	END
};

struct tagEnemyInfo : tagBattleObjectInfo
{
	int iObtain_Exp = 0;
	int iObtain_Gold = 0;
};

class CEnemy : public CObject
{
private:
	tagEnemyInfo m_tagEnemyInfo;
private:
	void SetEnemyInfo(const char _szName[], int _iMaxHP, int _iAttackPower);

public:

	CEnemy() { /*cout << "Enemy 생성자" << endl;*/ }
	CEnemy(int _num) { /*cout << "Enemy 생성자 Num :" << _num << endl;*/ }
	~CEnemy() {}

	//void InputInfo();

	// 몬스터의 정보를 초기화 합니다.
	void InitInfo(int _battleFieldNum);
	
	// 전투 중인 몬스터의 정보를 불러옵니다.
	//tagStateInfo GetInfo();
	tagEnemyInfo GetObjectInfo();
	virtual tagEnemyInfo* virtualGetObjectInfo() { return &m_tagEnemyInfo; }
	// 전투 중인 몬스터의 정보를 보여줍니다.
	virtual void ShowObjectInfo();

	// _iAmount 만큼 현재 체력을 변경합니다.
	virtual void UpdateHP(int _iAmount);

	// 현재 전투 가능한지 판단합니다.
	virtual bool CheckBattleAble();

	// 메모리를 해제 합니다.
	void Release();
};
