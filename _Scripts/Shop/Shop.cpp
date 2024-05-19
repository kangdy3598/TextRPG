#include "../_stdafx.h"
#include "Shop.h"

CShop::CShop()
{
	{ m_Position = POSITION(10, 7); }
	m_PlayerJob = nullptr;
}
void CShop::SetPosition(int _posX, int _posY)
{
	m_Position.x = _posX;
	m_Position.y = _posY;
}
void CShop::SetPosition(POSITION _position)
{
	m_Position = _position;
}

void CShop::GetPosition(int& _posX, int& _posY)
{
	m_Position.x = _posX;
	m_Position.y = _posY;
}
void CShop::GetPosition(POSITION& _position)
{
	_position = m_Position;
}
POSITION CShop::GetPosition()
{
	return m_Position;
}

void CShop::Interaction(CObject* _CPlayer)
{
	int iSelect(0);

	while (1)
	{
		//cout << "=====================================";
		//cout << "   " << "상점" << "   ";
		//cout << "=====================================" << endl;
		//cout << "1. 장비 아이템 2. 소비 아이템 3. 상점 나가기 : ";
		cin >> iSelect;

		system("cls");
		switch (iSelect)
		{
		case SHOP_EQUIP_ITEM:
			if (!m_PlayerJob)
				m_PlayerJob = ((CPlayer*)_CPlayer)->virtualGetObjectInfo()->szName;
			ShowEquipItem(m_PlayerJob);
			break;
		case SHOP_USE_ITEM:
			ShowUseItem();
			break;
		case SHOP_EXIT:
			return;
		default:
			break;
		}
	}
}

void CShop::ShowEquipItem(char* _playerJob)
{
	system("cls");

	int iSelect(0);

	cout << "=====================================";
	cout << "   " << "장비 아이템 물품" << "   ";
	cout << "=====================================" << endl;

	if (!strcmp(_playerJob, "전사"))
		cout << "초보 전사의 목검" << endl;
	else if (!strcmp(_playerJob, "마법사"))
		cout << "초보 마법사의 우드 완드" << endl;
	else if (!strcmp(_playerJob, "도적"))
		cout << "초보 도적의 단검" << endl;

	cout << "1. 구매하기 2. 뒤로 가기 : ";
	cin >> iSelect;

	//cout << "구매";
}

void CShop::ShowUseItem()
{
	system("cls");

	int iSelect(0);

	cout << "=====================================";
	cout << "   " << "소비 아이템 물품" << "   ";
	cout << "=====================================" << endl;

	cout << "1. ";
	cout << "초보 모험가의 HP 물약" << endl;
	cout << "1. 구매하기 2. 뒤로 가기 : ";
	cin >> iSelect;
}
