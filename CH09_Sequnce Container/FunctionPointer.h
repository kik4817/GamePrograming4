#pragma once

#include <iostream>

/*
* 1�ܰ� : �Լ����� ( (��ȯ��)(*ȣ�����Լ��̸�)() )
* 2�ܰ� : ȣ���� �Լ��� ���ڰ� �ִ°��
* �Լ����� ( (��ȯ��)(*ȣ�����Լ��̸�)(Ÿ�� �̸�, Ÿ�� �̸�), Ÿ�� �̸�, Ÿ�� �̸�
*/

void Add(int a, int b)
{
	std::cout << "���ϱ� ����" << std::endl;
	std::cout << a + b << std::endl;
}

void Minus(int a, int b)
{
	std::cout << "���� ����" << std::endl;
	std::cout << a - b << std::endl;
}

// ���ϱ�� ������
void Multiply(int a, int b)
{
	std::cout << "���ϱ� ����" << std::endl;
	std::cout << a * b << std::endl;
}

void Divide(int a, int b)
{
	std::cout << "������ ����" << std::endl;
	std::cout << a / b << std::endl;
}

void Calculate(void (*Func)(int a, int b), int a, int b)
{
	Func(a,b);
}

void Test()
{
	// ���ϱ�
	Calculate(Minus, 1, 2);

	// ����
	Calculate(Minus, 2, 1);

	// ���ϱ�
	Calculate(Multiply, 5, 5);

	// ������
	Calculate(Divide, 6, 3);
}