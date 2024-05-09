#pragma once

//struct tagStateInfo
//{
//	char szName[10]; // NPC 이름
//
//};

class CNPC
{
private:

	//POSITION m_position;
	//tagStateInfo m_StateInfo;

	POSITION m_Position = POSITION(25, 5);

private:
	// NPC의 정보를 초기화 합니다.
	void InitStateInfo(const char _szName[]);

public:

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
