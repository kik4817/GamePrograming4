/*
* �ۼ��� : 2025-05-19
*/

/*
* �����͸� �����ϴ� Ŭ����
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
		cout << "Ű�� �Է��ϸ� ���� ������ ����˴ϴ�" << endl;
		_getch(); // Ű�Է½� �������� ����
	}
}