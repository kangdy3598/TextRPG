#pragma once

class CMap
{
private:
	int m_MapData[60][20] = { 0 };

public:
	
	//void InitMap();
	void SetMapData(POSITION _position, int _iDrawType);
	//void GetMapData(int _mapData[60][20]);
	void* GetMapData();
	void GetObjectData(int _objectNumber);
};

