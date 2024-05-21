#include "../_stdafx.h"
#include "conio.h"
#include "Windows.h"

#include "../Player/Player.h"
#include "../Enemy/BattleField.h"
#include "Graphics.h"

// TITLE FUNCTION =================================================================
int CGraphics::DrawTitleScreen(bool _bLoadPlayerInfo)
{
	DrawTitle();
	return DrawTitleMenu(_bLoadPlayerInfo);
}

void CGraphics::DrawTitle()
{
	/////////////////////////////////////////////////////////////
	gotoxy(0, 5);
	cout << PUSH_RIGHT;
	cout << " ********** ******** **     ** **********   *******   *******    ******** " << endl;
	cout << PUSH_RIGHT;
	cout << "/////**/// /**///// //**   ** /////**///   /**////** /**////**  **//////**" << endl;
	cout << PUSH_RIGHT;
	cout << "    /**    /**       //** **      /**      /**   /** /**   /** **      //" << endl;
	cout << PUSH_RIGHT;
	cout << "    /**    /*******   //***       /**      /*******  /******* /**         " << endl;
	cout << PUSH_RIGHT;
	cout << "    /**    /**////     **/**      /**      /**///**  /**////  /**    *****" << endl;
	cout << PUSH_RIGHT;
	cout << "    /**    /**        ** //**     /**      /**  //** /**      //**  ////**" << endl;
	cout << PUSH_RIGHT;
	cout << "    /**    /******** **   //**    /**      /**   //**/**       //********" << endl;
	cout << PUSH_RIGHT;
	cout << "    //     //////// //     //     //       //     // //         ////////  " << endl;

	/////////////////////////////////////////////////////////////
}

int CGraphics::DrawTitleMenu(bool _bLoadPlayerInfo)
{
	int startPosX = 46;
	int startPosY = 20;

	gotoxy(startPosX, startPosY);
	cout << "┌─────────────────────────┐" << endl;

	gotoxy(startPosX, startPosY + 1);
	cout << "│                         │" << endl;
	
	gotoxy(startPosX, startPosY + 2);
	cout << "│         새로하기        │" << endl;
	
	gotoxy(startPosX, startPosY + 3);
	cout << "│                         │" << endl;
	
	gotoxy(startPosX, startPosY + 4);
	cout << "│         종료하기        │" << endl;
	
	gotoxy(startPosX, startPosY + 5);
	cout << "│                         │" << endl;
	
	gotoxy(startPosX, startPosY + 6);
	cout << "└─────────────────────────┘" << endl;

	gotoxy(startPosX + 10, startPosY + 3);
	if (!_bLoadPlayerInfo) SetColor(DARK_GRAY);
	cout << "이어하기";

	return InputTitleMenu(startPosX, startPosY, _bLoadPlayerInfo);
}

int CGraphics::InputTitleMenu(int _posX, int _posY, bool _bLoadPlayerInfo)
{
	int selectNum = 0;

	SetColor(GRAY);
	while (1)
	{
		SetMenuArrow(_posX + 7, _posY + 2, selectNum);
		int temp = _getch();
		switch (temp)
		{
		case DOWN_KEY:
			if (selectNum < 2)
			{
				if (_bLoadPlayerInfo)
					selectNum++;
				else
					selectNum = 2;
			}
			break;
		case UP_KEY:
			if (selectNum >  0)
			{
				if (_bLoadPlayerInfo)
					selectNum--;
				else
					selectNum = 0;
			}
			break;
		case ENTER_KEY:
			return selectNum;
		default:
			break;
		}
	}
}

void CGraphics::SetMenuArrow(int _posX, int _posY, int _selectNum)
{
	gotoxy(_posX, _posY); cout << "  " << endl;
	gotoxy(_posX, _posY + 1); cout << "  " << endl;
	gotoxy(_posX, _posY + 2); cout << "  " << endl;

	gotoxy(_posX, _posY + _selectNum); cout << "▶" << endl;
	gotoxy(0, _posY + 7);
}

// MAP FUNCITON ===================================================================
void CGraphics::InitDrawMap(int _mapData[][20], POSITION* _position)
{
	// 테두리
	system("cls");
	for (int i = 0; i < 60; i++) cout << WALL_MARK;
	gotoxy(0, 0);
	for (int i = 0; i < 20; i++) cout << WALL_MARK << endl;
	for (int i = 0; i < 60; i++) cout << WALL_MARK;
	for (int i = 0; i < 20; i++)
	{
		gotoxy(118, i); cout << WALL_MARK;
	}

	// 아이콘 출력
	for (int i = 0; i < 19; i++)
	{
		gotoxy(2, 1 + i);
		for (int j = 0; j < 58; j++)
		{
			switch (_mapData[j][i])
			{
			case PLAYER_MARK_NUM:
				cout << PLAYER_MARK;
				_position->x = j;
				_position->y = i;
				break;
			case NPC_MARK_NUM:
				cout << NPC_MARK;
				break;
			case BATTLE_MARK_NUM:
				cout << BATTLE_MARK;
				break;
			case SHOP_MARK_NUM:
				cout << SHOP_MARK;
				break;
			default:
				cout << "  ";
				break;
			}
		}

	}
}

