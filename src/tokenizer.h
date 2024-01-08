#pragma once
#include <vector>
#include <string>
std::vector<std::string> tokenize(const std::string src);
void _identifier_tokenize(const std::string& src, std::string& idn_name, std::string& idn_value);
std::vector<std::string> _binary_tokenize(const std::string& src);