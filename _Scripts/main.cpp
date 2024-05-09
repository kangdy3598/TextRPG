#include "_stdafx.h"
#include "GameManager.h"

//class CTEST
//{
//public:
//	int m_num = 0;
//	CTEST() { cout << "매개변수 없는 생성자\t"; }
//	CTEST(int num) { m_num = num;
//		cout << m_num << " : 생성자\t"; }
//	~CTEST() { cout << m_num << " : 소멸자\t"; }
//
//	void print() { cout << "num :" << m_num << "\t"; }
//};
int main()
{
	//cout << "ctest 생성자" << endl;
	//CTEST ctest[5]{ 1,2,3,4,5 };
	//cout << endl;
	//
	//cout << "=========================================================" << endl;
	//
	//cout << "cctest 생성자" << endl;
	//CTEST* cctest = new CTEST[5];
	//cout << endl;
	//for (int i = 0; i < 5; i++)
	//{
	//	cctest[i].m_num = i+1;
	//}
	//cout << "=========================================================" << endl;
	//cout << "cctest 소멸자" << endl;
	//delete[] cctest;
	//cout << endl;
	//cout << "=========================================================" << endl;
	//cout << "ctest 소멸자" << endl;
	//return 0;
	//system("pause");

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CGameManger cGameManager;

	cGameManager.StartGame();
	cGameManager.UpdateGame();
	cGameManager.EndGame();
}

