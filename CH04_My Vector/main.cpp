/*
* 작성일 : 2025-05-19
*/

/*
* 데이터를 저장하는 클래스
* T value. pointer
*/

#include "ConsoleUtility.h"
#include "CustomVector.h"
#include "RandomEncount.h"


int main()
{
	//test1();
	//test2();

	Player player;

	while (true)
	{
		system("cls");
		Battle(player);
		player.display();
		cout << "키를 입력하면 다음 전투가 진행됩니다" << endl;
		_getch(); // 키입력시 다음으로 진행
	}
}