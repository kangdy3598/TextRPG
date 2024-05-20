#pragma once

struct tagObjectInfo
{
	char szName[20]; // �̸�
};
struct tagBattleObjectInfo : tagObjectInfo
{
	int iLevel;  // ����

	int iNowHP; // ���� ü��
	int iMaxHP; // �ִ� ü��

	int iNowMP; // ���� ����
	int iMaxMP; // �ִ� ����

	int iAttackPower; // ���ݷ�
	int iDefensePower; // ����
};

class CObject
{
public:

	POSITION m_Position = POSITION(0, 0);

private:


public:

	CObject() {  }
	CObject(int _num) { cout << "Object ������ Num :" << _num << endl; }
	~CObject() { }

	// ���� ������Ʈ ��ġ�� ���� �մϴ�.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// ���� ������Ʈ ��ġ�� �ҷ��ɴϴ�.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// ������ ������Ʈ�� ������ �ҷ��ɴϴ�.
	//tagObjectInfo GetObjectInfo(){}
	virtual tagObjectInfo* virtualGetObjectInfo(){ }
	// ������ ������Ʈ�� ������ �����ݴϴ�.
	//virtual void ShowObjectInfo();

	// _iAmount ��ŭ ���� ü���� �����մϴ�.
	virtual void UpdateHP(int _iAmount){}
	
	// ���� ���� �������� �Ǵ��մϴ�.
	virtual bool CheckBattleAble() { return true; }

	// �޸𸮸� ���� �մϴ�.
	void Release();
};
