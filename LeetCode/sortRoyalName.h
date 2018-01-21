#pragma once

#ifndef ROYALNAME_H
#define ROYALNAME_H

#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <regex>

using namespace std;

class RoyalName {
public:
	vector<string> sortRoyalName(vector<string> names);
	static bool compareNames(string name1, string name2);
	void printResult(vector<string> result);
	static int RomanToInt(string numeral);
	
};

#endif