POSITION* CGraphics::UpdateDrawMap(int _mapData[][20], int& _hitObject, POSITION* _position
, bool& _test)
{
	// InputPlayerPos를 통해 플레이어를 이동합니다.
	// 이동한 곳에 오브젝트(NPC, 포탈 등)이 있으면 부딪힌 오브젝트를 hitObject에 반환 합니다.
	// 부딪히기 전의 위치를 returnPosition에 저장합니다.
	_hitObject = InputPlayerPos(_mapData, _position, _test);

	// 부딪힌 오브젝트가 있으면 부딪히기 전의 위치(의 주소)를 반환 합니다.
	if (_hitObject != 0) return _position;
	else return nullptr;
}

int CGraphics::InputPlayerPos(int _mapData[][20], POSITION* _position, bool& _test)
{
	POSITION prevPosition = *_position;
	
	// 플레이어 이동
	int temp = _getch();

	switch (temp)
	{
	case DOWN_KEY:
		_position->y += 1;
		break;
	case UP_KEY:
		_position->y -= 1;
		break;
	case LEFT_KEY:
		_position->x -= 1;
		break;
	case RIGHT_KEY:
		_position->x += 1;
		break;

	case INVEN_KEY:
		if (m_iInfoType == 1) m_iInfoType = 2;
		else m_iInfoType = 1;
		_test = false;
		break;
	}

	// 이동 후 맵데이터 갱신
	int returnMarkNum = _mapData[_position->x][_position->y];

	switch (_mapData[_position->x][_position->y])
	{
	case PLAYER_MARK_NUM:
		_position = &prevPosition;
		return NONE_MARK_NUM;

	case NONE_MARK_NUM:
		_mapData[prevPosition.x][prevPosition.y] = NONE_MARK_NUM;
		gotoxy((prevPosition.x + 1) * 2, prevPosition.y + 1);
		cout << "  " << endl;
		
		_mapData[_position->x][_position->y] = PLAYER_MARK_NUM;
		gotoxy((_position->x+1) * 2, _position->y+1);
		cout << PLAYER_MARK << endl;
		return NONE_MARK_NUM;

	case NPC_MARK_NUM:	
	case BATTLE_MARK_NUM:
	case SHOP_MARK_NUM:
		_position = &prevPosition;
		return returnMarkNum;
	}

	return NONE_MARK_NUM;
}

// BATTLEFIELD FUNCTION ==========================================================
int CGraphics::DrawSelectBattleField()
{
	int iSelectNum(0);
	/*gotoxy(0, 0);
	cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
	cin >> iSelectNum;*/

	return iSelectNum;
}

void CGraphics::DrawBattleScreen()
{
	//DrawPlayerInfo();
}

void CGraphics::DrawInfo(tagPlayerInfo _tagPlayerInfo, int _infoType)
{
	if (_infoType == 0) _infoType = m_iInfoType;
	switch (_infoType)
	{
	case 1:
		DrawPlayerStateInfo(_tagPlayerInfo);
		break;
	case 2:
		DrawPlayerInventory(_tagPlayerInfo);
		break;
	default:
		break;
	}
}

void CGraphics::DrawPlayerStateInfo(tagPlayerInfo _tagPlayerInfo)
{
	// 테두리
	gotoxy(0, 22);
	for (int i = 0; i < 60; i++) cout << WALL_MARK;

	gotoxy(0, 22);
	for (int i = 0; i < 7; i++) cout << WALL_MARK << endl;
	for (int i = 0; i < 60; i++) cout << WALL_MARK;
	for (int i = 22; i < 29; i++)
	{
		gotoxy(118, i); cout << WALL_MARK;
	}

	gotoxy(5, 25); cout << "직업 : " << _tagPlayerInfo.szName;
	gotoxy(5, 27); cout << "레벨 : " << _tagPlayerInfo.iLevel;
	
	gotoxy(25, 27); cout << "체력 : " <<
		_tagPlayerInfo.iNowHP << " / " << _tagPlayerInfo.iMaxHP;
	gotoxy(45, 27); cout << "마나 : " << 
		_tagPlayerInfo.iNowMP << " / " << _tagPlayerInfo.iMaxMP;
	gotoxy(65, 27); cout << "경험치 : " <<
		_tagPlayerInfo.iNowExp << " / " << 100;
	
	gotoxy(45, 25); cout << "공격력 : " << _tagPlayerInfo.iAttackPower;
	gotoxy(65, 25); cout << "방어력 : " << _tagPlayerInfo.iDefensePower;

	gotoxy(85, 25); cout << "인벤토리 열기(i)";
	gotoxy(85, 27); cout << "퀘스트 열기(q)";
	gotoxy(0, 0);
}

