/*
* 목표 : 1. 콘솔 창에서 플레이어를 움직인다.
*		2. 특정 위치에 상점 NPC와 조우할 때 상점의 항목을 보여준다
*		3. 상점을 이용한다.
* 
* Game Object : Player, NPC, Shop
* 자료구조 : Item 어떠한 컨테이너에 보관하여 사용할 것인가?
* File Input & output 메모장에 있는 데이터를 NPC에 전달하는 기능.* 
*/

//클래스 구현 -> 테스트 -> 헤더 옴기기

#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // 입출력 조작 헤더
#include <utility> // pair클래스가 사용가능
#include<unordered_map>

const int total_width = 60; // 전체 // 80을 넘기면 안좋다.
const int field1_width = 30; // 이름 길이
const int field2_width = 15; // 가격
const int field3_width = 15; // 타입

#pragma region 상점 코드

class Item
{
public:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type)
		: name(name), price(price), type(type) {}

	virtual void Use() = 0; // 순수 가상 함수 : Item을 상속하는 클래스가 이 함수를 반드시 구현을 하세요.
};

class Weapon : public Item
{
public:
	Weapon(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "무기를 사용합니다." << std::endl;
	}
};

/// <summary>
/// 아이템을 Use했을 때 사라지는 종류의 아이템입니다.
/// Player클래스의 RemoveItem을 사용하세요.
/// </summary>
class UsableItem : public Item
{
public:
	UsableItem(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "소비성 아이템을 사용합니다.." << std::endl;
	}
};



class Player
{
private:
	// Item Items[100]; 다음 코드의 문제점. 1억 -100 vector
	std::unordered_map<std::string, Item*> inventory; // Item을 아이템 이름으로 찾는 컨테이너
public:
	int posX, posY, money;

#pragma region 인벤토리 코드
	// 1 : 플레이어가 소유한 인벤토리를 자료구조를 한가지 선택해서 그 자료구조에 구매한 아이템을 저장해보세요
	// 2 : 저장한 자료구조를 사용하는 함수를 만들면 됩니다.

	void AddItem(Item* item)
	{
		inventory.insert({ item->name, item });
	}

	void RemoveItem(std::string name)
	{
		// 제거할 수 없는 경우에는?
		if (inventory.find(name) != inventory.end())
		{
		inventory.erase(name);
		}
		else
		{
			std::cout << "인벤토리에 해당하는 아이템이 없습니다." << std::endl;
		}
	}

	void RemoveItem(Item* item)
	{
		inventory.erase(item->name);	
	}

	// 특정 키를 눌렀을 때 (게임 입력 Player Input)
	// PushOne 함수포인터 PushOne();
	void Use(Item* item)
	{
		// 소비 아이템 -> 적용...
		// 장비 아이템 -> 장비 장착...
		item->Use();
	}

#pragma endregion

	/*
	* 상점은 전부다 아이템을 팔아야 하낟. (공통된 클래스 -> Item)
	* 해당 아이템 같은 함수 Use() 같고 있지만 다른 기능으로 사용하고 싶다. (클래스의 다형성)
	* Item을 주소로 받아오면, 다형성을 사용할 수 있다.
	*/

	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	// 좌상단의 플레이어 UI 뛰우기

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(45, 5);
		std::cout << "플레이어의 정보";
		ConsoleUtil::GotoXY(45, 6);
		std::cout << "돈 : " << money;
		ConsoleUtil::GotoXY(45, 7);
		std::cout << "소유한 아이템 목록" << money;
		ConsoleUtil::GotoXY(45, 8);
		for (const auto& item : inventory)
		{
			std::cout << item.first << " ";
		}


		// 보유한 아이템
	}

	void BuyItem(Item* item)
	{
		money -= item->price;
		AddItem(item);
		Use();

		// vector.push.back(item);
	}

	
};

class Shop
{
private:
	/*
	* Item 추상 클래스 만들면, item 자체를 클래스로 생성할 수 없다.(인스턴스)
	* 주소로 받아와야 하는데, enum 타입에 따라 클래스를 다르게 사용하게끔 코드를 작성해야 한다.
	* "팩토리 패턴" 팩토리 클래스로 만들어서 생성자를 다르게 구현할 수 있다.
	*/
	std::map<int, Item*> items; // 자료구조 클래스를 보관한다.
public:
	Shop() // 데이터를 초기화한다.
	{
		items.insert({ 0,new UsableItem("다이아몬드", 500,"소비") });
		items.insert(std::make_pair(1, new Weapon("활", 35, "무기")));
		std::pair<int, Item> p1(2, new UsableItem("화살", 5, "소비"));
		items.insert(p1);
		items.insert({ 3,new UsableItem("엘릭서", 300,"소비") });
		items.insert({ 4,new UsableItem("에메랄드", 100,"소비") });
	}

	Shop(std::string filename)
	{
		LoadShopData(filename);
	}
	
