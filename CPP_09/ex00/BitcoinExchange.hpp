#pragma once

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <map>

int	parsing(char **av);
bool parsingline(const std::string &line, std::string &date, float &value);
bool isValidDate(const std::string& date);
bool isValidValue(const float &value);
float FindExchangeRate(const std::map<std::string, float> &db, const std::string &date);
std::map<std::string, float> loadDatabase(const std::string &dbfile);