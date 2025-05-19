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
		cout << "���� �̸� : " << name << endl;
	}

	void takeDamage(int dmg)
	{
		hp -= dmg;

		if (hp <= 0)
		{
			cout << name << "�� �й��߽��ϴ�." << endl;
		}
		else
		{
			cout << name << "�� ���� ü�� : " << hp << endl;
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
		cout << "����� ���� ���" << endl;
		int i = 1;
		for (const auto& monster : huntedMonster)
		{
			cout << i << "��° ����� ����" << monster.name << endl;
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
	
	int randIndex = ConsoleUtil::GetRandomInt(monsters.size() - 1); // 0���� �����ϱ⶧���� -1�� �ؾ��Ѵ�

	Monster& selectMonster = monsters[randIndex];

	int playerAttakDMG = 10;

	while (selectMonster.hp > 0)
	{
		//cout << "���Ϳ��� " << playerAttakDMG << "��ŭ ������ �߽��ϴ�.";
		selectMonster.takeDamage(playerAttakDMG);
	}

	player.huntMonster(selectMonster);
}