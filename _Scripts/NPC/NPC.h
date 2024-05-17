#pragma once
#include "../Player/Player.h"

struct tagNPCInfo : tagObjectInfo
{
	int iScriptSize;
	char szScript[10][256]; // 대사
};

class CNPC
{
private:

	tagNPCInfo m_NPCInfo;

	POSITION m_Position;

private:
	

public:
	// NPC의 정보를 초기화 합니다.
	void InitNPCInfo(const char _szName[], const char _szscript[][256], int _scriptSize);

	// NPC 위치를 설정 합니다.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// NPC 위치를 불러옵니다.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// OBJECT : NPC 의 상호작용을 실행합니다.
	void InteractAction();

	// NPC의 대사를 보여줍니다.
	void ShowDescription();

	// 메모리를 해제 합니다.
	void Release();
};
#pragma once
