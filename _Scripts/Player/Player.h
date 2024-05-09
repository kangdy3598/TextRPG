#pragma once

enum JOBNAME
{
	WARRIOR = 1,
	MAGICIAN,
	THIEF,
	JOB_COUNT
};

struct tagStateInfo
{
	char szJobName[10]; // 직업 이름
	int iLevel;  // 레벨
	
	int iNowHP; // 현재 체력
	int iMaxHP; // 최대 체력
	
	int iNowMP; // 현재 마나
	int iMaxMP; // 최대 마나
	
	int iNowExp;    // 경험치
	//int iMaxExp;

	int iAttackPower; // 공격력
	int iDefensePower; // 방어력

};

struct tagInvenInfo
{
	int iGold;
};

struct tagEquipInfo
{

};
class CPlayer
{
private:
	tagStateInfo m_StateInfo;
	tagInvenInfo m_InvenInfo;
	tagEquipInfo m_EquipInfo;

	POSITION m_Position = POSITION(24, 5);

private:
	// 선택한 직업으로 플레이어를 초기화 합니다.
	void InitStateInfo(const char _szJobName[],
					   int _iMaxHP, int _iMaxMP,
						int _iAttackPower, int _iDefensePower);

	// 캐릭터 정보 데이터를 저장 합니다.
	void SaveStateInfo();

public:

	CPlayer() {}
	~CPlayer() {}

	// 현재 캐릭터 위치를 설정 합니다.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// 현재 캐릭터 위치를 불러옵니다.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// 선택한 직업의 정보를 불러옵니다.
	tagStateInfo GetStateInfo();

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
