#pragma once

#include <iostream>

/*
* 1단계 : 함수선언 ( (반환값)(*호출할함수이름)() )
* 2단계 : 호출할 함수의 인자가 있는경우
* 함수선언 ( (반환값)(*호출할함수이름)(타입 이름, 타입 이름), 타입 이름, 타입 이름
*/

void Add(int a, int b)
{
	std::cout << "더하기 실행" << std::endl;
	std::cout << a + b << std::endl;
}

void Minus(int a, int b)
{
	std::cout << "빼기 실행" << std::endl;
	std::cout << a - b << std::endl;
}

// 곱하기와 나누기
void Multiply(int a, int b)
{
	std::cout << "곱하기 실행" << std::endl;
	std::cout << a * b << std::endl;
}

void Divide(int a, int b)
{
	std::cout << "나누기 실행" << std::endl;
	std::cout << a / b << std::endl;
}

void Calculate(void (*Func)(int a, int b), int a, int b)
{
	Func(a,b);
}

void Test()
{
	// 더하기
	Calculate(Minus, 1, 2);

	// 빼기
	Calculate(Minus, 2, 1);

	// 곱하기
	Calculate(Multiply, 5, 5);

	// 나누기
	Calculate(Divide, 6, 3);
}