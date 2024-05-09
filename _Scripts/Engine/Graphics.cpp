#include "../_stdafx.h"
#include "conio.h"
#include "Windows.h"
#include "Graphics.h"

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

//================================================================================

POSITION* CGraphics::DrawMap(int _mapData[][20], int& _objectNumber)
{
	POSITION temp;
	DrawMapBoard(temp, _mapData); // 맵 가장자리 장식

	// InputPlayerPos를 통해 플레이어를 이동합니다.
	_objectNumber = InputPlayerPos(temp, _mapData);

	// _objectNumber 값에 따라 리턴 값이 달라집니다.
	if (_objectNumber) return &temp;
	else return nullptr;
}

void CGraphics::DrawMapBoard(POSITION& _position, int _mapData[][20])
{
	system("cls");
	for (int i = 0; i < 60; i++) cout << WALL_MARK;
	gotoxy(0, 0);
	for (int i = 0; i < 20; i++) cout << WALL_MARK << endl;
	for (int i = 0; i < 60; i++) cout << WALL_MARK;
	for (int i = 0; i < 20; i++)
	{
		gotoxy(118, i); cout << WALL_MARK;
	}

	for (int i = 0; i < 19; i++)
	{
		gotoxy(2, 1 + i);
		for (int j = 0; j < 58; j++)
		{
			switch (_mapData[j][i])
			{
			case PLAYER_MARK_NUM:
				_position.x = j;
				_position.y = i;
				cout << PLAYER_MARK;
				break;
			case NPC_MARK_NUM:
				cout << NPC_MARK;
				break;
			case BATTLE_MARK_NUM:
				cout << BATTILE_MARK;
				break;
			default:
				cout << "  ";
				break;
			}
		}
		
	}
	// player state info 로 이전
	//gotoxy(0, 22);
	//for (int i = 0; i < 60; i++) cout << WALL_MARK;
}

int CGraphics::InputPlayerPos(POSITION _position, int _mapData[][20])
{
	POSITION prevPosition = _position;

	// 플레이어 이동
	int temp = _getch();
	switch (temp)
	{
	case DOWN_KEY:
		_position.y += 1;
		break;
	case UP_KEY:
		_position.y -= 1;
		break;
	case LEFT_KEY:
		_position.x -= 1;
		break;
	case RIGHT_KEY:
		_position.x += 1;
		break;
	}
	
	switch (_mapData[_position.x][_position.y])
	{
	case NONE_MARK_NUM:
		_mapData[prevPosition.x][prevPosition.y] = NONE_MARK_NUM;
		_mapData[_position.x][_position.y] = PLAYER_MARK_NUM;

	default:
		return _mapData[_position.x][_position.y];
	}

	return NONE_MARK_NUM;
}

//================================================================================

int CGraphics::DrawSelectJobScreen()
{
	//system("pause");
	return 0;
}

//================================================================================
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
