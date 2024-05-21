#pragma once
#include "../Player/Player.h"	

#define SHOP_EQUIP_ITEM 1
#define SHOP_USE_ITEM   2
#define SHOP_EXIT       3
class CShop
{
private:
	
	POSITION m_Position;
	char* m_PlayerJob;

private:
	void ShowEquipItem(char* _playerJob);
	void ShowUseItem();

public:

	CShop();
	~CShop(){}

	// 현재 상점 위치를 설정 합니다.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// 현재 상점 위치를 불러옵니다.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// OBJECT : 상점 의 상호작용을 실행합니다.
	void Interaction(CObject* _CPlayer);
};

