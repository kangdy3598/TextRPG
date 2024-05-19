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

	CEnemy() { /*cout << "Enemy ������" << endl;*/ }
	CEnemy(int _num) { /*cout << "Enemy ������ Num :" << _num << endl;*/ }
	~CEnemy() {}

	//void InputInfo();

	// ������ ������ �ʱ�ȭ �մϴ�.
	void InitInfo(int _battleFieldNum);
	
	// ���� ���� ������ ������ �ҷ��ɴϴ�.
	//tagStateInfo GetInfo();
	tagEnemyInfo GetObjectInfo();
	virtual tagEnemyInfo* virtualGetObjectInfo() { return &m_tagEnemyInfo; }
	// ���� ���� ������ ������ �����ݴϴ�.
	virtual void ShowObjectInfo();

	// _iAmount ��ŭ ���� ü���� �����մϴ�.
	virtual void UpdateHP(int _iAmount);

	// ���� ���� �������� �Ǵ��մϴ�.
	virtual bool CheckBattleAble();

	// �޸𸮸� ���� �մϴ�.
	void Release();
};
