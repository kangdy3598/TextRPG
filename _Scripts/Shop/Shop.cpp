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
		//cout << "   " << "����" << "   ";
		//cout << "=====================================" << endl;
		//cout << "1. ��� ������ 2. �Һ� ������ 3. ���� ������ : ";
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
	cout << "   " << "��� ������ ��ǰ" << "   ";
	cout << "=====================================" << endl;

	if (!strcmp(_playerJob, "����"))
		cout << "�ʺ� ������ ���" << endl;
	else if (!strcmp(_playerJob, "������"))
		cout << "�ʺ� �������� ��� �ϵ�" << endl;
	else if (!strcmp(_playerJob, "����"))
		cout << "�ʺ� ������ �ܰ�" << endl;

	cout << "1. �����ϱ� 2. �ڷ� ���� : ";
	cin >> iSelect;

	//cout << "����";
}

void CShop::ShowUseItem()
{
	system("cls");

	int iSelect(0);

	cout << "=====================================";
	cout << "   " << "�Һ� ������ ��ǰ" << "   ";
	cout << "=====================================" << endl;

	cout << "1. ";
	cout << "�ʺ� ���谡�� HP ����" << endl;
	cout << "1. �����ϱ� 2. �ڷ� ���� : ";
	cin >> iSelect;
}
