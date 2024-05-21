#pragma once
#include "../Player/Player.h"

struct tagNPCInfo : tagObjectInfo
{
	int iScriptSize;
	char szScript[10][256]; // ���
};

class CNPC
{
private:

	tagNPCInfo m_NPCInfo;

	POSITION m_Position;

private:
	

public:

	CNPC() { m_Position = POSITION(25, 5); }
	~CNPC() {}
	// NPC�� ������ �ʱ�ȭ �մϴ�.
	void InitNPCInfo(const char _szName[], const char _szscript[][256], int _scriptSize);

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
