#pragma once

#ifndef DYNAMICPROGRAMMING_H
#define DYNAMICPROGRAMMING_H


#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class DynamicProgramming {
public:
	int movieRating(vector<int> input);
	int deleteAndEarn(vector<int> input);
	int longestCommonSequence(string input1, string input2);


private:
	int isLarger(int a, int b) { return (a > b) ? a : b; }
};


#endif