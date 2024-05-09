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
	
	void DrawMapBoard(POSITION& _position, int _mapData[][20]);
	int InputPlayerPos(POSITION _position, int _mapData[][20]);

	// PLAYER FUNCTION =================================================
	
	void DrawPlayerInfo();
	void DrawEnemyInfo();
	void DrawBattle();

public:
	int DrawTitleScreen(bool _bLoadPlayerInfo);

	int DrawSelectJobScreen();

	POSITION* DrawMap(int _mapData[][20], int& _objectNumber);
};