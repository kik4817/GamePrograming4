#pragma once

#include <iostream>
#include <random>
#include <Windows.h>
#include <conio.h> // _getch
#include <string>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using std::ostream;
using std::vector;

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
		static std::random_device rd; // 시드 생성기
		static std::mt19937 gen(rd()); // Mersenne Twister 엔진
		std::uniform_int_distribution<> dist(1, max); // 1부터 max까지의 균일한 정수 분포
		return dist(gen); // 랜
	}

	static void SetCursorVisible(bool visible)
	{
		CONSOLE_CURSOR_INFO c = { 0 };
		c.dwSize = 1;
		c.bVisible = visible;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
	}

	static void TimeCheck(void (*Func)())
	{
		auto start = std::chrono::high_resolution_clock::now();

		// 함수 포인터
		Func();

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duration = end - start;
		std::cout << duration.count() << "ms시간이 걸렸습니다." << std::endl;
	}
};
