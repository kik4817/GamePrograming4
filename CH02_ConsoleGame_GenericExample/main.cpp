/*
* 작성일 : 2025-05-15
*/

#include "ConsoleUtility.h"
#include "Pokeball.h"

void Example()
{
	int x = ConsoleUtil::GetRandomInt(10);
	int y = ConsoleUtil::GetRandomInt(10);
	ConsoleUtil::GotoXY(x, y);
	cout << "랜덤좌표" << endl;
	while (true)
	{
		int rand = ConsoleUtil::GetRandomInt(100);
		cout << rand << endl;
		Sleep(100);
		//break;
	}
}

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13

template<int N>
void Display(int index)
{
	for (int i = 0;i < N;i++)
	{
		if (i == index)
		{
			cout << "★ ";
		}
		else
		{
			cout << "☆ ";
		}
	}
}

template<int N>
void Display2D(int index)
{
	int height = index / N; // 세로
	int width = index % N;  // 가로

		for (int y = 0; y < N; y++)
		{
			for (int i = 0;i < N;i++)
			{
				if (i == width && y == height)
				{
					cout << "★ ";
				}
				else
				{
					cout << "☆ ";
				}
			}
			cout << endl;
		}
}

/*
* std::array(고정 배열) Fixed size Array
* 특징 : 크기가 고정되어 있고 규칙을 명확히 표현할 수 있다
* 의문 : 크기가 변경할 수 있는 배열로 만들면 되지 않을까? vector(가변 배열)
*/

int main()
{
	//Example();

	int selectedIndex = 0;
	char input;

	// 포켓몬스터의 데이터를 세팅
	// PokeMon (값 타입)          : 데이터 복사, 크기가 작은 경우, 값 자체가 상태를 표현할 때
	// PokeMon* (참조 타입, 주소값) : 복사를 안하고 데이터를 가져온다.
	
	// 몬스터 종류가 많고 크기가 크다 : PokeMon*
	// 몬스터 볼 갯수가 적고, 상태가 존재하기 때문에 값으로 표현

	ConsoleUtil::SetCursorVisible(false);

	array<PokeMon*, 40> pokeballs;

	PokeMon defaultMonster(0, "");
	pokeballs.fill(&defaultMonster);

	pokeballs[0] = new PokeMon(1, "이상해씨");
	pokeballs[1] = new PokeMon(4, "파이라");
	pokeballs[2] = new PokeMon(25, "피카츄");
	pokeballs[3] = new PokeMon(7, "꼬부기");

	// 키보드 상하좌우 입력을 받아서 아이템을 선택하는 그림 출력
	while (true)
	{
		
		const int size = 6;
		int sizePow = size * size;

		
		//Display<size>(selectedIndex); // 현제 선택한 아이템을 보여주는 Display 함수 만든다
		ConsoleUtil::GotoXY(0, 0);
		Display2D<size>(selectedIndex);

		input = _getch();

		if (input == LEFT)
		{
			//cout << "왼쪽 화살키를 입력";
			selectedIndex = (selectedIndex - 1 + sizePow) % sizePow; // 0 ~ 5
		}
		else if (input == RIGHT)
		{
			selectedIndex = (selectedIndex + 1) % sizePow;
		}
		else if (input == UP)
		{
			selectedIndex = (selectedIndex - size + sizePow) % sizePow;
		}
		else if (input == DOWN)
		{
			selectedIndex = (selectedIndex + size) % sizePow;
		}
		else if (input == ENTER)
		{
			break;
		}

		system("cls"); // 화면지우기
		//cout << selectedIndex << endl;
		ConsoleUtil::GotoXY(30, 0);
		cout << "몬스터 UI";
		ConsoleUtil::GotoXY(30, 1);
		cout << "NO. "<<pokeballs[selectedIndex]->get_number()<<pokeballs[selectedIndex]->get_name() << endl;
		//input = _getch();
	}

}