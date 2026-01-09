#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>

int	parsing(char **av);
bool parsingline(const std::string &line, std::string &date, float &value);
bool isValidDate(const std::string& date);