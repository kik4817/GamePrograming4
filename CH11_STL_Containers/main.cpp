#include "ConsoleUtility.h"

// 순차 컨테이너 Sequence Container : vector, list, deque
// #include <컨테이너>

#include <vector>
#include <list>
#include <deque>

// 연간 컨테이너 associate Container : (multi, unordered) set, map

#include <set>
#include <map>
#include <algorithm>

// 1단계 : 순차 컨테이너 데이터 입력 시간 비교
// 2단계 : 순차 컨테이너 중간 데이터 입력 시간 비교
// 3단계 : 갯수와, 중간 데이터 삭제를 비교하여 적합한 순차 컨테이너 사용하기

#pragma region 1단계 : 순차 컨테이너 데이터 입력 시간 비교

void DataPushByVector()
{
	std::vector<int> nums;
	for (int i = 0;i < 1000;i++)
	{
		nums.push_back(i);
	}
}

void DataPushByList()
{
	std::list<int> nums;
	for (int i = 0;i < 1000;i++)
	{
		nums.push_back(i);
	}
}

void DataPushByDeque()
{
	std::deque<int> nums;
	for (int i = 0;i < 1000;i++)
	{
		nums.push_back(i);
	}
}

void Test1()
{
	std::cout << "데이터 입력 시간 비교" << std::endl;
	std::cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(DataPushByVector);
	std::cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(DataPushByList);
	std::cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(DataPushByDeque);

	std::cout << "결과 : 단순 데이터를 입력할 때 vector 가장 빠르다." << std::endl;
	std::cout << std::endl;
}
#pragma endregion

#pragma region 2-1단계 : 순차 컨테이너 중간 데이터 입력 시간 비교

void InsertDataByVector()
{
	std::vector<int> nums;

	for (int i = 0;i < 10;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0;i < 1000;i++)
	{
		auto it = nums.begin() + 5;
		nums.insert(it, 1);
	}
}

void InsertDataByList()
{
	std::list<int> nums;
	
	for (int i = 0;i < 10;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0;i < 1000;i++)
	{
		auto it = std::next(nums.begin(), 5);
		nums.insert(it, 1);
	}
}

void InsertDataByDeque()
{
	std::deque<int> nums;
	
	for (int i = 0;i < 10;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0;i < 1000;i++)
	{
		auto it = nums.begin() + 5;
		nums.insert(it, 1);
	}
}

void Test2()
{
	std::cout << "중간 데이터 입력 시간 비교" << std::endl;
	std::cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	std::cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	std::cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);

	std::cout << "결과 : 처음에 데이터를 입력했을 때 vector가 빠르다." << std::endl;
	std::cout << "결과2 : 중간 삽입(삭제)하는 과정이 많으면 많을수록 list가 빨라 질 수 있다." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region 2-2단계 : 순차 컨테이너 데이터를 맨 앞에 추가할 때 걸리는 시간 비교

void FrontPushByVector()
{
	std::vector<int> nums;

	for (int i = 0;i < 1000;i++)
	{
		auto it = nums.begin();
		nums.insert(it, i);
	}
}

void FrontPushByList()
{
	std::list<int> nums;

	for (int i = 0;i < 1000;i++)
	{		
		nums.push_front(i);
	}
}

// double ended queue

void FrontPushByDeque()
{
	std::deque<int> nums;

	for (int i = 0;i < 1000;i++)
	{
		nums.push_front(i);
	}
}

void Test2_2()
{
	std::cout << "첫번째 위치에 데이터 입력 시간 비교" << std::endl;
	std::cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByVector);
	std::cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByList);
	std::cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByDeque);

	std::cout << "결과 : 첫번째 원소를 넣는 경우에 vector의 장점과 단점을 해결할 수 있다." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region 2-3단계 : 순차 컨테이너에서 랜덤 원소 접근에 걸리는 시간 비교

void RandomAccessByVector()
{
	std::vector<int> nums;

	for (int i = 0;i < 100;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0;i < 50;i++)
	{
		nums[i] = 0;
	}
}