// SHOP FUNNTION =================================================================
void CGraphics::DrawShopItemList()
{
	int width = 20;
	int height = 20;
	// 아이템 리스트 테두리
	gotoxy(0, 0);
	for (int i = 0; i < width; i++) cout << WALL_MARK;

	gotoxy(0, 0);
	for (int i = 0; i < height; i++) cout << WALL_MARK << endl;
	for (int i = 0; i < width; i++) cout << WALL_MARK;
	for (int i = 0; i < height; i++)
	{
		gotoxy(width + 18, i); cout << WALL_MARK;
	}

	gotoxy(0, 5);
	for (int i = 0; i < width; i++) cout << WALL_MARK;
	width = 37;
	height = 20;
	// 아이템 정보 테두리
	gotoxy(45, 0);
	for (int i = 0; i < width; i++) cout << WALL_MARK;
	for (int i = 0; i < height; i++)
	{
		gotoxy(45, i);
		cout << WALL_MARK;
	}
	gotoxy(45, height);
	for (int i = 0; i < width; i++) cout << WALL_MARK;
	for (int i = 0; i < height; i++)
	{
		gotoxy(width + 35 + 45, i);
		cout << WALL_MARK;
	}

	
	while (1)
	{
		ShowItemDescription();
		SetItemMenu();
		InputShopMenu();
	}
}

int CGraphics::InputShopMenu()
{
	int temp = _getch();

	switch (temp)
	{
	case DOWN_KEY:
		if (m_iSelectItemNum < 5) m_iSelectItemNum++;
		break;
	case UP_KEY:
		if (m_iSelectItemNum > 1) m_iSelectItemNum--;
		break;
	case LEFT_KEY:
		if (m_iSelectItemList == 2) m_iSelectItemList--;
		break;
	case RIGHT_KEY:
		if (m_iSelectItemList == 1) m_iSelectItemList++;
		break;
	case ENTER_KEY:
		break;
	}

	return 0;
}

int CGraphics::SetItemMenu()
{
	if (m_iSelectItemList == 1)
	{
		SetColor(RED);
		gotoxy(10, 2); cout << "장비";
		SetColor(GRAY);
		gotoxy(24, 2); cout << "소비";
		SetEquipList();
	}
	
	else
	{
		SetColor(GRAY);
		gotoxy(10, 2); cout << "장비";
		SetColor(RED);
		gotoxy(24, 2); cout << "소비";
		SetUseList();
	}
	

	
	return 0;
}

void CGraphics::SetEquipList()
{
	SetColor(RED);
	gotoxy(3, 5 + m_iSelectItemNum + 1);
	cout << "         " << m_iSelectItemNum << ". 장비 아이템";

	SetColor(GRAY);
	for (int i = 1; i < 6; i++)
	{
		if (m_iSelectItemNum == i) continue;
		gotoxy(3, i + 5 + 1);
		cout << "         " << i << ". 장비 아이템";
	}
}

void CGraphics::SetUseList()
{
	SetColor(RED);
	gotoxy(3, 5 + m_iSelectItemNum + 1);
	cout << "         " << m_iSelectItemNum << ". 소비 아이템";

	SetColor(GRAY);
	for (int i = 1; i < 6; i++)
	{
		if (m_iSelectItemNum == i) continue;
		gotoxy(3, i + 5 + 1);
		cout << "         " << i << ". 소비 아이템";
	}
}

void CGraphics::ShowItemDescription()
{
	gotoxy(50, 1);
	cout << m_iSelectItemNum << "번 ";
	if (m_iSelectItemList == 1) cout << "장";
	else cout <<"소";
	cout << "비 아이템에 대한 설명이다.";

	gotoxy(90, 17);
	cout << "구매 하기   ";
	cout << "뒤로 가기";
}

void CGraphics::DrawPlayerInventory(tagPlayerInfo _tagPlayerInfo)
{
	// 테두리
	gotoxy(0, 22);
	for (int i = 0; i < 60; i++) cout << WALL_MARK;

	gotoxy(0, 22);
	for (int i = 0; i < 7; i++) cout << WALL_MARK << endl;
	for (int i = 0; i < 60; i++) cout << WALL_MARK;
	for (int i = 22; i < 29; i++)
	{
		gotoxy(118, i); cout << WALL_MARK;
	}

	gotoxy(0, 0);
	gotoxy(85, 25); cout << "보유 골드 : " << _tagPlayerInfo.tagInvenInfo.iGold;
}

// ETC USEFUL FUNCTION ==========================================================

void CGraphics::gotoxy(int _x, int _y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = _x;
	pos.Y = _y;
	SetConsoleCursorPosition(handle, pos);
}

void CGraphics::SetColor(unsigned short text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void CGraphics::DrawLine(int _width, int _height)
{

}