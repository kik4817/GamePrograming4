#pragma once

#include "ConsoleUtility.h"

/*
* ����(���� �迭)�� Ư¡
* - ���̰� ���� �� �ִ�. ���� ũ�� ��ȯ�� �����ϴ�.
* - �ڵ����� ũ�Ⱑ ����ȴ�.
* 
* int arr[15]; -> int arr[20];
*/

/*
* int size ũ��;
* int capacity ���뷮
* 
* int arr = new int[5];  size 0, capacity 5.
* size 6 int[6];
* arr = new int[10];
* 
* resize();
* int size, capacity;
*/

// value�� �ش��ϴ� Ÿ���� T�� �ٲټ���.
template<typename T> // int, double, string
class MyVector
{
private:
	int size;     // ���� double X
	int capacity; // �ִ밹�� 4.4 X
	T* vec;       // double*, int*, string*

public:
	// ������
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];
		size = 0;
		capacity = startSize;
	}
	// �Ҹ���
	~MyVector()
	{
		delete[] vec;
	}

	T& operator[](int idx) // vec[1.1]
	{
		return vec[idx];
	}
	void resize(int nsize)
	{
		// size : ���� �迭�� ����ִ� ������ ����
		// nsize : �����Ϸ��� �������� ũ��

		// ������ ������ ������
		if (size < nsize)
		{
			size = size;
		}
		else
		{
			size = nsize;
		}
		// capacity ��� �����ұ�?
		capacity = nsize;

		T* arr = new T[nsize];
		
		// vec[0]...vec[1]...size
		for (int i = 0;i < size;i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec; // ������ vec ����Ű�� �ִ� ������ �޸� �����Ѵ�.
		vec = arr;    // vec�� ���ο� ������ �ٽ� �����Ѷ�. (arr�� �ּҸ� �����Ѷ�)
		// delete[] arr; �� ����� �ȵȴ�.
		
	}
	void push_back(const T& element) // vec.push_back(6)
	{
		// capacity < size
		if (capacity <= size)
		{
			capacity = capacity * 2; 
			resize(capacity);
		}

		vec[size] = element;
		size++;
	}
	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;

		//if (size > 0)
		//{
		//	size = size - 1;
		//}
		//else if (size == 0)
		//{
		//	size = 0;
		//}
	}

	int Size() { return size; }
};

void test1()
{
	while (true)
	{
		MyVector<int>* myVec = new MyVector<int>(10);
		delete myVec;
	}
}


// int size() (return size;)
void test2()
{
	MyVector<int> vec(5);

	for (int i = 0;i < 5; i++)
	{
		vec.push_back(i + 1);
		cout << vec[i] << " ";
	}

	vec.push_back(6);
	cout << endl;

	for (int i = 0;i < vec.Size();i++)
	{
		cout << vec[i] << " ";
	}

	cout << endl;
	MyVector<double> vec2(5);
	for (int i = 0;i < 5; i++)
	{
		vec2.push_back(i + 0.1);
		cout << vec2[i] << " ";
	}


}