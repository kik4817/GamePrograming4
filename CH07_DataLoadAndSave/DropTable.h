#pragma once

#include <iostream>
#include <vector>
#include "ConsoleUtility.h"

/*
* 1. DropItem 생성자를 만들어 보세요
* 2. Monster의 데이터를 받아올 수 있게 Private필드를 선언한다.
* 3. public 레이블에 todtjdwk, vector의 DropItem을 추가해보세요.
* 4. 자료구조를 사용하는 함수를 만들어보세요.
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
		// 3. 자료 구조를 생성하여 만들어보세요.
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
		std::cout << "획득한 경험치 : " << currentDropItem.exp << std::endl;
		std::cout << "획득한 돈 : " << currentDropItem.money << std::endl;		
	}

};
