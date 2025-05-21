#pragma once

#include "GameModel.h"

class BattleManager
{
private:
	Player& player;
	Monster& monster;		

public:
	BattleManager(Player& player, Monster& monster) : player(player), monster(monster) {}
	
	void Battle()
	{
		while (player.getHealth() > 0 && monster.getHealth() > 0)
		{
			player.attack(monster);
			if (monster.getHealth() > 0)
			{
				monster.attack(player);
			}
		}

		std::cout << "전투가 종료되었습니다." << std::endl;
	}
};