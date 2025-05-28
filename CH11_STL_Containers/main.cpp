#include "ConsoleUtility.h"

// ���� �����̳� Sequence Container : vector, list, deque
// #include <�����̳�>

#include <vector>
#include <list>
#include <deque>

// ���� �����̳� associate Container : (multi, unordered) set, map

#include <set>
#include <map>
#include <algorithm>

// 1�ܰ� : ���� �����̳� ������ �Է� �ð� ��
// 2�ܰ� : ���� �����̳� �߰� ������ �Է� �ð� ��
// 3�ܰ� : ������, �߰� ������ ������ ���Ͽ� ������ ���� �����̳� ����ϱ�

#pragma region 1�ܰ� : ���� �����̳� ������ �Է� �ð� ��

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
	std::cout << "������ �Է� �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(DataPushByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(DataPushByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(DataPushByDeque);

	std::cout << "��� : �ܼ� �����͸� �Է��� �� vector ���� ������." << std::endl;
	std::cout << std::endl;
}
#pragma endregion

#pragma region 2-1�ܰ� : ���� �����̳� �߰� ������ �Է� �ð� ��

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
	std::cout << "�߰� ������ �Է� �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);

	std::cout << "��� : ó���� �����͸� �Է����� �� vector�� ������." << std::endl;
	std::cout << "���2 : �߰� ����(����)�ϴ� ������ ������ �������� list�� ���� �� �� �ִ�." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region 2-2�ܰ� : ���� �����̳� �����͸� �� �տ� �߰��� �� �ɸ��� �ð� ��

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
	std::cout << "ù��° ��ġ�� ������ �Է� �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByDeque);

	std::cout << "��� : ù��° ���Ҹ� �ִ� ��쿡 vector�� ������ ������ �ذ��� �� �ִ�." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region 2-3�ܰ� : ���� �����̳ʿ��� ���� ���� ���ٿ� �ɸ��� �ð� ��

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
	std::cout << "���� ��ġ�� ������ �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByDeque);

	std::cout << "��� : �迭 ������ �ڷᱸ��(vector, deque) �ٷ� ������ �� �ִ�." << std::endl;
	std::cout << "list�� ��쿡�� ���۰� �Ÿ��� �ָ� �ּ��� �ð��� ���� �ɸ���." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region ���� �����̳� ��
/*       |  Vector  |  List  |  Deque  |
* Push   |    1     |    3   |    2    |
* Insert |    2     |    1   |    3    |
* Front  |    3     |    2   |    1    |
* Access |    1     |    3   |    2    |
*/

/*
* Case1 : ��Ȳ �ο�, �������� �Է��� (����) �߻��� �ϰ�, �߰� ������ �Է��� (������), �տ� ������(������), ���� ������ (����) ���
*/
#pragma endregion

#pragma region 3�ܰ� : ���� �����̳ʿ� ���� �����̳�

// �����͸� �����ϴ� �������� �����̳ʸ� �������.
// std::vector<monster> nums; monster a- nums[?];
// �����̳� �ȿ� �ش��ϴ� �����Ͱ� ������? ������ �߻��Ѵ�. if(�����Ͱ� �����ϳ���?) -> ����

bool Find(int value)
{
	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0;i < 10;i++)
	{
		if (nums[i] == value)
		{
			std::cout << nums[i] << "���� ã�ҽ��ϴ�." << std::endl;
			return true;
		}
	}

	std::cout << "���� ã�� ���߽��ϴ�." << std::endl;
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

void FindBySet() // �ڵ����� ������ ���ش�.
{
	std::set<int> nums;

	for (int i = 10; i > 0;i--)
	{
		nums.insert(i);
	}

	nums.insert(100);
	nums.insert(50);

	nums.insert(1); // �ߺ��� ���� ���������� �ʴ´�.

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
	std::cout << "ã�� ������ �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(FindByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(FindByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(FindByDeque);
	std::cout << "set�� �ð� : ";
	ConsoleUtil::TimeCheck(FindBySet);

	std::cout << "��� : ���� �����̳ʴ� �����͸� �Է��ϴµ� ������" << std::endl;
	std::cout << "���� �����̳ʴ� ��ü������ �����͸� �Է��ϴ� ������ �����ϱ� ������ �ð��� �� �ɸ���." << std::endl;
	std::cout << "�����͸� ���������� �Է��ϴ� ��찡 �ƴϸ鼭, ���� �����͸� �˻��ؾ� �� �� ����մϴ�." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

int main()
{
	Test1();
	Test2();
	Test2_2();
	Test2_3();

	//std::cout << std::boolalpha; // ����� true, false�� ǥ�����ش�
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