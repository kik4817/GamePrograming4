// ���� �����̳� : (multi, unordedred) set, map

#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>

// set�� ������� �� ���� ���� �߻��ϴ°�?
#pragma region ���� �����̳� ����ϱ�

void Test1()
{
	std::set<int> nums;

	// �����͸� ��� ������ �� �ֳ���?
	// ���� �����̳�? insert
	// ���� �����̳ʿ� �����͸� �Է��ϸ� �ڵ����� ������ �ȴ�.
	// Ž���� �� �� ���ĵ� ����� ����ϸ� ȿ�����̴�. (100�� ���� �߶� ȿ�������� ����Ѵ�)
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7}

	std::cout << "Ư¡1 : Set�� �����Ͱ� �ڵ����� ���ĵ�" << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}

	std::cout << std::endl;
	// set�� Ư¡. �ߺ��� �ȵȴ�.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}

	std::cout << "Ư¡2 : Set�� �����ʹ� �ߺ��� �ȵȴ�." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;	
}

void Test2()
{
	std::cout << "MultiSet" << std::endl;

	std::multiset<int> nums;

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7}

	std::cout << "Ư¡1 : MultiSet�� �����Ͱ� �ڵ����� ���ĵ�" << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}

	std::cout << std::endl;
	// set�� Ư¡. �ߺ��� �ȵȴ�.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}

	std::cout << "Ư¡2 : MultiSet�� �����ʹ� �ߺ��� �ȵȴ�." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

#pragma endregion

#pragma region Ŀ���� Ŭ������ set�� �ִ� ���

struct Item
{
	int id;
	std::string name;

	Item() = default;
	Item(int id, std::string name) : id(id), name(name) {}

	bool operator<(const Item& other) const
	{
		return id < other.id;
	}
};

void Test3()
{
	std::cout << "Ŀ���� ��ü�� Set���� ����ϱ�" << std::endl;
	std::set<Item> items;

	Item item1(1, "����");
	Item item2(2, "��");
	Item item3(3, "�ٳ���");
	Item item4(100, "Į");
	Item item5(50, "����");

	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	std::cout << "�ߺ��� ��� �ȵ�" << std::endl;
	items.insert(Item(3, "����"));

	for (const auto& item : items)
	{
		std::cout << item.id << " " << item.name << std::endl;
	}
	
	std::cout << "Set�� ����ϸ� �������� ũ�⿡ ���� �ڵ����� ������ ����� ���� �� �ֽ��ϴ�." << std::endl;
	std::cout << "find�Լ��� ����ؼ� ������ �����͸� ã�� �� �ִ�" << std::endl;


	// item ��ü�� items�ȿ��� ã�ƾ� �Ѵ�.
	// itemd�� id�� n���� �����͸� ã�� �;��.
	// map�� ����ϸ� ���� �������� �ذ� �� ���ִ�
}

#pragma endregion

#pragma region map ����ϱ�

void Test4()
{
	std::cout << "map �ڷᱸ�� ����ϱ�" << std::endl;

	std::map<int, Item> items;

	// map�� �����͸� �ִ� ��� (1) �߰�ȣ�� ��� //{Ÿ��, Ÿ��}

	items.insert({ 0, Item(100, "����") });

	// (2) make_pair�Լ� ����ϱ�
	
	items.insert(std::make_pair(10, Item(1000, "�ռҵ�")));

	// (3) pairŬ������ ���� �����ϱ� (����� �ʿ�)

	std::pair<int, Item> p1(5, Item(101, "���� ����"));

	items.insert(p1);

	std::cout << "Ư¡1 : map�� pair�� �̷���� �����͸� �����ϴ� �����̳��̴�." << std::endl;
	std::cout << "Ư¡2 : map�� key������ �ڵ� ������ �̷�� ���ϴ�." << std::endl;

	for (const auto& item : items)
	{
		std::cout << item.first << " " << "ID : " << item.second.id << "�̸� : " << item.second.name << std::endl;
	}

	std::cout << "Ư¡3 : ����(Dictionary)�� �ڷᱸ���Դϴ�." << std::endl;

	std::cout << items[0].id << items[0].name << std::endl;

}

#pragma endregion

#pragma region ���� �����̳ʸ� �ǽ��Ѵ�.

struct NewItem
{
	std::string name;
	int ATK;
	int price;

	NewItem() = default;
	NewItem(std::string name, int ATK, int price) : name(name), ATK(ATK), price(price) {}
};

