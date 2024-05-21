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
	// 최대 아이템 이름 길이 : 32
	// 최대 아이템 개수 : 10
	char szEquipItemList[10][32];
	char szUseItemList[10][32];

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

struct tagPlayerInfo : tagBattleObjectInfo
{
	int iNowExp = 0;
	tagInvenInfo tagInvenInfo;
};
class CPlayer : public CObject
{
public:
	CPlayer();
	~CPlayer() {}
private:
	tagPlayerInfo m_tagPlayerInfo;
	//tagInvenInfo m_tagInvenInfo;

	int m_MyJobCode;
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
