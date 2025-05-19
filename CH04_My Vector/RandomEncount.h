#pragma once

#include "ConsoleUtility.h"

class Monster
{
public:
	string name;
	int hp;
	int atk;

public:
	Monster() = default;
	~Monster() = default;

	Monster(string name, int hp, int atk)
		: name(name), hp(hp), atk(atk) {}

	void ShowInfo() const
	{
		cout << "몬스터 이름 : " << name << endl;
	}

	void takeDamage(int dmg)
	{
		hp -= dmg;

		if (hp <= 0)
		{
			cout << name << "이 패배했습니다." << endl;
		}
		else
		{
			cout << name << "의 남은 체력 : " << hp << endl;
		}
	}
};

class Player
{
private:
	vector<Monster> huntedMonster;
	// huntedMonster.push_back();
public:
	void huntMonster(const Monster& monster)
	{
		huntedMonster.push_back(monster);
	}

	void display()
	{
		cout << "사냥한 몬스터 목록" << endl;
		int i = 1;
		for (const auto& monster : huntedMonster)
		{
			cout << i << "번째 사냥한 몬스터" << monster.name << endl;
			i++;
		}
	}
};

void Battle(Player& player)
{
	vector<Monster> monsters =
		//monsters.emplace_back()
	{
		Monster("Gablin", 30, 5),
		Monster("Orc", 50, 10),
		Monster("Dragon", 100, 20),
		Monster("Zombie", 20, 5),
		Monster("Vampire", 40, 8)
	};
	
	int randIndex = ConsoleUtil::GetRandomInt(monsters.size() - 1); // 0부터 시작하기때문에 -1을 해야한다

	Monster& selectMonster = monsters[randIndex];

	int playerAttakDMG = 10;

	while (selectMonster.hp > 0)
	{
		//cout << "몬스터에게 " << playerAttakDMG << "만큼 공격을 했습니다.";
		selectMonster.takeDamage(playerAttakDMG);
	}

	player.huntMonster(selectMonster);
}