#pragma once


#define PUSH_RIGHT "                     "

// KEY INPUT CLASS
#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define ENTER_KEY 13

enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

class CPlayer;
class CBattleField;
class CGraphics
{
private:
	
private:
	void gotoxy(int _x, int _y);
	void SetColor(unsigned short text);
	
	// TITLE FUNCTION ==================================================
	void DrawTitle();
	int DrawTitleMenu(bool _bLoadPlayerInfo);
	int InputTitleMenu(int _posX, int _posY, bool _bLoadPlayerInfo);
	void SetMenuArrow(int _posX, int _posY, int _selectNum);

	// MAP FUNCTION ====================================================
	
	// BATTLEFIELD FUNCTION ============================================
	
	// 키 입력으로 플레이어를 움직입니다.
	int InputPlayerPos(int _mapData[][20], POSITION* _prevPosition);

	// PLAYER FUNCTION =================================================
	
	

	void DrawEnemyInfo();
	void DrawBattle();

public:
	// 타이틀 화면을 그립니다.
	int DrawTitleScreen(bool _bLoadPlayerInfo);

	// 처음으로 맵을 그립니다.
	void InitDrawMap(int _mapData[][20], POSITION* _position);

	// 맵을 갱신하여 그립니다.
	POSITION* UpdateDrawMap(int _mapData[][20], int& _hitObject, POSITION* _position);
	
	// 플레이어 정보를 담은 UI를 그립니다.
	void DrawPlayerInfo(tagStateInfo tagStateInfo);

	int DrawSelectJobScreen();

	int DrawSelectBattleField();

	void DrawBattleScreen();
};