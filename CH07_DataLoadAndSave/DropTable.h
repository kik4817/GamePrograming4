#pragma once

#include <iostream>
#include <vector>
#include "ConsoleUtility.h"

/*
* 1. DropItem �����ڸ� ����� ������
* 2. Monster�� �����͸� �޾ƿ� �� �ְ� Private�ʵ带 �����Ѵ�.
* 3. public ���̺� todtjdwk, vector�� DropItem�� �߰��غ�����.
* 4. �ڷᱸ���� ����ϴ� �Լ��� ��������.
*/

struct DropItem
{
	int index;
	int exp;
	int money;

	DropItem() = default;
	DropItem(int index, int exp, int money) : index(index), exp(exp), money(money) {}
};

class Monster
{
private:
	// 2
	int index;
	int exp;
	int money;
	std::vector<DropItem> drop;
	DropItem currentDropItem;

public:
	Monster(int exp, int money) : exp(exp), money(money)
	{
		// 3. �ڷ� ������ �����Ͽ� ��������.
		drop.emplace_back(1, 10, 100);
		drop.emplace_back(2, 10, 100);
		drop.emplace_back(3, 20, 200);
		drop.emplace_back(4, 20, 200);
		drop.emplace_back(5, 20, 300);

		SetDropItem();
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(drop.size()-1);
		currentDropItem = drop[index];
	}

	void GetDropPoint()
	{
		std::cout << "ȹ���� ����ġ : " << currentDropItem.exp << std::endl;
		std::cout << "ȹ���� �� : " << currentDropItem.money << std::endl;		
	}

};
