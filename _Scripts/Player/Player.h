#pragma once
#include "../Object/Object.h"
enum JOBNAME
{
	WARRIOR = 1,
	MAGICIAN,
	THIEF,
	JOB_COUNT
};

struct tagPlayerInfo : tagBattleObjectInfo
{
	int iNowExp = 0;
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
public:
	CPlayer() { }
	CPlayer(int _num) /* : CObject(_num)*/ { cout << "Player ������ Num :" << _num << endl; }
	~CPlayer() {}
private:
	tagPlayerInfo m_tagPlayerInfo;
private:

	// ������ �������� �÷��̾ �ʱ�ȭ �մϴ�.
	void InitInfo(const char _szJobName[],
					   int _iMaxHP, int _iMaxMP,
					   int _iAttackPower, int _iDefensePower);

	// ĳ���� ���� �����͸� ���� �մϴ�.
	void SaveInfo();

public:

	// ĳ���� ���� �����͸� �ҷ��ɴϴ�.
	bool LoadInfo();

	// �÷��̾�� ���� ������ ���� �մϴ�.
	void SelectJob();

	// ������ ������ ������ �����ݴϴ�.
	//void ShowObjectInfo();

	tagPlayerInfo GetObjectInfo();
	virtual tagPlayerInfo* virtualGetObjectInfo() { return &m_tagPlayerInfo; }
	// _iAmount ��ŭ ���� ü���� �����մϴ�.
	virtual void UpdateHP(int _iAmount);

	// ���� ���� �������� �Ǵ��մϴ�.
	virtual bool CheckBattleAble();

	// �޸𸮸� ���� �մϴ�.
	void Release();
};
