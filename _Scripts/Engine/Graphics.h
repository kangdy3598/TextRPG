#pragma once


#define PUSH_RIGHT "                     "

// KEY INPUT CLASS
#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77

#define INVEN_KEY 105
#define QUEST_KEY 113
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
	int m_iSelectItemNum = 1;
	int m_iSelectItemList = 1;
	int m_iInfoType = 1;

private:
	void gotoxy(int _x, int _y);
	void SetColor(unsigned short text);
	void DrawLine(int _width, int _height);

	// TITLE FUNCTION ==================================================

	void DrawTitle();
	int DrawTitleMenu(bool _bLoadPlayerInfo);
	int InputTitleMenu(int _posX, int _posY, bool _bLoadPlayerInfo);
	void SetMenuArrow(int _posX, int _posY, int _selectNum);

	// MAP FUNCTION ====================================================
	
	// 키 입력으로 플레이어를 움직입니다.
	int InputPlayerPos(int _mapData[][20], POSITION* _prevPosition,bool& _test);

	// BATTLEFIELD FUNCTION ============================================
	// PLAYER FUNCTION =================================================
	
	// 플레이어 정보를 그립니다.
	void DrawPlayerStateInfo(tagPlayerInfo _tagPlayerInfo);

	// 플레이어 인벤토리를 그립니다.
	void DrawPlayerInventory(tagPlayerInfo _tagPlayerInfo);

	// SHOW FUNCTION ===================================================

	int InputShopMenu();
	int SetItemMenu();
	void SetEquipList();
	void SetUseList();
	void ShowItemDescription();
	//void DrawEnemyInfo();
	//void DrawBattle();

	// =================================================================
	
public:
	// 타이틀 화면을 그립니다.
	int DrawTitleScreen(bool _bLoadPlayerInfo);

	// 처음으로 맵을 그립니다.
	void InitDrawMap(int _mapData[][20], POSITION* _position);

	// 맵을 갱신하여 그립니다.
	POSITION* UpdateDrawMap(int _mapData[][20], int& _hitObject, POSITION* _position,
	bool& _test);
	
	int GetInfoType() { return m_iInfoType; }

	// 플레이어 정보를 m_iInforType에 맞게 보여줍니다.
	void DrawInfo(tagPlayerInfo _tagPlayerInfo, int _infoType = 0);
	
	// 상점 정보를 그립니다.
	void DrawShopItemList();

	//int DrawSelectJobScreen();

	int DrawSelectBattleField();

	void DrawBattleScreen(); //
};