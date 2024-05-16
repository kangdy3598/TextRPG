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
	{	"초급 몬스터, 중급 몬스터, 고급 몬스터 각각 한 마리씩 잡아 오시오.",
		"표지판 훼손 시 벌금 10만원."
	};

	int temp_size = sizeof(temp_script) / sizeof(temp_script[0]);
	m_CNPC->InitNPCInfo( "수배 표지판", temp_script, temp_size);

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
	// ★상속성 : CObject 자료형으로 m_CPlayer를 생성하면
	//           CObject론 CPlayer클래스 멤버함수를 실행할 수 없기 때문에 오류가 난다.
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

		// returnPosition이 nullptr이 아니면	
		if (returnPosition != nullptr)
		{
			// objectNumber 오브젝트와 상호작용을 시작합니다.
			InteractionObject(objectNumber);
			
			// 상호작용 끝났다면 상호작용 하기 전 위치로 돌아갑니다.
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
