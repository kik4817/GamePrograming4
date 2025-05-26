#pragma once

#include <iostream>
#include <chrono> // clock기능이 담겨잇는 헤더
#include <vector>
#include <list>

/*
* vector와 list의 차이점
* 
* 1. 임이의 데이어에 접근하는 시간을 비교한다.
* 
* 결과 : vecotr는 바로 임이의 데이터에 접근할 수 있다. 빠르다
*		list는 n번째 데이터에 접근하는데 길이에 비례해서 시간이 걸린다. (linear time)
* 
* 2. 첫번째와 끝의 데이터가 아닌 데이터를 삭제 또는 수정하는데 걸리는 시간
* - 데이터를 자주 삭제 또는 수정하는 경우게 Vector의 시간이 비효율적이다.
* - 1~N 데이터 -> 1~N-1개 데이터로 옮기는 작업
* 
* 데이터 지우거나, 변경하는 작업이 많으면 많을수록 vector가 시간이 비효율적이다.
*/

/*
* (번외) 어떠한 자료구조를 써야할 지 잘모르겠으면, vector로 만들어보세요
* vecctor 무엇을 했을 때 시간이 더 오래걸릴까?
*/

void TimeCheckTest()
{
	std::cout << "특정 기능이 얼마나시간이 걸리는지 측정하는 코드입니다." << std::endl;
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
	std::cout << "list의 시간을 측정합니다." << std::endl;
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