#pragma once

#include <iostream>
#include <random>
#include <Windows.h>
#include <conio.h> // _getch
#include <string>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;

class ConsoleUtil
{
public:
	static void GotoXY(int x, int y)
	{
		COORD pos = { static_cast<short>(x), static_cast<short>(y) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static int GetRandomInt(int max)
	{
		static std::random_device rd; // �õ� ������
		static std::mt19937 gen(rd()); // Mersenne Twister ����
		std::uniform_int_distribution<> dist(1, max); // 1���� max������ ������ ���� ����
		return dist(gen); // ��
	}

	//static void SetCursorVisible(bool visible)
	//{
	//	CONSOLE_CURSOR_INFO c = { 0 };
	//	c.dwSize = 1;
	//	c.bVisible = 
	//}
};
