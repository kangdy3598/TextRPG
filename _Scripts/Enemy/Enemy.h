#pragma once

enum MAPNAME
{
	LOW_MAP = 1,
	MID_MAP,
	HIGH_MAP,
	END
};

struct tagEnemyInfo
{
	char szName[32]; // ���� �̸�

	int iNowHP; // ���� ü��
	int iMaxHP; // �ִ� ü��

	int iAttackPower; // ���ݷ�
	int iDefensePower; // ����

	int iDropGold; // ó�� �� ����� ��差
};

class CEnemy
{
private:
	tagEnemyInfo m_enemyInfo;

private:

public:
	void InputInfo();

	// ������ ������ �ʱ�ȭ �մϴ�.
	void InitInfo(const char _szName[], int _iMaxHP, int _iAttackPower);

	// ���� ���� ������ ������ �ҷ��ɴϴ�.
	tagEnemyInfo GetInfo();

	// ���� ���� ������ ������ �����ݴϴ�.
	void ShowInfo();

	// _iAmount ��ŭ ���� ü���� �����մϴ�.
	void UpdateHP(int _iAmount);

	// ���� ���� �������� �Ǵ��մϴ�.
	bool CheckBattleAble();

	// �޸𸮸� ���� �մϴ�.
	void Release();
};
