#include <iostream>
#include <string>
#include "bugsy_interpret.h"

int main(int argc, char** argv)
{
	std::cout << "Hello From Bugsy" << std::endl;
	std::string src;
	while (src != "exit")
	{
		std::cout << ">>";
		std::getline(std::cin, src);
		interpret(src);
	}
}