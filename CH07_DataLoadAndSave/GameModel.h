#pragma once

/*
* 목표 : 레벨업 시스템 구현하고 싶다.
* int exp, int maxExp; 현제 경험치 > maxExp 레벨을 1 올린다.
*/

/*
* 목표2 : 레벨에 따른 경험치 요구량을 자료구조로 표현하기
* vector<""> 
*/

#include <iostream>
#include <vector>
#include <fstream>


/*
* 데이터를 표현하기 위한 클래스를 생성하세요. LevelExp
* 특정 클래스 안에 표현하기 위한 클래스의 자료구조로 선언하세요. Plyaer->std::vector<LevelExp> leveltable;
*/

/*
* 생성자에 데이터를 직접 작성한다.
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
	//	// 1레벨의 데이터를 가져와서 사용한다.		
	//	maxExp = leveltable[i].maxExp;
	//}

	int GetMaxExpForLevel(int level)
	{
		for (const auto& data : leveltable)
		{
			// 레벨과 table레벨을 비교하라.
			if (level == data.level)
			{
				return data.maxExp;
			}			
		}

		return -1; // -1 반환하면 에러로 인식하라. 
	}

	void GetExp(int amount) // 경험치 획득
	{
		maxExp = GetMaxExpForLevel(level);
		
		if (maxExp == -1)
		{
			std::cout << "최대 레벨을 도달했습니다. 실행을 취소 합니다." << std::endl;
			return; // 예외 처리 코드 알림 후 함수를 종료한다.
		}

		exp += amount; // exp 그 수치만큼 더 해준다.

		if (exp >= maxExp) // "레벨의 최대 경헌치 도달했을 때"
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
