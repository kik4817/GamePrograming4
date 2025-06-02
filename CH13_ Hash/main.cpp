#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsoleUtility.h"

#pragma region 해쉬 함수가 무엇인가?

/*
* Hash Function : Hashing하다의 의미?
* - 전달하는 타입을 특정한 규칙으로 다른 타입으로 변환하는 작업.
* Hashing 결과로 데이터를 재정렬해서 사용할 수 있다.
*/

/*
* Hash만든 자료구조의 장점?
* 
* map보다 데이터 접근이 빠르고, 데이터 탐색이 빠르다.
*/

int HashFunction(int input)
{
	return input % 10; // 0 ~ 9
}

void Test1()
{
	HashFunction(252349429); // 252349429 -> 9

	// unordered_map : [key - value] :: 9라는 해쉬값에는 252349429숫자가 들어있습니다.

	std::unordered_map<std::string, int> umap;

	umap.insert({ "바나나", 5 });
	umap.insert({ "사과", 3 });	

	std::cout << "예제 1" << std::endl;
	std::cout << "바나나의 갯수 : " << umap["바나나"] << std::endl;

	std::cout << "예제 2" << std::endl;
	std::cout << "파인애플이 존재하나요?" << std::endl;

	auto it = umap.find("파인애플");
	if (it != umap.end())
	{
		std::cout << "찾았습니다." << std::endl;
	}
	else
	{
		std::cout << "찾지못했습니다." << std::endl;
	}
}


#pragma endregion

#pragma region map과 unordered_map 비교

/*
* 탐색하는데 unorderd_map이 map보다 빠르다.
* 데이터의 수가 많으면 많을수록 unorderd_map이 좋습니다.
* unorderd_map이 유리하다.
* 
* 왜 유리할까?
* 데이터를 초기화할 때 절리는 시간
* 순차 컨테이너 > 연관 컨테이너 (map) > unordered_map (해시함수가 구현되었고, 해시함수로 저장하는 내부 데이터)
* 
* 해시함수의 단점
* - 해싱충돌이 발생할 때 성능저하가 발생할 수 있다.
*/

void MapTimeTest()
{
	std::map<std::string, int> map;

	map.insert({ "A", 1 });
	map.insert({ "B", 1 });
	map.insert({ "C", 1 });
	map.insert({ "D", 1 });
	map.insert({ "E", 1 });

	for (int i = 0;i < 1000;i++)
	{
		map.find("A");
	}

}

void UMapTimeTest()
{
	std::map<std::string, int> umap;

	umap.insert({ "A", 1 });
	umap.insert({ "B", 1 });
	umap.insert({ "C", 1 });
	umap.insert({ "D", 1 });
	umap.insert({ "E", 1 });

	for (int i = 0;i < 1000;i++)
	{
		umap.find("A");
	}

}

void Test2()
{
	std::cout << "첫번째 비교 : 데이터 입력 시간 비교" << std::endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);

	std::cout << "map 장점 : 데이터의 자동 정렬이 발생한다." << std::endl;
	std::cout << "정렬이된 데이터를 필요할 때 map이 유용하다." << std::endl;;

	std::cout << "그 이외에 컨테이너안에 빠르게 데이터를 찾고 변경하고 싶다." << std::endl;

	std::cout << "두번째 비교 :: 데이터 검색 시간 비교" << std::endl;
	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);
}

#pragma endregion

int main()
{
	//Test1();
	Test2();
}