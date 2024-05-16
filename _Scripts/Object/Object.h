#pragma once

struct tagStateInfo
{
	char szName[20]; // �̸�
	int iLevel;  // ����

	int iNowHP; // ���� ü��
	int iMaxHP; // �ִ� ü��

	int iNowMP; // ���� ����
	int iMaxMP; // �ִ� ����

	int iNowExp = 0;    // ����ġ
	//int iMaxExp;

	int iAttackPower; // ���ݷ�
	int iDefensePower; // ����

};

class CObject
{
protected:
	tagStateInfo m_StateInfo;

	POSITION m_Position = POSITION(0, 0);

private:


public:

	CObject() { cout << "Object ������" << endl; }
	CObject(int _num) { cout << "Object ������ Num :" << _num << endl; }
	~CObject() { }

	// ���� ������Ʈ ��ġ�� ���� �մϴ�.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// ���� ������Ʈ ��ġ�� �ҷ��ɴϴ�.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	tagStateInfo GetStateInfo();

	// ������ ������Ʈ�� ������ �����ݴϴ�.
	void ShowStateInfo();

	// _iAmount ��ŭ ���� ü���� �����մϴ�.
	
	//vptr vtbl
	/*virtual->�������̵�*/ void UpdateHP(int _iAmount); // �� : �������̵�����
	
	// ���� ���� �������� �Ǵ��մϴ�.
	bool CheckBattleAble();

	// �޸𸮸� ���� �մϴ�.
	void Release();
};
