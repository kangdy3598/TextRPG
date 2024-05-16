#pragma once

#include <iostream>
#include <string>

#include "_pch.h"

// OBJECT PARENT CLASS
typedef struct __tagPOINT
{
	int x;
	int y;

	//__tagPOINT(int _x,  int _y) { this->x = _x; this->y = _y; }
	__tagPOINT() : x(0), y(0) {};
	__tagPOINT(int _x,  int _y) : x(_x), y(_y) {};
}POSITION;

using namespace std;
