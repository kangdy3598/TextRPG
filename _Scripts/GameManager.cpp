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

	char temp_script[][256] =
	{	"�ʱ� ����, �߱� ����, ��� ���� ���� �� ������ ��� ���ÿ�.",
		"ǥ���� �Ѽ� �� ���� 10����."
	};

	int temp_size = sizeof(temp_script) / sizeof(temp_script[0]);
	m_CNPC->InitNPCInfo( "���� ǥ����", temp_script, temp_size);

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

void CGameManger::InteractionObject(int _objectNum)
{
	system("cls");
	m_bIsDrawingMap = false;

	int iSelectNum = 0;
	int iBattleNum = -1;
	switch (_objectNum)
	{
	case NPC_MARK_NUM:
		m_CNPC->InteractAction();
		break;
	case BATTLE_MARK_NUM:
		while (iBattleNum != 0)
		{
			system("cls");
			m_CGraphics.DrawPlayerInfo(m_CPlayer->GetStateInfo());
			iBattleNum = m_CBattleField->InteractAction(1, m_CPlayer);
		}
		
		break;
	default:
		//	SelectAction(); 
		break;
	}
}

void CGameManger::StartGame()
{
	InitGame();
	//UpdateGame();
	// �ڻ�Ӽ� : CObject �ڷ������� m_CPlayer�� �����ϸ�
	//           CObject�� CPlayerŬ���� ����Լ��� ������ �� ���� ������ ������ ����.
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
	void* mapData = m_CMap->GetMapData();

	POSITION* returnPosition = nullptr;
	POSITION playerPosition = m_CPlayer->GetPosition();
	tagStateInfo playerStateInfo = m_CPlayer->GetStateInfo();

	int objectNumber = 0;
	while (1)
	{
		if (!m_bIsDrawingMap)
		{
			m_CGraphics.InitDrawMap((int(*)[20])mapData, &playerPosition);
			m_CGraphics.DrawPlayerInfo(m_CPlayer->GetStateInfo());
			m_bIsDrawingMap = true;
		}
		
		returnPosition
		= m_CGraphics.UpdateDrawMap((int(*)[20])mapData, objectNumber, &playerPosition);

		// returnPosition�� nullptr�� �ƴϸ�	
		if (returnPosition != nullptr)
		{
			// objectNumber ������Ʈ�� ��ȣ�ۿ��� �����մϴ�.
			InteractionObject(objectNumber);
			
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
