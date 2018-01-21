#pragma once

#ifndef MOVIERATING_H
#define MOVIERATING_H


#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class MovieRating {
public:
	int findMaximum(vector<int> input);
	int deleteAndEarn(vector<int> input);

};


#endif