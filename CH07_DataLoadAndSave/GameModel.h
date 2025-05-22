#pragma once

/*
* ��ǥ : ������ �ý��� �����ϰ� �ʹ�.
* int exp, int maxExp; ���� ����ġ > maxExp ������ 1 �ø���.
*/

/*
* ��ǥ2 : ������ ���� ����ġ �䱸���� �ڷᱸ���� ǥ���ϱ�
* vector<""> 
*/

#include <iostream>
#include <vector>
#include <fstream>


/*
* �����͸� ǥ���ϱ� ���� Ŭ������ �����ϼ���. LevelExp
* Ư�� Ŭ���� �ȿ� ǥ���ϱ� ���� Ŭ������ �ڷᱸ���� �����ϼ���. Plyaer->std::vector<LevelExp> leveltable;
*/

/*
* �����ڿ� �����͸� ���� �ۼ��Ѵ�.
* vetor.push_back();
* vetor.emplace_back();
*/

struct LevelExp
{
	int level;
	int maxExp;

	LevelExp(int level, int maxExp) : level(level), maxExp(maxExp) {}
};

class Player
{
private:
	int exp;
	int maxExp;
	int level;
	std::vector<LevelExp> leveltable;

public:
	Player() : exp(0), level(1), maxExp(100) {}
	Player(int exp, int maxExp) : level(1), exp(exp), maxExp(maxExp) 
	{
		leveltable.emplace_back(1, 100);
		leveltable.emplace_back(2, 100);
		leveltable.emplace_back(3, 100);
		leveltable.emplace_back(4, 150);
		leveltable.emplace_back(5, 150);
		leveltable.emplace_back(6, 150);
		leveltable.emplace_back(7, 200);
		leveltable.emplace_back(8, 200);
		leveltable.emplace_back(9, 200);
	}

	//void LoadExpInExpTable(int i)
	//{
	//	// 1������ �����͸� �����ͼ� ����Ѵ�.		
	//	maxExp = leveltable[i].maxExp;
	//}

	int GetMaxExpForLevel(int level)
	{
		for (const auto& data : leveltable)
		{
			// ������ table������ ���϶�.
			if (level == data.level)
			{
				return data.maxExp;
			}			
		}

		return -1; // -1 ��ȯ�ϸ� ������ �ν��϶�. 
	}

	void GetExp(int amount) // ����ġ ȹ��
	{
		maxExp = GetMaxExpForLevel(level);
		
		if (maxExp == -1)
		{
			std::cout << "�ִ� ������ �����߽��ϴ�. ������ ��� �մϴ�." << std::endl;
			return; // ���� ó�� �ڵ� �˸� �� �Լ��� �����Ѵ�.
		}

		exp += amount; // exp �� ��ġ��ŭ �� ���ش�.

		if (exp >= maxExp) // "������ �ִ� ����ġ �������� ��"
		{
			level++;
			exp -= maxExp;
		}
	}

	void Show() const
	{
		std::cout << "Level : " << level << std::endl;
		std::cout << "Exp : " << exp << std::endl;
		std::cout << "MaxExp : " << maxExp << std::endl;
	}

	void SaveData(const std::string& filename)
	{
		std::ofstream file(filename);

		if (file.is_open())
		{
			file << level << " " << exp << " " << std::endl;
			file.close();
		}
	}
	void LoadData(const std::string& filename)
	{
		std::ifstream file(filename);		
		
		int _level, _exp;

		file >> _level >> _exp;

		level = _level;
		exp = _exp;

	}
};
