#pragma once

#include "ConsoleUtility.h"

/*
* 백터(가변 배열)의 특징
* - 길이가 변할 수 있다. 동적 크기 변환이 가능하다.
* - 자동으로 크기가 변경된다.
* 
* int arr[15]; -> int arr[20];
*/

/*
* int size 크기;
* int capacity 수용량
* 
* int arr = new int[5];  size 0, capacity 5.
* size 6 int[6];
* arr = new int[10];
* 
* resize();
* int size, capacity;
*/

// value에 해당하는 타입을 T로 바꾸세요.
template<typename T> // int, double, string
class MyVector
{
private:
	int size;     // 갯수 double X
	int capacity; // 최대갯수 4.4 X
	T* vec;       // double*, int*, string*

public:
	// 생성자
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];
		size = 0;
		capacity = startSize;
	}
	// 소멸자
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
		// size : 현재 배열에 들어있는 원소의 숫자
		// nsize : 변경하려는 사이즈의 크기

		// 원소의 갯수를 재정의
		if (size < nsize)
		{
			size = size;
		}
		else
		{
			size = nsize;
		}
		// capacity 어떻게 변경할까?
		capacity = nsize;

		T* arr = new T[nsize];
		
		// vec[0]...vec[1]...size
		for (int i = 0;i < size;i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec; // 기존에 vec 가리키고 있는 공간을 메모리 해제한다.
		vec = arr;    // vec가 새로운 공간을 다시 가리켜라. (arr의 주소를 가리켜라)
		// delete[] arr; 은 지우면 안된다.
		
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