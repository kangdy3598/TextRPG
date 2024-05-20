#include "../_stdafx.h"
#include "Object.h"

void CObject::SetPosition(int _posX, int _posY)
{
	m_Position.x = _posX;
	m_Position.y = _posY;
}
void CObject::SetPosition(POSITION _position)
{
	m_Position = _position;
}

void CObject::GetPosition(int& _posX, int& _posY)
{
	m_Position.x = _posX;
	m_Position.y = _posY;
}
void CObject::GetPosition(POSITION& _position)
{
	_position = m_Position;
}
POSITION CObject::GetPosition()
{
	return m_Position;
}

//tagObjectInfo CObject::GetObjectInfo()
//{
//	
//}

//void CObject::ShowObjectInfo()
//{
//}

void CObject::Release()
{
	
	// delete m_playerInfo;
}
