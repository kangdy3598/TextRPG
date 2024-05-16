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

	CEnemy() { cout << "Enemy ������" << endl; }
	CEnemy(int _num) { cout << "Enemy ������ Num :" << _num << endl; }
	~CEnemy() {}

	void InputInfo();

	void InitInfo(int _battleFieldNum);
	// ������ ������ �ʱ�ȭ �մϴ�.
	void InitInfo(const char _szName[], int _iMaxHP, int _iAttackPower);

	// ���� ���� ������ ������ �ҷ��ɴϴ�.
	//tagStateInfo GetInfo();

	// ���� ���� ������ ������ �����ݴϴ�.
	void ShowInfo();

	// _iAmount ��ŭ ���� ü���� �����մϴ�.
	void UpdateHP(int _iAmount);

	// ���� ���� �������� �Ǵ��մϴ�.
	bool CheckBattleAble();

	// �޸𸮸� ���� �մϴ�.
	void Release();
};
