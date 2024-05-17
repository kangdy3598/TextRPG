#include "../_stdafx.h"
#include "Map.h"

//void CMap::InitMap()
//{
//	
//}

void CMap::SetMapData(POSITION _position, int _iDrawType)
{
	m_MapData[_position.x][_position.y] = _iDrawType;
}

void* CMap::GetMapData()
{
	return m_MapData;
}

void CMap::GetObjectData(int _objectNumber)
{
}

