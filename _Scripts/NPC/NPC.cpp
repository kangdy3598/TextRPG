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
	ShowDescription();
	system("pause");
}

void CNPC::InitNPCInfo(const char _szName[], const char _szscript[][256], int _scriptSize)
{
	strcpy_s(m_NPCInfo.szName, _szName);
	m_NPCInfo.iScriptSize = _scriptSize;
	for (int i = 0; i < _scriptSize; i++)
	{
		strcpy_s(m_NPCInfo.szScript[i], _szscript[i]);
	}
	
}

void CNPC::ShowDescription()
{
	int iSelect(0);

	cout << "=====================================";
	cout << "   " << m_NPCInfo.szName << "   ";
	cout << "=====================================" << endl;

	for (int i = 0; i < m_NPCInfo.iScriptSize; i++)
	{
		cout << m_NPCInfo.szScript[i] << endl;
	}
	
	cout << "1. 수락 2. 거절 : " << endl;
	cin >> iSelect;

}

void CNPC::Release()
{
}
