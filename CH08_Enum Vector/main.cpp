/*
* �ۼ��� : 2025-05-23
*/

/*
* enum �����غ�����
* 
* class �ȿ� enum�� �����غ�����
*/

/*
* enum : ������
* enum���� ����� ������ �� �ִ�
*/

#include <iostream>
#include <vector>

enum Trait
{
	Strength,
	Dexterity,
	Intelligence,
	None
};

enum Stat
{
	Damage,
	Health,
	Mana,
	Speed
};

/*
* Trait�� Stat ���踦 �����ؾ��մϴ�.
* STR 1 �÷��� �� ? : Damage(���� ��ġ) * (); // �տ���
*/

/*
* VectorŸ���� �Ѱ���
* Stat, Stat
* Dex�ø��� Speed �����ϴ� �ý����� ������
* 
* �迭 ���·� ����Ǿ� �ִ� �ڷᱸ���̱� ������, �ڷ��� ���� �� �߰��� �� �� �������� �߻��� �� �ִ�.
* ������� �����Ǿ� ���� ���� �������� ������ �߻����� �� ������ ����ȴ�.
* 
* Map
*/

class TraitBonus
{
private:
	void IncreaseStat(Stat stat, int amount)
	{
		Stats[static_cast<int>(stat)] += amount;
	}

public:
	//Trait trait;
	//Stat stat;
	int additivaeBonusPoint;
	std::vector<int> Stats;

	TraitBonus() : Stats(4, 0) {}
	//TraitBonus(Trait trait, Stat stat, int additivaeBounusPoint)
	//	: trait(trait), stat(stat), additivaeBonusPoint(additivaeBounusPoint), Stats(4, 0) {}

	void GetTrait(Trait trait)
	{
		switch (trait)
		{
		case Trait::Strength:
			IncreaseStat(Damage, 5);
			IncreaseStat(Health, 3);
			break;
		case Trait::Dexterity:
			IncreaseStat(Speed, 1);			
			break;
		case Trait::Intelligence:
			IncreaseStat(Mana, 1);			
			break;
		}
	}

	void ShowStat()
	{
		std::cout << "Damge : " << Stats[Damage] << std::endl;
		std::cout << "Health : " << Stats[Health] << std::endl;
		std::cout << "Mana : " << Stats[Mana] << std::endl;
		std::cout << "Speed : " << Stats[Speed] << std::endl;
	}

};

class Player
{
	//Trait trait; // Ư���� 1���� �����Ѵ�.
	//Stat stat;   // ������ 1���� �����Ѵ�.
	//std::vector<Trait> traits;
	//std::vector<Stat> stats;

	//std::vector<TraitBonus> traitBonuses;

	//std::vector<int> stats;

	TraitBonus traitbonus;

public:
	//Player() : stats(4, 0) // stat�� ���� ���ڰ� �߰��Ǿ�� �Ѵ�.
	//{
	//	stats[static_cast<int>(Stat::Damage)] = 5;
	//	stats[static_cast<int>(Stat::Health)] = 50;
	//	stats[static_cast<int>(Stat::Mana)] = 100;
	//}

	//void IncreaseStat(Stat stat, int amount)
	//{
	//	stats[static_cast<int>(stat)] += amount;
	//}

	//void ShowPlayerStat()
	//{
	//	std::cout << "Damge : " << stats[Damage] << std::endl;
	//	std::cout << "Health : " << stats[Health] << std::endl;
	//	std::cout << "Mana : " << stats[Mana] << std::endl;
	//}
	Player() : traitbonus() {}

	TraitBonus GetTraits() const { return traitbonus; }

	void GetTrait(Trait trait)
	{
		traitbonus.GetTrait(trait);
	}

	void ShowStatus()
	{
		traitbonus.ShowStat();
	}
};

/*
* c������ Casting ������
* - �������� ����ȯ�� ���ÿ� �� �� �ִ�.
* cpp������ Casting
* - static_cast, const_cast, reinterpret_cast // dynamic_cast
* 
* �ǵ�ġ ���� ����ȯ�� �߻��� �� �ִ�.
* 
* Tip) int, double, std::string Primitive Type Ÿ���� ��ȯ�ϰ� ������, static_cast����Ѵ�.
* const_cast : ����� �����ִ� ����ȯ
* reinterpret_cast : �޸𸮿� �����Ͽ� int* -> double* ���ؼ��Ͽ� ��ȯ�ϴ� ��ȯ.
* dynamic_cast : Ŭ������ ��Ӱ��踦 ����ȯ�Ͽ�, ���� �����Ͱ� �������� ������ null��ȯ�Ѵ�.
* 
* if(dynamic_cast<Monster> d){}
*/

void EnumTest1()
{
	// enum�� ������, ������ enum���� ��ȯ�ϴ� ����
	
	int num = Stat::Damage;

	Stat someType = (Stat)num;               // c������ ����ȯ
	Stat someType2 = static_cast<Stat>(num); // cpp ����ȯ

	if (someType == Stat::Damage) // someType ����� ����ȯ�� �Ǿ��ٸ� �ڵ尡 ����� ���̴�
	{
		std::cout << "����::�������� ��µǾ����ϴ�." << std::endl;
	}

}

// enum vectorŸ������ ����ȯ�Ͽ� ����ϴ� ����
//void EnumTest2()
//{
//	Player player;
//		
//	player.IncreaseStat(Stat::Damage, 5); // �÷��̾��� ���ݷ� ������ 5��ŭ �������Ѷ�
//	player.ShowPlayerStat();
//	
//}

void EnumTest3()
{
	TraitBonus traits;

	traits.GetTrait(Trait::Strength);

	traits.ShowStat();

	// �÷��̾��� Ư���� ������������, Ư�� ������ �����ϰ� �Ϸ��� ��� �ڵ带 �ۼ��ؾ� �ұ�?

	// enum Trait, enum Stat, int amount �Լ��� �ʿ��մϴ�.
}

void EnumTest4()
{
	Player player;

	// player�ȿ� �ִ� Traitbonus Ŭ������ �����Ͽ� �Լ� ���
	player.GetTraits().GetTrait(Trait::Strength);
	player.GetTraits().ShowStat();

	// player Ŭ������ Traitbounus �Լ��� wrapping�ߴ�
	player.GetTrait(Trait::Strength);
	player.ShowStatus();

}

int main()
{
	//EnumTest1();
	//EnumTest2();
	//EnumTest3();
	//EnumTest4();

	// �Է��� ����Ͽ� ������ �������� ������

	// ȭ�� ��� : 1�� ������ Strenth ���� 2.. 3...
	Player player;

	std::cout << "  ============������=============" << std::endl;

	int input;
	std::cout << "���� ����� �Է����� �� Ư���� A�� �ø��ϴ�." << std::endl;
	std::cin >> input;

	if (input >= Trait::None)
	{
		std::cout << "�߸��� ���ڸ� �Է��߽��ϴ�." << std::endl;
	}
	else
	{
		player.GetTrait(static_cast<Trait>(input));
	}

	player.ShowStatus();

	//if (input == 0)
	//{
	//	player.GetTrait(Trait::Strength);
	//}
	//else if (input == 1)
	//{
	//	player.GetTrait(Trait::Dexterity);
	//}
}

// �÷��̾� ������ �ý��� + ���� ��� �ý���
// �������� ���� �� ������ ����� �� �ְ� ������
// Player TraitBonus, Levelup