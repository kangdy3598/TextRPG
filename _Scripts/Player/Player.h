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
	char szJobName[10]; // ���� �̸�
	int iLevel;  // ����
	
	int iNowHP; // ���� ü��
	int iMaxHP; // �ִ� ü��
	
	int iNowMP; // ���� ����
	int iMaxMP; // �ִ� ����
	
	int iNowExp;    // ����ġ
	//int iMaxExp;

	int iAttackPower; // ���ݷ�
	int iDefensePower; // ����

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
	// ������ �������� �÷��̾ �ʱ�ȭ �մϴ�.
	void InitStateInfo(const char _szJobName[],
					   int _iMaxHP, int _iMaxMP,
						int _iAttackPower, int _iDefensePower);

	// ĳ���� ���� �����͸� ���� �մϴ�.
	void SaveStateInfo();

public:

	CPlayer() {}
	~CPlayer() {}

	// ���� ĳ���� ��ġ�� ���� �մϴ�.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// ���� ĳ���� ��ġ�� �ҷ��ɴϴ�.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// ������ ������ ������ �ҷ��ɴϴ�.
	tagStateInfo GetStateInfo();

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
