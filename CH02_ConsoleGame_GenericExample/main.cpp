/*
* �ۼ��� : 2025-05-15
*/

#include "ConsoleUtility.h"
#include "Pokeball.h"

void Example()
{
	int x = ConsoleUtil::GetRandomInt(10);
	int y = ConsoleUtil::GetRandomInt(10);
	ConsoleUtil::GotoXY(x, y);
	cout << "������ǥ" << endl;
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
			cout << "�� ";
		}
		else
		{
			cout << "�� ";
		}
	}
}

template<int N>
void Display2D(int index)
{
	int height = index / N; // ����
	int width = index % N;  // ����

		for (int y = 0; y < N; y++)
		{
			for (int i = 0;i < N;i++)
			{
				if (i == width && y == height)
				{
					cout << "�� ";
				}
				else
				{
					cout << "�� ";
				}
			}
			cout << endl;
		}
}

/*
* std::array(���� �迭) Fixed size Array
* Ư¡ : ũ�Ⱑ �����Ǿ� �ְ� ��Ģ�� ��Ȯ�� ǥ���� �� �ִ�
* �ǹ� : ũ�Ⱑ ������ �� �ִ� �迭�� ����� ���� ������? vector(���� �迭)
*/

int main()
{
	//Example();

	int selectedIndex = 0;
	char input;

	// ���ϸ����� �����͸� ����
	// PokeMon (�� Ÿ��)          : ������ ����, ũ�Ⱑ ���� ���, �� ��ü�� ���¸� ǥ���� ��
	// PokeMon* (���� Ÿ��, �ּҰ�) : ���縦 ���ϰ� �����͸� �����´�.
	
	// ���� ������ ���� ũ�Ⱑ ũ�� : PokeMon*
	// ���� �� ������ ����, ���°� �����ϱ� ������ ������ ǥ��

	ConsoleUtil::SetCursorVisible(false);

	array<PokeMon*, 40> pokeballs;

	PokeMon defaultMonster(0, "");
	pokeballs.fill(&defaultMonster);

	pokeballs[0] = new PokeMon(1, "�̻��ؾ�");
	pokeballs[1] = new PokeMon(4, "���̶�");
	pokeballs[2] = new PokeMon(25, "��ī��");
	pokeballs[3] = new PokeMon(7, "���α�");

	// Ű���� �����¿� �Է��� �޾Ƽ� �������� �����ϴ� �׸� ���
	while (true)
	{
		
		const int size = 6;
		int sizePow = size * size;

		
		//Display<size>(selectedIndex); // ���� ������ �������� �����ִ� Display �Լ� �����
		ConsoleUtil::GotoXY(0, 0);
		Display2D<size>(selectedIndex);

		input = _getch();

		if (input == LEFT)
		{
			//cout << "���� ȭ��Ű�� �Է�";
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

		system("cls"); // ȭ�������
		//cout << selectedIndex << endl;
		ConsoleUtil::GotoXY(30, 0);
		cout << "���� UI";
		ConsoleUtil::GotoXY(30, 1);
		cout << "NO. "<<pokeballs[selectedIndex]->get_number()<<pokeballs[selectedIndex]->get_name() << endl;
		//input = _getch();
	}

}