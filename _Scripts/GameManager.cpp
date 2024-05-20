#include "_stdafx.h"
#include "GameManager.h"

CGameManger::CGameManger()
{
	m_CPlayer = nullptr;
	m_CDownPlayer = (CPlayer*)m_CPlayer;
	m_CEnemy = nullptr;
	m_CNPC = nullptr;
	m_CMap = nullptr;
	m_CBattleField = nullptr;

	m_bIsDrawingMap = false;
}

CGameManger::~CGameManger()
{
}

bool CGameManger::StartGame()
{
	InitGame();

	//UpdateGame();
	// �ڻ�Ӽ� : CObject �ڷ������� m_CPlayer�� �����ϸ�
	//           CObject�� CPlayerŬ���� ����Լ��� ������ �� ���� ������ ������ ����.
	bool bLoadPlayerInfo = false/*m_CPlayer->LoadInfo()*/; 
	switch (m_CGraphics.DrawTitleScreen(bLoadPlayerInfo))
	{
	case RUNNING - 1:
		m_CGraphics.DrawSelectJobScreen();
		((CPlayer*)m_CPlayer)->SelectJob();
	case RUNNING:
		return true;
	case EXIT:;
		return false;
	default:
		break;
	}

	return false;
}

void CGameManger::UpdateGame()
{
	void* mapData = m_CMap->GetMapData();

	POSITION* returnPosition = nullptr;
	POSITION playerPosition = m_CPlayer->GetPosition();

	int objectNumber = 0;
	while (1)
	{
		if (!m_bIsDrawingMap)
		{
			m_CGraphics.InitDrawMap((int(*)[20])mapData, &playerPosition);
			m_CGraphics.DrawPlayerInfo(((CPlayer*)m_CPlayer)->GetObjectInfo());
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

	if (m_CNPC)
	{
		m_CNPC->Release();
		delete m_CNPC;
		m_CNPC = 0;
	}

	if (m_CMap)
	{
		//m_CMap->Release();
		delete m_CMap;
		m_CMap = 0;
	}

	if (m_CBattleField)
	{
		//m_CMap->Release();
		delete m_CBattleField;
		m_CBattleField = 0;
	}
}

void CGameManger::InitGame()
{
	m_CPlayer = new CPlayer;
	if (!m_CPlayer) return;

	m_CMap = new CMap;
	if (!m_CMap) return;

	m_CNPC = new CNPC;
	if (!m_CNPC) return;

	char temp_script[][256] =
	{ "�ʱ� ����, �߱� ����, ��� ���� ���� �� ������ ��� ���ÿ�.",
		"ǥ���� �Ѽ� �� ���� 10����."
	};

	int temp_size = sizeof(temp_script) / sizeof(temp_script[0]);
	m_CNPC->InitNPCInfo("���� ǥ����", temp_script, temp_size);

	m_CBattleField = new CBattleField;
	if (!m_CBattleField) return;

	POSITION temp;
	m_CPlayer->SetPosition(POSITION(14, 5));
	m_CPlayer->GetPosition(temp);
	m_CMap->SetMapData(temp, PLAYER_MARK_NUM);

	m_CNPC->SetPosition(POSITION(25, 5));
	m_CNPC->GetPosition(temp);
	m_CMap->SetMapData(temp, NPC_MARK_NUM);

	m_CBattleField->SetPosition(POSITION(24, 2));
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
			m_CGraphics.DrawPlayerInfo(m_CPlayer->GetObjectInfo());
			iBattleNum = m_CBattleField->InteractAction(1, (CPlayer*)m_CPlayer);
		}

		break;
	default:
		break;
	}
}
