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
		: name(name), price(price), type(type) {}
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
	void ShowItems()
	{
		//std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// �������� �Ӹ���
		//std::cout << headersize << std::endl;
		
		std::cout << std::setw(field1_width) << std::left << "�̸�"
			<< std::setw(field2_width) << std::right << "����"
			<< std::setw(field3_width) << std::right << "Ÿ��"
			<< std::endl;

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
			std::cout << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		}
	}

	// �������� �Ǹ��Ѵ�.
	void SellItems()
	{

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

	NPC() = default;
	NPC(std::string filename, int posX, int posY) : posX(posX), posY(posY)
	{
		shop = Shop(filename);
	}

	void ShowItems()
	{
		shop.ShowItems();
	}

	void ShowNPC()
	{
		ConsoleUtil::GotoXY(posX, posY);
		std::cout << "$";
	}
};

void Interact(int x1, int y1, NPC& npc) // Player, Npc
{
	if (x1 == npc.posX && y1 == npc.posY)
	{
		npc.ShowItems();
	}
}

#pragma endregion

#pragma region Player�ڵ�

class Player
{
	// ��ǥ
	// �� <<

	// Shop�ڵ�� ������ �ؼ�.. money, Shop.itemp[i].price �� money-= price;
	// �κ��丮 (� �����̳ʸ� �����ϸ� ������?) shop -> player.inventory
	// std::vector

	// ���� �÷��̾ ������ �ִ� ������ ������ ����. LEVEL
	// ���� ����
};

#pragma endregion

int main()
{
	ConsoleUtil::SetCursorVisible(false);

	int playerX = 10;
	int playerY = 10;

	NPC npc1("shop1.txt", 3, 5);
	NPC npc2("shop2.txt", 10, 15);
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
				playerY--;

				if (playerY <= 0) { playerY = 0; }
			}
			if (GetAsyncKeyState(VK_DOWN))
			{				
				playerY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				playerX--;

				if (playerX <= 0) { playerY = 0; }
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				playerX++;
			}
		}

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(playerX, playerY, npc1);
		Interact(playerX, playerY, npc2);
		Interact(playerX, playerY, npc3);

		//shop.ShowItems();
		ConsoleUtil::GotoXY(playerX, playerY);
		std::cout << "a";

		_getch(); // ������ �Է��� �ִ� �ڵ�
	}
}