#pragma once


/*
* 데이터 저장.
* 1단계 : 플레이어의 레벨, 경험치
* 
* 2단계 : 데이터를 자료구조 형태로 저장.
* 1 100
* 2 200
*/

#include <fstream>
#include <iostream>

class Data
{
public:
	int exp;
	int level;

public:
	Data() : exp(100), level(1) {}

	// file 열어라
	// 메모장에 exp와 level을 저장해라
	// close() 스트림을 반드시 닫아줄 것.
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
		
		int _exp, _level;

		file >> _level >> _exp;

		level = _level;
		exp = _exp;
	}
};