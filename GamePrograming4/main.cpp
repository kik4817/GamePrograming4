/*
* �ۼ��� : 2025-05-13
*/

/*
* �ڷ� ����(Data Structure)
* 
* Data      : ���ӿ� �����ϴ� ���� ��ǻ�Ͱ� �ؼ��� �� �ֵ��� �ۼ��� ��
* Structure : ����, ���� | ���꼺, ������
* 
* �����͸� �����ؾ� �ϴ� ����?
* STL(Standard Template Library)
* ǥ�� : �ſ��� �� �ִ�, ���������� ���� ����Ѵ�
* ���ø� : �Ϲ�ȭ ���α׷����� �����ϱ� ���� ����
* ���̺귯�� : ������� �Լ�, Ŭ����
* 
* �����̳� : Ư���� ������ ���� ��Ƴ��� ��ü
* �˰��� : �����̳� �ȿ� �ִ� �����͸� ����ϴ� �Լ� ���̺귯��
* �ݺ��� : �˰��� �ڵ带 �����ϰ� ����ϱ� ���� ����
*/

/*
* array, vector, list, stack, queue, priority queue, hash-set, map
* � ��쿡 ������ ����ؾ� �ϴ°�?
* - �� �� �ڵ忡�� �� �ڷᱸ���� ����߳���? <<
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Template.h"
#include "Sample.h"
using namespace std;

int main()
{
	cout << "�ڷ� ���� ����" << endl;
	
	// ������ ������ 3�� �����ϰ� �ִ� 'nums' vector
	std::vector<int> nums = { 1,5,3, 10, 2, 4 };

	// ������ ���1. 1, 5, 3
	cout << "������ ���1 " << endl;
	for (auto& num : nums)
	{
		cout << num << " ";
	}

	cout << endl;


	// �����͸� �����Ѵ�
	std::sort(nums.begin(), nums.end());

	// ������ ���2. 1, 3, 5
	cout << "������ ���2 " << endl;

	// 'nums' �ȿ� �ִ� ������ Ÿ�� ������Ҹ� ��ΰ� �����Ѵ�
	for (auto& num : nums) 
	{
		cout << num << " ";
	}

	cout << endl;

	cout << "���ø� ����" << endl;

	// Ÿ�� ����

	int num = Add<int>(2, 5);
	cout << num << endl;

	int num1 = Add(1, 4);
	double num2 = Add(1.5, 4.2);
	int num3 = Add('b', 'a');
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	Example1();

}