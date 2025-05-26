/*
* �ۼ��� : 2025-05-26
*/


#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "TimeCheck.h"
#include "FunctionPointer.h"
#include "ConsoleUtility.h"

/*
* Sequence Container
* Vector
* Deque
* List
*/

/*
* (��ǥ) Vector�� List�� �������� ���� ���غ�����
* 
* 1. vector.push_back �߰�, list.push_back �߰� �� �ð��� �� : ��� <> ���� ��������. ��������
* 2. ������ �����Ϳ� �����ϴµ� �ɸ��� �ð� : ��� vector�� �� ������. list ������ �������� �� �ð��� �ɸ���
* 3. ������ �����͸� ����µ� �ɸ��� �ð� : list�� �� ������
* 
*	�����Ͱ� ������ ������, ������ ���� ��� : vector ����
*	�������� ������ ������ ��� : list ����
* 
*	(�ڡڡڡڡ�)������ ������ ���� ���ٵ� ���� ��� : ?? unordered_map
* 
*	vector
*	unordered_map
*/

/*
* Vector, List ũ�� �������� ����
* Vector [ ] �ε����� �����ͷ� ����� �� �ֵ�
* List   [ ] �ε����� ������ �� ����        // ������ �ƴϸ� ��� �ڷḦ ǥ���� �� ������?
* 
* �������� ������ Ȯ���ϱ� ���ؼ� ȯ�� ������ �����Ѵ�.
*/

struct Node
{
	int value;
	Node* nextPtr;
	Node* prevPtr;
};

void Test1_Vector()
{
	std::vector<int> nums;
	//nums.push_back(1);
	for (int i = 0; i < 1000;i++)
	{
		nums.push_back(i);
	}

	std::cout << nums[500] << std::endl;
}

void Test2_List()
{
	std::list<int> nums;

	nums.push_back(3);
	nums.push_front(2);
	nums.push_back(1);

	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
}

void Example()
{

}

void VectorExample()
{
	std::vector<int> nums;
	for (int i = 0; i < 1000;i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 100;i++)
	{
		auto it = nums.begin();
		nums.erase(it);
	}


	std::cout << "������ ������ ���� �ð�" << std::endl;
	std::cout << nums[900] << std::endl;

	// erase�Լ� n����� �ϴ� ����

}
void ListExample()
{
	std::list<int> nums;
	for (int i = 0; i < 1000;i++)
	{
		nums.push_back(i);
	}


	std::cout << "������ ������ ���� �ð�" << std::endl;

	auto it = std::next(nums.begin(), 900);
	std::cout << *it << std::endl;

	// erase�Լ� n����� �ϴ� ����

}

int main()
{
	//Test1_Vector();
	//Test2_List();
	
	// �ڷᱸ�� �ð� �׽�Ʈ
	//TimeCheckTest();
	//TimeCheckTest2();

	// �Լ� ������ ����
	//Test();

	// ConsoleUtill::TimeCheck(); �����ϱ�

	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(ListExample);

	// double��ȯ
}