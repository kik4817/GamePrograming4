/*
* 작성일 : 2025.05.22
*/

#include "GameModel.h"
#include "conio.h"
#include "DropTable.h"
#include "DataHandler.h".h"

/*
* 경험치 테이블 만든다.
* 1레벨 - 100
* 2레벨 - 100
* 3레벨 - 100
* 4레벨 - 150
* 5레벨 - 150 
*/

int main()
{
	Player player(0, 100); // exp0, level1, maxexp10
	Monster monster(0, 0);
	
	player.LoadData("player.txt");

	Data data;
	//data.SaveData("data.txt");
	data.LoadData("data.txt");

	std::cout << "data의 level : " << data.level << " exp : " << data.exp << std::endl;
	//std::cout << "player의 level : " << player.level << " exp : " << player.exp << std::endl;

	//monster.Drop();
	_getch();

	int count = 0;

	while (true)
	{
		system("cls");
		player.GetExp(30);
		player.Show();		
		_getch();

		if (count >= 4)
		{
			break;
		}
	}

	player.SaveData("player.txt");
}