#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include "binary_parser.h"
#include "binary_operations.h"
#include "tokenizer.h"

// For DEBUGGING
void show_stack(std::stack<std::string> s)
{
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

}

int eval_shunting_yard(std::stack<std::string> output)
{
    std::stack<std::string> tree;
    while (!output.empty())
    {
        tree.push(output.top());
        output.pop();
    }

    std::stack<int> temp;
    std::string token;
    while (!tree.empty())
    {
        token = tree.top();
        if (token != "+" && token != "-" && token != "*")
        {
            temp.push(std::stoi(token));
        }

        else if (token == "+")
        {

            int operand1 = temp.top();
            temp.pop();
            int operand2 = temp.top();
            temp.pop();

            temp.push(ADD(operand2, operand1));
        }
        else if (token == "-")
        {

            int operand1 = temp.top();
            temp.pop();
            int operand2 = temp.top();
            temp.pop();

            temp.push(SUB(operand2, operand1));

        }
        else if (token == "*")
        {

            int operand1 = temp.top();
            temp.pop();
            int operand2 = temp.top();
            temp.pop();

            temp.push(MUL(operand2, operand1));
        }
        tree.pop();
    }
    return temp.top();
}

bool contains_only_numbers(const std::string& str)
{
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

int EVALUATE_BINARY_EXPRESSION(const std::string src, std::map<std::string, int>& idn_list)
{
	std::vector<std::string> token_list = _binary_tokenize(src);
    /*for (auto token = token_list.begin(); token != token_list.end(); token++)
    {
        std::cout << *token << std::endl;
    }*/

	
	std::stack<std::string> output; 
	std::stack<std::string> operator_stack;

	for (auto token = token_list.begin(); token != token_list.end(); token++)
	{
        if (contains_only_numbers(*token))
        {
            std::string digit = *token;
            output.push(digit);
        }
        /*if (*token != "+" && *token != "-" && *token != "*")
        {
            std::string digit = *token;
            output.push(digit);
        }*/
        else if (*token == "*")
        {
            while (operator_stack.empty() != 1 && operator_stack.top() == "*")
            {
                std::string op = operator_stack.top();
                output.push(op);
                operator_stack.pop();
            }
            operator_stack.push(*token);
        }
        else if (*token == "+" || *token == "-")
        {
            while (operator_stack.empty() != 1 && operator_stack.top() == "+" || operator_stack.empty() != 1 && operator_stack.top() == "-" || operator_stack.empty() != 1 && operator_stack.top() == "*")
            {

                std::string op = operator_stack.top();
                output.push(op);
                operator_stack.pop();
            }
            operator_stack.push(*token);
        }
        else
        {
            std::string variable = *token;
            /*int x = idn_list[variable];
            std::cout << "DEBUG >> " << *token << " == " << x << std::endl;*/
            std::string value = std::to_string(idn_list[variable]);
            output.push(value);
        }
	}

    while (!operator_stack.empty()) { output.push(operator_stack.top()); operator_stack.pop(); }

    //show_stack(output);

    int value = eval_shunting_yard(output);
    return value;
}
