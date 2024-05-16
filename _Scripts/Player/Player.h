#pragma once
#include "../Object/Object.h"
enum JOBNAME
{
	WARRIOR = 1,
	MAGICIAN,
	THIEF,
	JOB_COUNT
};

struct tagInvenInfo
{
	int iGold;
};

struct tagEquipInfo
{
	// head
	// clothes
	// shoes
	// glove
	// weapon
};

class CPlayer : public CObject
{
private:

private:

	// ������ �������� �÷��̾ �ʱ�ȭ �մϴ�.
	void InitStateInfo(const char _szJobName[],
					   int _iMaxHP, int _iMaxMP,
					   int _iAttackPower, int _iDefensePower);

	// ĳ���� ���� �����͸� ���� �մϴ�.
	void SaveStateInfo();

public:

	CPlayer(){}
	CPlayer(int _num) /* : CObject(_num)*/ { cout << "Player ������ Num :" << _num << endl; }
	~CPlayer() {}

	// ĳ���� ���� �����͸� �ҷ��ɴϴ�.
	bool LoadStateInfo();

	// �÷��̾�� ���� ������ ���� �մϴ�.
	void SelectJob();

	// ������ ������ ������ �����ݴϴ�.
	void ShowStateInfo();

	// _iAmount ��ŭ ���� ü���� �����մϴ�.
	void UpdateHP(int _iAmount);

	// ���� ���� �������� �Ǵ��մϴ�.
	bool CheckBattleAble();

	// �޸𸮸� ���� �մϴ�.
	void Release();
};
