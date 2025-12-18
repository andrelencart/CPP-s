#pragma once

#include <iostream>
#include <fstream>

int	parsing(char **av);
bool parsingline(const std::string &line, std::string &date, float &value);
bool isValidDate(const std::string& date);