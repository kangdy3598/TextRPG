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
	CPlayer(int _num) /* : CObject(_num)*/ { cout << "Player 생성자 Num :" << _num << endl; }
	~CPlayer() {}
private:
	tagPlayerInfo m_tagPlayerInfo;
private:

	// 선택한 직업으로 플레이어를 초기화 합니다.
	void InitInfo(const char _szJobName[],
					   int _iMaxHP, int _iMaxMP,
					   int _iAttackPower, int _iDefensePower);

	// 캐릭터 정보 데이터를 저장 합니다.
	void SaveInfo();

public:

	// 캐릭터 정보 데이터를 불러옵니다.
	bool LoadInfo();

	// 플레이어로 정할 직업을 선택 합니다.
	void SelectJob();

	// 선택한 직업의 정보를 보여줍니다.
	//void ShowObjectInfo();

	tagPlayerInfo GetObjectInfo();
	virtual tagPlayerInfo* virtualGetObjectInfo() { return &m_tagPlayerInfo; }
	// _iAmount 만큼 현재 체력을 변경합니다.
	virtual void UpdateHP(int _iAmount);

	// 현재 전투 가능한지 판단합니다.
	virtual bool CheckBattleAble();

	// 메모리를 해제 합니다.
	void Release();
};
