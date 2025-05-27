#pragma once

#include "ConsoleUtility.h"

// 복습, 계산기 기능, 함수 포인터로 표현하기

#pragma region 심화1 : 함수 포인터에 일반화 Generic Programming 적용

template<typename T>
void Plus(T a, T b)
{
	std::cout << "더하기 결과 :";
	std::cout << a + b << std::endl;
}

template<typename T>
void Minus(T a, T b)
{
	std::cout << "빼기 결과 :";
	std::cout << a - b << std::endl;
}

template<typename T>
void Multiply(T a, T b)
{
	std::cout << "곱하기 결과 :";
	std::cout << a * b << std::endl;

}

template<typename T>
void Divide(T a, T b)
{
	if(b==0)
	{
		return;
	}

	std::cout << "나누기 결과 :";
	std::cout << a / b << std::endl;
}

template<typename T>
void Calculate(void(*Func)(T a, T b), T outA, T outB)
{
	Func(outA, outB);
}

#pragma endregion

#pragma region 심화2 : 열거형과 클래스로 함수포인터 활용

// 열거형의 이름은 항상 대문자로 작성해서, 이름으로 타입을 알아볼 수 있게 설정하였다.
// 함수는 첫글자가 대문자로 표현하게 설정하였다.
enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:

	static void Move()
	{
		std::cout << "움직입니다." << std::endl;
	}

	static void Talk()
	{
		std::cout << "대화합니다." << std::endl;
	}

public:
	Actor() = default;

	void (*Action)();	

	void Think()
	{
		// 랜덤한 숫자를 받아서, 0이나오면 움직여라, 1이나오면 Talk, 2가 나오면...
		int select = ConsoleUtil::GetRandomInt(2); // 1,2과 나오기 때문에 -1을 해준다

		ActorAction aaction = static_cast<ActorAction>(select - 1);

		switch (aaction)
		{
		case MOVE: Action = Move;
			break;
		case TALK: Action = Talk;
			break;
		default:
			std::cout << "잘못된 입력을 받아옸습니다." << std::endl;
			return;
		}

	}
};


#pragma endregion

#pragma region 가위바위보 예제 만들기

enum RSP_TYPE
{
	ROCK, SCISSORS, PAPER
};

class RSPGame
{
private:	
	// 함수포인터 선언

	static void Rock()
	{
		std::cout << "바위" << std::endl;
	}
	static void Scissors()
	{
		std::cout << "가위" << std::endl;
	}
	static void Paper()
	{
		std::cout << "보" << std::endl;
	}

	RSP_TYPE computertype;
	RSP_TYPE usertype;

	int userScore;
	int computerScore;

	void Result()
	{
		// 유저, 컴퓨터가 같다 : 비김

		// 유저 > 컴퓨터 : 이김

		// 그게아니면 졌다
		if (usertype == computertype)
		{
			std::cout << "비겼다." << std::endl;
		}
		else if(usertype == ROCK && computertype == SCISSORS ||
			usertype==SCISSORS && computertype == PAPER||
			usertype==PAPER &&computertype == ROCK)
		{
			std::cout << "이겼다" << std::endl;
			userScore++;
		}
		else
		{
			std::cout << "졌다." << std::endl;
			computerScore++;
		}
	}
	
public:
	RSPGame() : userScore(0), computerScore(0){}
	void (*RSP)();
	// switch(RSP_TYPE) 각 타입에 맞게 함수포인터의 함수를 넣는 코드를 만들어보세요
	

	void StartGame()
	{
		while (true)
		{
			// 유저가 입력
			std::cout << "0 : 바위, 1 : 가위, 2 : 보" << std::endl;
			int input = 0;
			std::cin >> input;
			usertype = static_cast<RSP_TYPE>(input);

			// 컴퓨터가 선택할 번호를 랜덤으로 받습니다.
			int select = ConsoleUtil::GetRandomInt(3);
			computertype = static_cast<RSP_TYPE>(select - 1);
			// switch문을 사용합니다. 함수포인터를 결정합니다.
			switch (computertype)
			{
			case ROCK: RSP = Rock;
				break;
			case SCISSORS: RSP = Scissors;
				break;
			case PAPER: RSP = Paper;
				break;
			default:
				std::cout << "잘못된 입렵을 받았습니다." << std::endl;
				return;
			}
			// 함수포인터의 함수를 실행합니다.
			std::cout << "컴퓨터가 선택한 행동 :" << " ";
			RSP();
			Result();

			if (userScore >= 3 || computerScore >= 3)
			{
				break;
			}
		}

		if (userScore >= 3)
		{
			std::cout << "유저의 승리입니다." << std::endl;
		}
		else if (computerScore >= 3)
		{
			std::cout << "컴퓨터의 승리입니다." << std::endl;
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
	// actor.의사결정을 한다. Think
	actor.Think();
	actor.Action();
}
void FPTest3()
{
	RSPGame rspgame;
	rspgame.StartGame();
}
	