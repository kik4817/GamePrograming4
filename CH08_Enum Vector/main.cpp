/*
* 작성일 : 2025-05-23
*/

/*
* enum 선언해보세요
* 
* class 안에 enum을 선언해보세요
*/

/*
* enum : 열거형
* enum으로 상수를 지정할 수 있다
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
* Trait와 Stat 관계를 정의해야합니다.
* STR 1 올렸을 때 ? : Damage(기존 수치) * (); // 합연산
*/

/*
* Vector타입의 한계점
* Stat, Stat
* Dex올리면 Speed 증가하는 시스템을 만들어라
* 
* 배열 형태로 저장되어 있는 자료구조이기 때문에, 자료의 삭제 및 추가를 할 때 문제점이 발생할 수 있다.
* 순서대로 정리되어 있지 않은 데이터의 변경이 발생했을 때 문제가 예상된다.
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
	//Trait trait; // 특성을 1개만 소유한다.
	//Stat stat;   // 스탯을 1개만 소유한다.
	//std::vector<Trait> traits;
	//std::vector<Stat> stats;

	//std::vector<TraitBonus> traitBonuses;

	//std::vector<int> stats;

	TraitBonus traitbonus;

public:
	//Player() : stats(4, 0) // stat의 다음 숫자가 추가되어야 한다.
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
* c형태의 Casting 문제점
* - 여러가지 형변환을 동시에 할 수 있다.
* cpp형태의 Casting
* - static_cast, const_cast, reinterpret_cast // dynamic_cast
* 
* 의도치 않은 형변환이 발생할 수 있다.
* 
* Tip) int, double, std::string Primitive Type 타입을 변환하고 싶으면, static_cast사용한다.
* const_cast : 상수를 없애주는 형변환
* reinterpret_cast : 메모리에 접근하여 int* -> double* 재해석하여 변환하는 변환.
* dynamic_cast : 클래스의 상속관계를 형변환하여, 실제 데이터가 존재하지 않으면 null변환한다.
* 
* if(dynamic_cast<Monster> d){}
*/

void EnumTest1()
{
	// enum을 정수로, 정수를 enum으로 변환하는 예제
	
	int num = Stat::Damage;

	Stat someType = (Stat)num;               // c형태의 형변환
	Stat someType2 = static_cast<Stat>(num); // cpp 형변환

	if (someType == Stat::Damage) // someType 제대로 형변환이 되었다면 코드가 실행될 것이다
	{
		std::cout << "스탯::데미지가 출력되었습니다." << std::endl;
	}

}

// enum vector타입으로 형변환하여 사용하는 에제
//void EnumTest2()
//{
//	Player player;
//		
//	player.IncreaseStat(Stat::Damage, 5); // 플레이어의 공격력 스탯을 5만큼 증가시켜라
//	player.ShowPlayerStat();
//	
//}

void EnumTest3()
{
	TraitBonus traits;

	traits.GetTrait(Trait::Strength);

	traits.ShowStat();

	// 플레이어의 특성을 증가시켰을때, 특정 스탯을 증가하게 하려면 어떠한 코드를 작성해야 할까?

	// enum Trait, enum Stat, int amount 함수가 필요합니다.
}

void EnumTest4()
{
	Player player;

	// player안에 있는 Traitbonus 클래스에 접근하여 함수 사용
	player.GetTraits().GetTrait(Trait::Strength);
	player.GetTraits().ShowStat();

	// player 클래스에 Traitbounus 함수를 wrapping했다
	player.GetTrait(Trait::Strength);
	player.ShowStatus();

}

int main()
{
	//EnumTest1();
	//EnumTest2();
	//EnumTest3();
	//EnumTest4();

	// 입력을 사용하여 스탯을 증가시켜 보세요

	// 화면 출력 : 1을 누르면 Strenth 증가 2.. 3...
	Player player;

	std::cout << "  ============레벨업=============" << std::endl;

	int input;
	std::cout << "숫자 몇번을 입력했을 때 특성을 A를 올립니다." << std::endl;
	std::cin >> input;

	if (input >= Trait::None)
	{
		std::cout << "잘못된 숫자를 입력했습니다." << std::endl;
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

// 플레이어 레벨업 시스템 + 스탯 상승 시스템
// 레벨업을 했을 때 스탯을 상승할 수 있게 만들어라
// Player TraitBonus, Levelup