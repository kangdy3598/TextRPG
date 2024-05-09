#pragma once

//struct tagStateInfo
//{
//	char szName[10]; // NPC �̸�
//
//};

class CNPC
{
private:

	//POSITION m_position;
	//tagStateInfo m_StateInfo;

	POSITION m_Position = POSITION(25, 5);

private:
	// NPC�� ������ �ʱ�ȭ �մϴ�.
	void InitStateInfo(const char _szName[]);

public:

	// NPC ��ġ�� ���� �մϴ�.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// NPC ��ġ�� �ҷ��ɴϴ�.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// OBJECT : NPC �� ��ȣ�ۿ��� �����մϴ�.
	void InteractAction();

	// NPC�� ��縦 �����ݴϴ�.
	void ShowDescription();

	// �޸𸮸� ���� �մϴ�.
	void Release();
};
#pragma once
