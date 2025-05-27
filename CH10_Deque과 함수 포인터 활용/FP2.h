#pragma once

#include "ConsoleUtility.h"

// ����, ���� ���, �Լ� �����ͷ� ǥ���ϱ�

#pragma region ��ȭ1 : �Լ� �����Ϳ� �Ϲ�ȭ Generic Programming ����

template<typename T>
void Plus(T a, T b)
{
	std::cout << "���ϱ� ��� :";
	std::cout << a + b << std::endl;
}

template<typename T>
void Minus(T a, T b)
{
	std::cout << "���� ��� :";
	std::cout << a - b << std::endl;
}

template<typename T>
void Multiply(T a, T b)
{
	std::cout << "���ϱ� ��� :";
	std::cout << a * b << std::endl;

}

template<typename T>
void Divide(T a, T b)
{
	if(b==0)
	{
		return;
	}

	std::cout << "������ ��� :";
	std::cout << a / b << std::endl;
}

template<typename T>
void Calculate(void(*Func)(T a, T b), T outA, T outB)
{
	Func(outA, outB);
}

#pragma endregion

#pragma region ��ȭ2 : �������� Ŭ������ �Լ������� Ȱ��

// �������� �̸��� �׻� �빮�ڷ� �ۼ��ؼ�, �̸����� Ÿ���� �˾ƺ� �� �ְ� �����Ͽ���.
// �Լ��� ù���ڰ� �빮�ڷ� ǥ���ϰ� �����Ͽ���.
enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:

	static void Move()
	{
		std::cout << "�����Դϴ�." << std::endl;
	}

	static void Talk()
	{
		std::cout << "��ȭ�մϴ�." << std::endl;
	}

public:
	Actor() = default;

	void (*Action)();	

	void Think()
	{
		// ������ ���ڸ� �޾Ƽ�, 0�̳����� ��������, 1�̳����� Talk, 2�� ������...
		int select = ConsoleUtil::GetRandomInt(2); // 1,2�� ������ ������ -1�� ���ش�

		ActorAction aaction = static_cast<ActorAction>(select - 1);

		switch (aaction)
		{
		case MOVE: Action = Move;
			break;
		case TALK: Action = Talk;
			break;
		default:
			std::cout << "�߸��� �Է��� �޾ƞ����ϴ�." << std::endl;
			return;
		}

	}
};


#pragma endregion

#pragma region ���������� ���� �����

enum RSP_TYPE
{
	ROCK, SCISSORS, PAPER
};

class RSPGame
{
private:	
	// �Լ������� ����

	static void Rock()
	{
		std::cout << "����" << std::endl;
	}
	static void Scissors()
	{
		std::cout << "����" << std::endl;
	}
	static void Paper()
	{
		std::cout << "��" << std::endl;
	}

	RSP_TYPE computertype;
	RSP_TYPE usertype;

	int userScore;
	int computerScore;

	void Result()
	{
		// ����, ��ǻ�Ͱ� ���� : ���

		// ���� > ��ǻ�� : �̱�

		// �װԾƴϸ� ����
		if (usertype == computertype)
		{
			std::cout << "����." << std::endl;
		}
		else if(usertype == ROCK && computertype == SCISSORS ||
			usertype==SCISSORS && computertype == PAPER||
			usertype==PAPER &&computertype == ROCK)
		{
			std::cout << "�̰��" << std::endl;
			userScore++;
		}
		else
		{
			std::cout << "����." << std::endl;
			computerScore++;
		}
	}
	
public:
	RSPGame() : userScore(0), computerScore(0){}
	void (*RSP)();
	// switch(RSP_TYPE) �� Ÿ�Կ� �°� �Լ��������� �Լ��� �ִ� �ڵ带 ��������
	

	void StartGame()
	{
		while (true)
		{
			// ������ �Է�
			std::cout << "0 : ����, 1 : ����, 2 : ��" << std::endl;
			int input = 0;
			std::cin >> input;
			usertype = static_cast<RSP_TYPE>(input);

			// ��ǻ�Ͱ� ������ ��ȣ�� �������� �޽��ϴ�.
			int select = ConsoleUtil::GetRandomInt(3);
			computertype = static_cast<RSP_TYPE>(select - 1);
			// switch���� ����մϴ�. �Լ������͸� �����մϴ�.
			switch (computertype)
			{
			case ROCK: RSP = Rock;
				break;
			case SCISSORS: RSP = Scissors;
				break;
			case PAPER: RSP = Paper;
				break;
			default:
				std::cout << "�߸��� �Է��� �޾ҽ��ϴ�." << std::endl;
				return;
			}
			// �Լ��������� �Լ��� �����մϴ�.
			std::cout << "��ǻ�Ͱ� ������ �ൿ :" << " ";
			RSP();
			Result();

			if (userScore >= 3 || computerScore >= 3)
			{
				break;
			}
		}

		if (userScore >= 3)
		{
			std::cout << "������ �¸��Դϴ�." << std::endl;
		}
		else if (computerScore >= 3)
		{
			std::cout << "��ǻ���� �¸��Դϴ�." << std::endl;
		}

	}


};

#pragma endregion

void FPTest()
{
	Calculate(Plus, 5, 6);
	Calculate(Plus, 5.5, 6.5);
	Calculate(Minus, 6.9, 5.7);
	Calculate(Multiply, 6, 5);
	Calculate(Divide, 6, 3);
}
void FPTest2()
{
	Actor actor;
	// actor.�ǻ������ �Ѵ�. Think
	actor.Think();
	actor.Action();
}
void FPTest3()
{
	RSPGame rspgame;
	rspgame.StartGame();
}
	