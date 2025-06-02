/*
* ��ǥ : 1. �ܼ� â���� �÷��̾ �����δ�.
*		2. Ư�� ��ġ�� ���� NPC�� ������ �� ������ �׸��� �����ش�
*		3. ������ �̿��Ѵ�.
* 
* Game Object : Player, NPC, Shop
* �ڷᱸ�� : Item ��� �����̳ʿ� �����Ͽ� ����� ���ΰ�?
* File Input & output �޸��忡 �ִ� �����͸� NPC�� �����ϴ� ���.* 
*/

//Ŭ���� ���� -> �׽�Ʈ -> ��� �ȱ��

#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // ����� ���� ���
#include <utility> // pairŬ������ ��밡��

const int total_width = 60; // ��ü // 80�� �ѱ�� ������.
const int field1_width = 30; // �̸� ����
const int field2_width = 15; // ����
const int field3_width = 15; // Ÿ��

#pragma region ���� �ڵ�

class Item
{
public:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type)
		: name(name), price(price), type(type) {
	}
};

class Player
{
public:
	int posX, posY, money;

	// 1 : �÷��̾ ������ �κ��丮�� �ڷᱸ���� �Ѱ��� �����ؼ� �� �ڷᱸ���� ������ �������� �����غ�����
	// 2 : ������ �ڷᱸ���� ����ϴ� �Լ��� ����� �˴ϴ�.

	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	// �»���� �÷��̾� UI �ٿ��

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(45, 5);
		std::cout << "�÷��̾��� ����";
		ConsoleUtil::GotoXY(45, 6);
		std::cout << "�� : " << money;

		// ������ ������
	}

	void BuyItem(Item& item)
	{
		money -= item.price;

		// vector.push.back(item);
	}

	
};

class Shop
{
private:
	std::map<int, Item> items; // �ڷᱸ�� Ŭ������ �����Ѵ�.
public:
	Shop() // �����͸� �ʱ�ȭ�Ѵ�.
	{
		items.insert({ 0,Item("���̾Ƹ��", 500,"�Һ�") });
		items.insert(std::make_pair(1, Item("Ȱ", 35, "����")));
		std::pair<int, Item> p1(2, Item("ȭ��", 5, "�Һ�"));
		items.insert(p1);
		items.insert({ 3,Item("������", 300,"�Һ�") });
		items.insert({ 4,Item("���޶���", 100,"�Һ�") });
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
			std::cerr << "������ ���µ� �����߽��ϴ�." << std::endl;
			std::exit(1); //return;
		}
		
		int index = 0;

		while(!in_file.eof()) // end of file(������ ���� �������� �� true��ȯ)
		{
			in_file >> name >> price >> type;				  // ���Ͽ��� name, price, type �б�
			items.insert({ index, Item(name, price, type) }); // map �ڷᱸ���� ����
			index++;										  // ���� index �Ѿ��
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
			std::cerr << "������ ���µ� �����߽��ϴ�." << std::endl;
			std::exit(1);
		}

		for (int i = 0;i < items.size();i++)
		{
			out_file << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		}

		out_file.close();
	}

	// �����͸� ����Ͽ� ����� �����Ѵ�.
	void ShowItems(int x, int y)
	{
		//std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// �������� �Ӹ���
		//std::cout << headersize << std::endl;
		ConsoleUtil::GotoXY(x, y);
		std::cout << std::setw(field1_width) << std::left << "�̸�"
			<< std::setw(field2_width) << std::right << "����"
			<< std::setw(field3_width) << std::right << "Ÿ��"
			<< std::endl;

		ConsoleUtil::GotoXY(x, y+1);
		// ������ �ߴ� ���
		std::cout << std::setw(total_width) // ���� ����
			<< std::setfill('-')			// ������ '-' ����
			<< ""							// ���� ����2
			<< std::endl;

		std::cout << std::setfill(' '); // ���� �������� ����
		// �������� ���	
		//for (const auto& elem : items) {}
		for (int i = 0;i < items.size();i++) // �ε��� ��� ������ ������ �ڷᱸ���� �Ѵ�. vector, map
		{
			ConsoleUtil::GotoXY(x, y+2==i);
			std::cout << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		}
	}

	// �������� �Ǹ��Ѵ�.
	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) // �ش��ϴ� ������ ã�Ҵ�.
		{
			Item itemInstance = items[index];
			if (player.money >= itemInstance.price) // �÷��̾ �������� ����Ҷ�
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				std::cout << "�������� �����մϴ�." << std::endl;
			}
		}
		else
		{
			std::cout << "�������� ã�� ���߽��ϴ�." << std::endl;
		}

	}

	void Interact(Player& player)
	{
		int select;
		std::cout << "��ȣ�� �Է��Ͽ� �������� ������ �� �ֽ��ϴ�." << std::endl;

		std::cin >> select;
		
		BuyItem(select, player);
	}	
};

#pragma endregion

#pragma region NPC �ڵ�

// ������ �����ϴ� ��ġ�� �÷��̾ �������� �� �� �������� �����ּ���

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
		if (npc.isActivate == false) { return; } // ������ ��Ȱ��ȭ �Ǹ� ��� �Ұ���
		npc.ShowItems(UI_X, UI_Y);
		npc.Interact(player);
	}
}

#pragma endregion

#pragma region Player�ڵ�



#pragma endregion

int main()
{
	ConsoleUtil::SetCursorVisible(false);

	Player player(10,10, 1000); // �÷��̾��� ���� ����

	//int playerX = 10;
	//int playerY = 10;

	NPC npc1("shop1.txt", 3, 5);
	NPC npc2("shop2.txt", 30, 10);
	NPC npc3("shop3.txt", 7, 7);

	//shop.SaveShopData("shop1.txt");

	while (true)
	{

		// �Է��� �޾��� �� ��ǥ�� ���ϴ� �ڵ�
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

		_getch(); // ������ �Է��� �ִ� �ڵ�
	}
}