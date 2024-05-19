#include "_stdafx.h"
#include "GameManager.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CGameManger cGameManager;

	
	if(cGameManager.StartGame())
		cGameManager.UpdateGame();
	cGameManager.EndGame();
}

