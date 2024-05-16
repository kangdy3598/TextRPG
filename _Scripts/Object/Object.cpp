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

tagStateInfo CObject::GetStateInfo()
{
	return m_StateInfo;
}

void CObject::ShowStateInfo()
{
}

void CObject::UpdateHP(int _iAmount)
{
	m_StateInfo.iNowHP += _iAmount;
	if (m_StateInfo.iNowHP > m_StateInfo.iMaxHP)
		m_StateInfo.iNowHP = m_StateInfo.iMaxHP;
}

bool CObject::CheckBattleAble()
{
	return m_StateInfo.iNowHP > 0;
}

void CObject::Release()
{
	// delete m_playerInfo;
}
