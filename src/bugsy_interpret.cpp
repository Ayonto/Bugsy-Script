#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "bugsy_interpret.h"
#include "tokenizer.h"
#include "binary_parser.h"

std::map<std::string, int> IDENTIFIER_LIST;

// FOR DEBUGING
static void _show_map(const std::map<std::string, int>& map)
{
	for (auto i = map.begin(); i != map.end(); i++)
	{
		std::cout << "Key: " << i->first << " | value: " << i->second << std::endl;
	}
}

void _ASSIGN_OPERATION(const std::string& src)
{
	std::vector<std::string> list = tokenize(src);
	/*for (auto i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << std::endl;
	}*/
	std::string IDN_NAME; 
	std::string IDN_VALUE;

	_identifier_tokenize(src, IDN_NAME, IDN_VALUE);
	//std::cout << "variable name >>" << IDN_NAME << "<<" << std::endl; std::cout << "Value >>" << IDN_VALUE << "<<" << std::endl;
	
	/*int INT_IDN_VALUE = std::stoi(IDN_VALUE);*/
	int INT_IDN_VALUE = EVALUATE_BINARY_EXPRESSION(IDN_VALUE, IDENTIFIER_LIST);

	IDENTIFIER_LIST[IDN_NAME] = INT_IDN_VALUE;
	
	_show_map(IDENTIFIER_LIST);

}

void interpret(std::string src)
{
	/*std::vector<std::string> source_token_list = tokenize(src);
	for(auto i = source_token_list.begin(); i != source_token_list.end(); i++)
	{
		std::cout << *i << std::endl;
	}*/
	if(src.find("=") != std::string::npos)
	{
		_ASSIGN_OPERATION(src); 
	}
}
