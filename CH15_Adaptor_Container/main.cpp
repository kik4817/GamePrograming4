/*
* adapt �����̳�
* (Vector, List, Deque) ������� Ư���� �����̳�
* 
* stack queue, priority_queue
* ����, ť, �켱���� ť
*/

#pragma region ����

/*
* �޸� ���� LIFO�̴�. Last in First out
* �����͸� ����ϴ� ��Ģ�� �����ϴ� ������ ȿ���� ��� �ڷᱸ���Դϴ�.
* Iterator �������� �ʴ´�. (���������� iterator Ŭ������ ����.)
* Ctrl + z (Histor - Ư�� ��ġ�� ���ư� �� �ִ�.)
*/

#include <stack>
#include <iostream>

void Test1()
{
	std::cout << "���� ��� ����" << std::endl;
	std::stack<int>nums;

	for (int i = 0; i < 10;i++)
	{
		nums.push(i);
	}

	std::cout << "num�� ������ ���" << std::endl;
	//iterator�� �������� �ʱ� ������ ���� ��� for loop ��� �Ұ���
	//for (const auto& num : nums)
	//{
	//	std::count << num << " ";
	//}

	while (!nums.empty()) // �ڷᱸ���� ������� ���� �� �ݺ��϶�
	{
		std::cout << nums.top() << " "; // top �� ���� �����͸� ����϶�
		nums.pop();						// top�� �����͸� �����϶�
	}
	
	// size() = nums�� �ִ밪�� ��ȯ

	//for (int i = 0;i < nums.size();i++)
	//{
	//	std::cout << nums.top() << " ";
	//	nums.pop();
	//}
}
#pragma endregion 

#pragma region ť

/*
* �޸� ���� FIFO�̴�. First in First out
*/

#include <queue>

void Test2()
{
	std::cout << "\n\nť ��� ����" << std::endl;
	std::queue<int>nums;

	for (int i = 0; i < 10;i++)
	{
		nums.push(i);
	}

	std::cout << "num�� ������ ���" << std::endl;

	while (!nums.empty()) // �ڷᱸ���� ������� ���� �� �ݺ��϶�
	{
		std::cout << nums.front() << " "; 
		nums.pop();
	}
}

#pragma endregion

#pragma region �켱����ť

// ť : ���� ������� ������.(x) ���� �������� ����� ���� ������.
// ���, �Ϲ� �ʴ��, Ư�� �ʴ��
// �ð�, ��
// �� �Ȱ��� �ð��� ���� ��

// #include<queue> ���ԵǾ� �ִ�.
// heap �˰������� �����Ǿ� �ֽ��ϴ�. ���� ����(ū) �� Ʈ�� ������ ������ ������ ����.
// heapify

void Test3()
{
	std::cout << "\n\n�켱����ť ��� ����" << std::endl;
	std::priority_queue<int>nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);

	std::cout << "num�� ������ ���" << std::endl;

	while (!nums.empty()) // �ڷᱸ���� ������� ���� �� �ݺ��϶�
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}
}

#pragma endregion

#include <vector>
#include <deque>

template <typename T>
class MyQueue
{
private:
	int _size;
	std::deque<T> data;
public:
	MyQueue() : _size(0) {}

	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}

	T front()
	{
		return data[0];
	}

	void pop()
	{
		_size--;
		data.pop_back();
	}

	int size()
	{
		return _size;
	}

	bool empty()
	{
		return _size == 0;
	}
};

// vector�� ��������
template <typename T>
class MyStack
{
private:
	int _size;
	std::vector<T> data;
public:
	MyStack() : _size(0) {}
	
	// push, top, pop, size, empty
	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}

	T top()
	{
		return data[_size-1];
	}

	void pop()
	{
		_size--;
		data.pop_back();
	}

	int size()
	{
		return _size;
	}

	bool empty()
	{
		return _size == 0;
	}
};

void Test4()
{
	// queue�� ��� ����� ����?
	// 

	std::cout << "\n\n���� ���� ť ��� ����" << std::endl;
	MyQueue<int>nums;

	for (int i = 0; i < 10;i++)
	{
		nums.push(i);
	}

	std::cout << "num�� ������ ���" << std::endl;

	while (!nums.empty()) // �ڷᱸ���� ������� ���� �� �ݺ��϶�
	{
		std::cout << nums.front() << " ";
		nums.pop();
	}
}

void Test5()
{
	std::cout << "\n\n���� ��� ����" << std::endl;
	MyStack<int>nums;

	for (int i = 0; i < 10;i++)
	{
		nums.push(i);
	}

	std::cout << "num�� ������ ���" << std::endl;
	
	while (!nums.empty())
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}