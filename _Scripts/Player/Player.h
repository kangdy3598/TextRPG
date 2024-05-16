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

	// 선택한 직업으로 플레이어를 초기화 합니다.
	void InitStateInfo(const char _szJobName[],
					   int _iMaxHP, int _iMaxMP,
					   int _iAttackPower, int _iDefensePower);

	// 캐릭터 정보 데이터를 저장 합니다.
	void SaveStateInfo();

public:

	CPlayer(){}
	CPlayer(int _num) /* : CObject(_num)*/ { cout << "Player 생성자 Num :" << _num << endl; }
	~CPlayer() {}

	// 캐릭터 정보 데이터를 불러옵니다.
	bool LoadStateInfo();

	// 플레이어로 정할 직업을 선택 합니다.
	void SelectJob();

	// 선택한 직업의 정보를 보여줍니다.
	void ShowStateInfo();

	// _iAmount 만큼 현재 체력을 변경합니다.
	void UpdateHP(int _iAmount);

	// 현재 전투 가능한지 판단합니다.
	bool CheckBattleAble();

	// 메모리를 해제 합니다.
	void Release();
};