void RandomAccessByList()
{
	std::list<int> nums;

	for (int i = 0;i < 100;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0;i < 50;i++)
	{
		auto it = std::next(nums.begin(), i);
		*it = 0;
	}
}

void RandomAccessByDeque()
{
	std::deque<int> nums;

	for (int i = 0;i < 100;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0;i < 50;i++)
	{
		nums[i] = 0;
	}
}

void Test2_3()
{
	std::cout << "랜덤 위치에 데이터 시간 비교" << std::endl;
	std::cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByVector);
	std::cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByList);
	std::cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByDeque);

	std::cout << "결과 : 배열 형태의 자료구조(vector, deque) 바로 접근할 수 있다." << std::endl;
	std::cout << "list의 경우에는 시작과 거리가 멀면 멀수록 시간이 오래 걸린다." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region 순차 컨테이너 비교
/*       |  Vector  |  List  |  Deque  |
* Push   |    1     |    3   |    2    |
* Insert |    2     |    1   |    3    |
* Front  |    3     |    2   |    1    |
* Access |    1     |    3   |    2    |
*/

/*
* Case1 : 상황 부여, 데이터의 입력이 (많이) 발생을 하고, 중간 데이터 입력이 (적으며), 앞에 데이터(적으며), 랜덤 접근이 (많음) 경우
*/
#pragma endregion

#pragma region 3단계 : 순차 컨테이너와 연관 컨테이너

// 데이터를 저장하는 공간으로 컨테이너를 만들었다.
// std::vector<monster> nums; monster a- nums[?];
// 컨테이너 안에 해당하는 데이터가 없으면? 에러가 발생한다. if(데이터가 존재하나요?) -> 실행

bool Find(int value)
{
	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0;i < 10;i++)
	{
		if (nums[i] == value)
		{
			std::cout << nums[i] << "값을 찾았습니다." << std::endl;
			return true;
		}
	}

	std::cout << "값을 찾지 못했습니다." << std::endl;
	return false;
}

void FindByVector()
{
	std::vector<int> nums;

	for (int i = 10;i > 0;i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}
	
	for (int i = 0;i < 10;i++)
	{
		std::find(nums.begin(), nums.end(), i);
	}
}

void FindByList()
{
	std::list<int> nums;

	for (int i = 10;i > 0;i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0;i < 10;i++)
	{
		std::find(nums.begin(), nums.end(), i);
	}
}

void FindByDeque()
{
	std::deque<int> nums;

	for (int i = 10;i > 0;i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0;i < 10;i++)
	{
		std::find(nums.begin(), nums.end(), i);
	}
}

void FindBySet() // 자동으로 정렬을 해준다.
{
	std::set<int> nums;

	for (int i = 10; i > 0;i--)
	{
		nums.insert(i);
	}

	nums.insert(100);
	nums.insert(50);

	nums.insert(1); // 중복된 수를 저장해주지 않는다.

	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0;i < 10;i++)
	{
		nums.find(i);
	}
}

void Test3()
{
	std::cout << "찾기 데이터 시간 비교" << std::endl;
	std::cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(FindByVector);
	std::cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(FindByList);
	std::cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(FindByDeque);
	std::cout << "set의 시간 : ";
	ConsoleUtil::TimeCheck(FindBySet);

	std::cout << "결과 : 순차 컨테이너는 데이터를 입력하는데 빠르다" << std::endl;
	std::cout << "연관 컨테이너는 자체적으로 데이터를 입력하는 로직이 존재하기 때문에 시간이 더 걸린다." << std::endl;
	std::cout << "데이터를 지속적으로 입력하는 경우가 아니면서, 자주 데이터를 검색해야 할 때 사용합니다." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

int main()
{
	Test1();
	Test2();
	Test2_2();
	Test2_3();

	//std::cout << std::boolalpha; // 결과를 true, false를 표기해준다
	//std::cout<<Find(5);

	Test3();
	std::cout << std::endl;
	FindByVector();
	std::cout << std::endl;
	FindByList();
	std::cout << std::endl;
	FindByDeque();
	std::cout << std::endl;
	FindBySet();
	std::cout << std::endl;
}