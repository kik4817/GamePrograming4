#pragma once

#include <iostream>

/*
* virtual 키워드를 사용하면 헤당 클래스를 상속하는 자식 클래스가 필요하다
* Combat - player, Monster
* override 기능을 사용하면 Combat 타입임에도 Player의 Combat과 Monster의 Cmobat 사용할 수 있다.
* 
* virtual 함수() = 0; 순수 가상함수
* 자식에서 해당 함수를 override 시켜라
*/

class Combat
{
public:
	virtual ~Combat() = default;

	virtual void attack(Combat& target) = 0;
	virtual void takeDamage(int damage) = 0;
	virtual int getHealth() = 0;
};

class Player : public Combat
{
private:
	int health;
	int ATK;

public:
	Player(int health, int ATK) : health(health), ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(ATK);
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		std::cout << "Player가" << damage << "의 피해를 입었습니다." << std::endl;
	}

	int getHealth() override
	{
		return health;
	}
};

class Monster : public Combat
{
private:
	int health;
	int ATK;

public:
	Monster(int health, int ATK) : health(health), ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(ATK);
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		std::cout << "Monster가" << damage << "의 피해를 입었습니다." << std::endl;
	}

	int getHealth() override
	{
		return health;
	}
};
