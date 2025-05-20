#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

// 찾으면 true, 못찾으면 false
// 찾으면 iterator 변환, 못찾으면 end()
// 데이터 안에 찾는 데이터가 있는지 확인하는 함수
void find_test()
{
	std::cout<<"\n==============" << std::endl;
	std::vector<int> nums = { 1,2,3,4,5 };

	auto it = std::find(nums.begin(), nums.end(), 2);

	if (it != nums.end())
	{
		std::cout << *it << std::endl;
	}
	else
	{
		std::cout << "데이터를 찾지 못했습니다." << std::endl;
	}
}


struct Monster
{
	int id;
	std::string name;

	Monster(int id, std::string name) : id(id), name(name) {}
};

// 알고리즘을 사용한 심화 코드

/*
* std::함수이름(vec.begin(), vec.end(), 정의된 함수, 람다식, 필터
* 
* 1. funstion pointer
* bool (*함수이름)(int x);
* 
* 2. functor : struct 이름() 엣날 문법
* 
* 3. lamda : 함수를 선언하지 않아도 함수를 호출한 것 처럼 사용할 수 있다. 무명 함수
* [](){}
*/

// 홀수
bool IsEven(int x)
{
	return x % 2 != 0;
}

// 짝수
bool IsOdd(int x)
{
	return x % 2 == 0;
}

bool CheckMonster(const Monster& findmon)
{
	return findmon.id == 3;
}

void find_test2()
{
	std::cout << "\n==============" << std::endl;
	//std::map<int, std::string> datas = // 키 = 숫자, 이름

	std::vector<Monster> monsters;
	monsters.emplace_back(1, "피카츄");
	monsters.emplace_back(2, "이상해씨");
	monsters.emplace_back(3, "파이리");
	monsters.emplace_back(4, "꼬부기");

	// monster
	// monster.id	

	// find_if : 3번째 인자에 어떻나 데이터를 찾을 것인가? 조건을 넣어준다
	// 함수, functor, 람다식

	auto it = std::find_if(monsters.begin(), monsters.end(),
		[](const Monster& findmon) {return findmon.id == 3;});
	
	std::cout << it->name << std::endl;

	std::cout << std::endl;
	std::cout << "람다식 예제" << std::endl;
	
	auto it2 = std::find_if(monsters.begin(), monsters.end(), CheckMonster);		

	std::cout << it2->name << std::endl;
}

struct Square_Functor
{
	void operator()(int x)
	{
		std::cout << x*x << " ";
	}
};

void for_each_test()
{
	std::vector<int> nums = { 1,3,5 };
	Square_Functor square;
	//std::for_each(nums.begin(), nums.end())
}

void find_test3()
{
	std::vector<int> nums = { 1,2,3,4,5 };
	if (std::all_of(nums.begin(), nums.end(), IsEven))
	{
		std::cout << "nums의 모든 데이터가 홀수 입니다." << std::endl;
	}
	else
	{
		std::cout << "짝수가 num에 존재합니다." << std::endl;
	}
}
