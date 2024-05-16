#pragma once

#define SAFE_DELETE(p) if(p){ delete p; p = nullptr;} // 들여 쓰기 하고 싶다면 \ 추가
#define SAFE_DELETE_ARRAY(p) if(p){ delete p[]; p = nullptr;}

#ifdef _DEBUG // _DEBUG가 정의 되어 있다면

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW // DBG_NEW가 정의 되어 있지 않다면
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#define WALL_MARK "■"
#define NONE_MARK_NUM 0

#define PLAYER_MARK_NUM 1
#define PLAYER_MARK "◎"

#define NPC_MARK_NUM 2
#define NPC_MARK "▣"

#define BATTLE_MARK_NUM 3
#define BATTLE_MARK "※"