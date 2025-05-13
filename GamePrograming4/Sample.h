#pragma once


// int array[100];
// 1. vector<int> vec;

// 2. template ������ �ڵ�� �����غ� ��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PocketMonster
{
private:
	int _number;
	string _name;

public:
	PocketMonster(int number, string name) 
		: _number(number), _name(name) {}
	int Get_Number() const
	{
		return _number;
	}
	string Get_Name() const
	{
		return _name;
	}

	bool operator<(const PocketMonster& other)
	{
		// this->_number : �ڽ��� ���� ��ȣ
		// ohter.Get_Number() : �� ����� ���� ��ȣ
		return this->_number < other.Get_Number();

		//return this->_name.length() < other.Get_Name().length();
	}
	bool operator>(const PocketMonster& other)
	{		
		return this->_number > other.Get_Number();	
	}
	
};

class Player
{
	vector<PocketMonster> myPocketmon;
};

void Example1()
{
	PocketMonster pica(25, "��ī��");
	PocketMonster �̻��ؾ�(1, "�̻��ؾ�");
	PocketMonster ���α�(7, "���α�");
	PocketMonster ���̸�(4, "���̸�");
	PocketMonster ����(16, "����");
	
	//cout << "No. " << pica.Get_Number() << " " << pica.Get_Name() << endl;
	
	//bool result = pica > �̻��ؾ�;
	//cout << "�̻��ؾ��� ��ī�� ���� ���� ��ȣ�� ū����?" << result << endl;

	cout << "�̻��ؾ��� ��ī�� ���� ���� ��ȣ�� ū����?" << endl;
	if (pica < �̻��ؾ�)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "�ƴϿ�" << endl;
	}

	vector<PocketMonster> pocketDatabase;

	// ������ �Է�
	pocketDatabase.push_back(pica);
	pocketDatabase.push_back(�̻��ؾ�);
	pocketDatabase.push_back(���α�);
	pocketDatabase.push_back(���̸�);
	pocketDatabase.push_back(����);

	// ������ �˰���(����)
	sort(pocketDatabase.begin(), pocketDatabase.end());

	// ������ ���
	for (auto& pocketmon : pocketDatabase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	cout << endl;

	// ������ ã��(�˻�)
	for (auto& pocketmon : pocketDatabase)
	{
		if (pocketmon.Get_Number() == 7)
		{
			cout <<pocketmon.Get_Number()<<"�� ���͸� ã�Ҵ�";
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
		else
		{
			cout << "��ã�Ҵ�";
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;

		}
	}
}