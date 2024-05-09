#include "_stdafx.h"
#include "GameManager.h"

void CGameManger::InitGame()
{
	m_CPlayer = new CPlayer;
	if (!m_CPlayer) return;

	m_CMap = new CMap;
	if (!m_CMap) return;

	m_CNPC = new CNPC;
	if (!m_CNPC) return;

	m_CBattleField = new CBattleField;
	if (!m_CBattleField) return;

	POSITION temp;
	m_CPlayer->GetPosition(temp);
	m_CMap->SetMapData(temp, PLAYER_MARK_NUM);

	m_CNPC->GetPosition(temp);
	m_CMap->SetMapData(temp, NPC_MARK_NUM);

	m_CBattleField->GetPosition(temp);
	m_CMap->SetMapData(temp, BATTLE_MARK_NUM);
}

void CGameManger::StartGame()
{
	InitGame();
	//UpdateGame();

	bool bLoadPlayerInfo = m_CPlayer->LoadStateInfo();
	switch (m_CGraphics.DrawTitleScreen(bLoadPlayerInfo))
	{
	case RUNNING - 1:
		m_CGraphics.DrawSelectJobScreen();
		m_CPlayer->SelectJob();
	case RUNNING:
		//m_CMap.InitMap();
		break;
	case EXIT:
		exit(0);
		return;
	default:
		break;
	}
}

void CGameManger::UpdateGame()
{
	int posX = 0, posY = 0;
	void* mapData = m_CMap->GetMapData();

	POSITION* returnPosition = nullptr;
	int objectNumber = 0;
	while (1)
	{
		returnPosition = m_CGraphics.DrawMap((int(*)[20])mapData, objectNumber);

		// returnPosition�� nullptr�� �ƴϸ�
		// objectNumber ������Ʈ�� ��ȣ�ۿ��� �����մϴ�.
		if (returnPosition != nullptr)
		{
			system("cls");
			switch (objectNumber)
			{
			case NPC_MARK_NUM:
				//m_CGraphics->DrawScreen(NPC_MARK_NUM)
				m_CNPC->InteractAction();
				break;
			case BATTLE_MARK_NUM:
				//m_CGraphics->DrawScreen(BATTLE_MARK_NUM)
				m_CBattleField->InteractAction();
				break;
			default:
			//	SelectAction(); 
				break;
			}
			
			// ��ȣ�ۿ� �����ٸ� ��ȣ�ۿ� �ϱ� �� ��ġ�� ���ư��ϴ�.
			m_CPlayer->SetPosition(*returnPosition);
		}
	}
}

void CGameManger::EndGame()
{
	if (m_CPlayer)
	{
		m_CPlayer->Release();
		delete m_CPlayer;
		m_CPlayer = 0;
	}

	if (m_CEnemy)
	{
		m_CEnemy->Release();
		delete m_CEnemy;
		m_CEnemy = 0;
	}
	//m_CPlayer->SaveInfo();
}

//bool CGameManger::SelectAction()
//{
//	int iSelectNum(0);
//	system("cls");
//	while (true)
//	{
//		cout << "1. ����� ���� 2. ���� : ";
//		cin >> iSelectNum;
//
//		switch (iSelectNum)
//		{
//		case RUNNING:
//			SelectBattleMap();
//			return false;
//		case EXIT:
//			return true;
//		default:
//			cout << "�߸� �Է�" << endl;
//			system("pause");
//			system("cls");
//			continue;
//		}
//	}
//}
//
//void CGameManger::SelectBattleMap()
//{
//	int iSelectNum(0);
//
//	while (true)
//	{
//		m_CPlayer->ShowStateInfo();
//		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
//		cin >> iSelectNum;
//
//		if (!m_CEnemy) m_CEnemy = new CEnemy;
//		switch (iSelectNum)
//		{
//		case LOW_MAP:
//			m_CEnemy->InitInfo("�ʱ� ����", 50, 5);
//			break;
//		case MID_MAP:
//			m_CEnemy->InitInfo("�߱� ����", 70, 7);
//			break;
//		case HIGH_MAP:
//			m_CEnemy->InitInfo("��� ����", 100, 10);
//			break;
//		case END:
//			return;
//		default:
//			cout << "�߸� �Է�" << endl;
//			system("pause");
//			system("cls");
//			continue;
//		}
//
//		while (SelectBattle())
//		{
//			ProcessBattle();
//		}
//	}
//}
//
//bool CGameManger::InitBattleMap(int _iSelectNum)
//{
//	return true;
//}
//
//bool CGameManger::SelectBattle()
//{
//	if (!m_CPlayer->CheckBattleAble())
//	{
//		m_CPlayer->UpdateHP(m_CPlayer->GetStateInfo().iMaxHP);
//		return false;
//	}
//
//	if (!m_CEnemy->CheckBattleAble())
//		return false;
//	
//
//	int iSelectNum(0);
//	do
//	{
//		m_CPlayer->ShowStateInfo();
//		cout << "=================" << endl;
//		m_CEnemy->ShowInfo();
//
//		cout << "1. ���� 2. ���� : ";
//		cin >> iSelectNum;
//
//		if (iSelectNum == 1)
//			return true;
//
//		else if (iSelectNum == 2)
//			return false;
//
//		else
//		{
//			cout << "�߸� �Է�" << endl;
//			system("pause");
//			system("cls");
//		}
//			
//	} while (iSelectNum != 1 && iSelectNum != 2);
//
//	return true;
//}
//
//void CGameManger::ProcessBattle()
//{
//	m_CPlayer->UpdateHP(-m_CEnemy->GetInfo().iAttackPower);
//	m_CEnemy->UpdateHP(-m_CPlayer->GetStateInfo().iAttackPower);
//
//	if (!m_CEnemy->CheckBattleAble())
//	{
//		cout << "�¸�" << endl;
//		system("pause");
//
//		return; // ���͸� óġ�ߴٸ� ĳ���Ͱ� �׾ �¸� ó��
//	}
//
//	if (!m_CPlayer->CheckBattleAble())
//	{
//		cout << "���" << endl;
//		system("pause");
//	}
//}

