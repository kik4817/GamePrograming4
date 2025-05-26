#pragma once

#include <iostream>
#include <chrono> // clock����� ����մ� ���
#include <vector>
#include <list>

/*
* vector�� list�� ������
* 
* 1. ������ ���̾ �����ϴ� �ð��� ���Ѵ�.
* 
* ��� : vecotr�� �ٷ� ������ �����Ϳ� ������ �� �ִ�. ������
*		list�� n��° �����Ϳ� �����ϴµ� ���̿� ����ؼ� �ð��� �ɸ���. (linear time)
* 
* 2. ù��°�� ���� �����Ͱ� �ƴ� �����͸� ���� �Ǵ� �����ϴµ� �ɸ��� �ð�
* - �����͸� ���� ���� �Ǵ� �����ϴ� ���� Vector�� �ð��� ��ȿ�����̴�.
* - 1~N ������ -> 1~N-1�� �����ͷ� �ű�� �۾�
* 
* ������ ����ų�, �����ϴ� �۾��� ������ �������� vector�� �ð��� ��ȿ�����̴�.
*/

/*
* (����) ��� �ڷᱸ���� ����� �� �߸𸣰�����, vector�� ��������
* vecctor ������ ���� �� �ð��� �� �����ɸ���?
*/

void TimeCheckTest()
{
	std::cout << "Ư�� ����� �󸶳��ð��� �ɸ����� �����ϴ� �ڵ��Դϴ�." << std::endl;
	auto Start = std::chrono::high_resolution_clock::now();
	//
	std::vector<int> nums;
	for (int i = 0; i < 100;i++)
	{
		nums.push_back(i);
	}

	for(int i = 0; i < 10; i++)
	{
		auto it = nums.begin();
		nums.erase(it);
	}
	//
	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;	

}

void TimeCheckTest2()
{
	std::cout << "list�� �ð��� �����մϴ�." << std::endl;
	auto Start = std::chrono::high_resolution_clock::now();
	//
	std::list<int> nums;
	for (int i = 0; i < 100;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i<10; i++)
	{
	auto it = std::next(nums.begin(), 10);
	//auto it = nums.begin();
	nums.erase(it);		
	}
	//
	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;
}