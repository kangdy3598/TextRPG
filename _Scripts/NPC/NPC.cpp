#include "../_stdafx.h"
#include "NPC.h"

void CNPC::SetPosition(int _posX, int _posY)
{
	m_Position.x = _posX;
	m_Position.y = _posY;
}
void CNPC::SetPosition(POSITION _position)
{
	m_Position = _position;
}

void CNPC::GetPosition(int& _posX, int& _posY)
{
	_posX = m_Position.x;
	_posY = m_Position.y;
}
void CNPC::GetPosition(POSITION& _position)
{
	_position = m_Position;
}
POSITION CNPC::GetPosition()
{
	return m_Position;
}

void CNPC::InteractAction()
{
	cout << "NPC와의 상호작용" << endl;
	system("pause");
}

void CNPC::InitStateInfo(const char _szName[])
{
}

void CNPC::ShowDescription()
{
	cout << "test" << endl;
}

void CNPC::Release()
{
}
