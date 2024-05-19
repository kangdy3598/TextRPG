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

	// ���� ���� ��ġ�� ���� �մϴ�.
	void SetPosition(int _posX, int _posY);
	void SetPosition(POSITION _position);

	// ���� ���� ��ġ�� �ҷ��ɴϴ�.
	void GetPosition(int& _posX, int& _posY);
	void GetPosition(POSITION& _position);
	POSITION GetPosition();

	// OBJECT : ���� �� ��ȣ�ۿ��� �����մϴ�.
	void Interaction(CObject* _CPlayer);
};

