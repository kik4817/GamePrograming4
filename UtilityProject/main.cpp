#include "ConsoleUtility.h"

int main()
{
	while (true)
	{
		int random = ConsoleUtil::GetRandomInt(100);
		std::cout << random << std::endl;
		Sleep(100);
		break;
	}

	ConsoleUtil::GotoXY(4, 3);
	std::cout << "숫자" << std::endl;
	ConsoleUtil::GotoXY(6, 4);
	std::cout << "숫자" << std::endl;

}