void Test5()
{
	std::map<std::string, int> map1;
	// �Ѱ�ȣ
	map1.insert({ "��", 0 });
	map1.insert({ "��", 1 });
	map1.insert(std::make_pair("��", 2));
	map1.insert(std::pair<std::string, int>("��", 3));

	for (const auto& e : map1)
	{
		std::cout << "[";
		std::cout << e.first << " " << e.second; 
		std::cout << "]" << " ";
	}

	std::cout << "�� Ű���忡�� ��� ���ڰ� ����ֽ��ϱ�?" << map1["��"] << std::endl;

	std::map<int, int> map2;
	// �÷��̾��� id��ȣ(����), �ش� �÷��̾��� ����
	// id��ȣ�� ???�� ������ ������ ���ΰ���?
	// ���� -> user Ÿ������ �����ϸ� user�� ��� ������ id ��ȣ�� ã�� �� �ִ�.
	map2.insert({0,10});
	map2.insert({5,100});
	map2.insert({100, 999});
	map2.insert({50, 50});
	map2.insert({25, 100});

	std::cout << "map2 �����̳� �ȿ� ������(0) Ű���忡�� ��� ���ڰ� ����ֽ��ϱ�?" << map2[0] << std::endl;

	std::map<std::string, NewItem> map3;
	map3.insert({"�ռҵ�", NewItem("�ռҵ�", 50, 100)});
	map3.insert({"���Ǿ�", NewItem("���Ǿ�", 30, 75)});

	//std::cout << "map3����ؼ� Ư���̸����� ã�� ���" << map3["�ռҵ�"] << std::endl;

	std::cout << "���࿡ map3�ȿ� ����ִ� �̸��� �ռҵ��� �����͸� �ҷ�����" << std::endl;
	NewItem itemInstance = map3["�ռҵ�"];
	std::cout <<"�̸� : "<< itemInstance.name
		<< " ���ݷ� : "<<itemInstance.ATK
		<< " ���� : "<<itemInstance.price << std::endl;

	//void BuyItem(NewItem item) item����, player�� ���ؼ� �����Ѵ�.
}

#pragma endregion

#pragma region ���� UI �� ��� �����ϱ�

// iomanip : setw left

class Player
{
	int money;
public:
	Player(int money) : money(money) {}

	// ������ �������� ȹ���ߴ�
	void BuyItem(NewItem item) {}
};

// ������ ���� �������� �Ȱ� �ʹ�.
// �������� �����̳� ���·� ������ �ؾ��Ѵ�.
// map�� ����ؼ� �����̳� ������ �ϰڴ�.

class Shop
{
	// 1�ܰ�
	// Ÿ��<int, NewItem>items �����̳ʸ� �����ϱ�
	std::map<int, NewItem> items;

public:
	Shop()
	{
		// 2�ܰ�
		// 5���� ���� �����͸� ���� �־��ּ���
		// items.insert(��ȣ, NewItem(�̸�, ���ݷ�, ����);
		items.insert({ 0, NewItem("�ռҵ�", 50, 100) });
		items.insert({ 1, NewItem("���ҵ�", 25, 50) });
		items.insert({ 2, NewItem("���Ǿ�", 35, 75) });
		items.insert({ 3, NewItem("������", 10, 10) });
		items.insert({ 4, NewItem("���", 45, 80) });
	}

	// ConsoleUtil::GotoXY

	void ShowItem()
	{
		std::cout << std::left;
		std::cout << std::setw(10) <<"�ε���"
			<< std::setw(10) << "�̸�"
			<< std::setw(10) << "���ݷ�"
			<< std::setw(10) << "����"
			<< std::endl;

		for (const auto& item : items)
		{
			std::cout << std::left; // �������� ����
			std::cout << std::setw(10) << item.first
				<< std::setw(10) << item.second.name 
				<< std::setw(10)<<item.second.ATK
				<< std::setw(10)<<item.second.price
				<<std::endl; // setw �ڸ�Ȯ��
		}
	}

	void SellItem(Player& player)
	{
		// 3�ܰ�

	}
};

void ShopTest()
{
	// 1. Item �����͸� �����.
	// 2. ������ �����͸� ����� Ŭ����
	// 3. ShopŬ���� �ȿ� map�ڷᱸ���� �߰��غ�����
	// 3. items �����͸� �ʱ�ȭ ���ּ���

	std::cout << std::endl;
	std::cout << "���� ��� ����Ʈ" << std::endl;

	Shop shop1;
	shop1.ShowItem();
}

#pragma endregion


// set���� �����͸� ���� ���� ���� ������ ��, �װ��� ������ map
// pair�� ���Ǹ� �ؾ��Ѵ�.

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	ShopTest();
}