	void LoadShopData(std::string filename)
	{
		std::ifstream in_file;
		in_file.open(filename);

		std::string name;
		int price;
		std::string type;

		if (!in_file)
		{
			std::cerr << "파일을 여는데 실패했습니다." << std::endl;
			std::exit(1); //return;
		}
		
		int index = 0;

		while (!in_file.eof()) // end of file(파일의 끝에 도달했을 때 true반환)
		{
			in_file >> name >> price >> type;				  // 파일에서 name, price, type 읽기

			if (type == "무기")
			{
				items.insert({ index, new Weapon(name, price, type) }); // map 자료구조에 저장
				index++;										  // 다음 index 넘어가기
			}
		}

		in_file.close();
	}

	void SaveShopData(std::string filename)
	{
		std::ofstream out_file;
		out_file.open(filename);

		std::string name;
		int price;
		std::string type;

		if (!out_file)
		{
			std::cerr << "파일을 여는데 실패했습니다." << std::endl;
			std::exit(1);
		}

		for (int i = 0;i < items.size();i++)
		{
			out_file << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type
				<< std::endl;
		}

		out_file.close();
	}

	// 데이터를 사용하여 기능을 구현한다.
	void ShowItems(int x, int y)
	{
		//std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// 아이템의 머릿말
		//std::cout << headersize << std::endl;
		ConsoleUtil::GotoXY(x, y);
		std::cout << std::setw(field1_width) << std::left << "이름"
			<< std::setw(field2_width) << std::right << "가격"
			<< std::setw(field3_width) << std::right << "타입"
			<< std::endl;

		ConsoleUtil::GotoXY(x, y+1);
		// 라인을 긋는 방법
		std::cout << std::setw(total_width) // 길이 설정
			<< std::setfill('-')			// 공백을 '-' 설정
			<< ""							// 길이 설정2
			<< std::endl;

		std::cout << std::setfill(' '); // 기존 버전으로 리셋
		// 아이템을 출력	
		//for (const auto& elem : items) {}
		for (int i = 0;i < items.size();i++) // 인덱스 기반 접근이 가능한 자료구조야 한다. vector, map
		{
			ConsoleUtil::GotoXY(x, y+2+i);
			std::cout << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type
				<< std::endl;
		}
	}

	// 아이템을 판매한다.
	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) // 해당하는 아이템 찾았다.
		{
			Item* itemInstance = items[index];
			if (player.money >= itemInstance->price) // 플레이어가 소지금이 충분할때
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				std::cout << "소지금이 부족합니다." << std::endl;
			}
		}
		else
		{
			std::cout << "아이템을 찾지 못했습니다." << std::endl;
		}

	}

	void Interact(Player& player)
	{
		int select;
		std::cout << "번호를 입력하여 아이템을 구매할 수 있습니다." << std::endl;

		std::cin >> select;
		
		BuyItem(select, player);
	}	
};

#pragma endregion

#pragma region NPC 코드

// 상인이 존재하는 위치에 플레이어가 도달햇을 때 이 아이템을 보여주세요

class NPC
{
private:
	Shop shop;
public:
	int posX;
	int posY;
	bool isActivate;

	NPC() = default;
	NPC(std::string filename, int posX, int posY) : posX(posX), posY(posY), isActivate(true)
	{
		shop = Shop(filename);
	}

	void changeItemList(std::string filename)
	{
		shop = Shop(filename);
	}

	void ShowItems(int x, int y)
	{
		shop.ShowItems(x, y);
	}

	void Interact(Player& player)
	{
		shop.Interact(player);
		isActivate = false;
	}

	void ShowNPC()
	{
		if (isActivate == false) return;
		ConsoleUtil::GotoXY(posX, posY);
		std::cout << "$";
	}
};

//void Interact(int x1, int y1, NPC& npc, int ) // Player, Npc
void Interact(Player& player,NPC& npc, int UI_X, int UI_Y ) // Player, Npc
{
	if (player.posX == npc.posX && player.posY == npc.posY)
	{
		//if(!npc.isActivate)
		if (npc.isActivate == false) { return; } // 상점이 비활성화 되면 사용 불가능
		npc.ShowItems(UI_X, UI_Y);
		npc.Interact(player);
	}
}

#pragma endregion

#pragma region Player코드



#pragma endregion

int main()
{
	ConsoleUtil::SetCursorVisible(false);

	Player player(10,10, 1000); // 플레이어의 시작 설정

	//int playerX = 10;
	//int playerY = 10;

	NPC npc1("shop1.txt", 3, 5);
	NPC npc2("shop2.txt", 30, 10);
	NPC npc3("shop3.txt", 7, 7);

	//shop.SaveShopData("shop1.txt");

	while (true)
	{

		// 입력을 받았을 때 좌표가 변하는 코드
		if (_kbhit())
		{
			system("cls");

			if (GetAsyncKeyState(VK_UP))
			{
				player.posY--;

				if (player.posY <= 0) { player.posY = 0; }
			}
			if (GetAsyncKeyState(VK_DOWN))
			{				
				player.posY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				player.posX--;

				if (player.posX <= 0) { player.posX = 0; }
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				player.posX++;
			}
		}

		player.ShowPlayerUI();

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(player, npc1, 0, 10);
		Interact(player, npc2, 1, 5);
		Interact(player, npc3, 4, 7);

		//shop.ShowItems();
		ConsoleUtil::GotoXY(player.posX, player.posY);
		std::cout << "P";

		_getch(); // 유저의 입력을 넣는 코드
	}
}