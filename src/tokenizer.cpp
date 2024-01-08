
#include <iostream>
#include <string>
#include <vector>
#include "tokenizer.h"



void _identifier_tokenize(const std::string& src, std::string& idn_name, std::string& idn_value)
{
	std::string identifier = "";
	for (int i = 0; i < src.find("="); i++)
	{
		if (src[i] != ' ') { identifier += src[i]; }
	}
	idn_name = identifier;
	idn_value = src.substr(src.find("=") + 1);
}

std::vector<std::string> _binary_tokenize(const std::string& src)
{
	std::vector<std::string> token_list;
	std::string op = "";
	std::string digit_token = "";
	std::string variable_token = "";
	for (int i = 0; i < src.length(); i++)
	{
		if (src[i] == ' ') { continue; }
		else if (src[i] != '+' && src[i] != '-' && src[i] != '*')
		{
			digit_token += src[i];
		}
		else if (((int)src[i] >= 65 && (int)src[i] <= 90) || ((int)src[i] >= 97 && (int)src[i] <= 120))
		{
			variable_token += src[i];
		}
		else 
		{
			if (digit_token.length() != 0)
			{
				token_list.push_back(digit_token);

				digit_token = "";
				op = src[i];
				token_list.push_back(op);
				op = "";
			}
			else
			{
				token_list.push_back(variable_token);
				variable_token = "";
				op = src[i];
				token_list.push_back(op);
				op = "";
			}

			/*token_list.push_back(digit_token);

			digit_token = "";
			op = src[i];
			token_list.push_back(op);
			op = "";*/
		}
	}
	token_list.push_back(digit_token);
	return token_list;
}

std::vector<std::string> tokenize(const std::string src)
{
	std::vector<std::string> token_list;
	std::string token = "";
	for (int i = 0; i < src.length(); i++)
	{
		if (src[i] != ' ') { token += src[i]; }
		else { token_list.push_back(token); token = ""; }
	}
	token_list.push_back(token);
	return token_list;
}
