#pragma once

struct tagObjectInfo
{
	char szName[20]; // 이름
};
struct tagBattleObjectInfo : tagObjectInfo
{
	int iLevel;  // 레벨

	int iNowHP; // 현재 체력
	int iMaxHP; // 최대 체력

	int iNowMP; // 현재 마나
	int iMaxMP; // 최대 마나

	int iAttackPower; // 공격력
	int iDefensePower; // 방어력
};

class CObject
{
public:

	POSITION m_Position = POSITION(0, 0);

private:


public:

	CObject() {  }
	CObject(int _num) { cout << "Object 생성자 Num :" << _num << endl; }
	~CObject() { }

	// 현재 오브젝트 위치를 설정 합니다.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// 현재 오브젝트 위치를 불러옵니다.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// 선택한 오브젝트의 정보를 불러옵니다.
	//tagObjectInfo GetObjectInfo(){}
	virtual tagObjectInfo* virtualGetObjectInfo(){ }
	// 선택한 오브젝트의 정보를 보여줍니다.
	//virtual void ShowObjectInfo();

	// _iAmount 만큼 현재 체력을 변경합니다.
	virtual void UpdateHP(int _iAmount){}
	
	// 현재 전투 가능한지 판단합니다.
	virtual bool CheckBattleAble() { return true; }

	// 메모리를 해제 합니다.
	void Release();
};
