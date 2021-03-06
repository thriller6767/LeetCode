// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include"sortRoyalName.h"
#include "MovieRating.h"

using namespace std;

void test_MovieRating();
void test_SortRoyalName();
void test_minIncrementToEqual();

int main()
{
	test_SortRoyalName();
	//test_MovieRating();
	//test_minIncrementToEqual();

    return 0;
}

void test_MovieRating()
{

	map<vector<int>, int> input({ {{ 9, -1, -3, 4, 5 }, 17}, { { -1, -3, -2 },-3 }, { { -1,4,9,-8,-7,-6, -9, 10 },10 }, {{9, -1, -3}, 8} });

	DynamicProgramming dp;
	int result;
	for (auto& list : input) {
		result = dp.movieRating(list.first);
		cout << "movie rating max is " << result << ", should be "<< list.second<<"\n"; 
	}
	
}

void test_SortRoyalName()
{
	vector<string> names{ "Albert II", "Alberte I","Polo IV", "Alexander V", "Elizabeth XXV",
		"Albert XL", "Polo XLVI", "William IX", "Edward XXXIX",
		"Elizabeth XIX", "Elizabeth XLVII" };


	RoyalName royalName;
	royalName.printResult(royalName.sortRoyalName(names));

}

void test_minIncrementToEqual() {
	map<vector<int>, int> input({ {{4,3,4},2}, { {5,5,6,8,8,5 }, 7},{{2,3,4,4}, 0} });
	
	DynamicProgramming dp;
	int result;

	for (auto& list : input) {
		result = dp.minIncrementToEqual(list.first);
		cout << "Min Increment is " << result << ", should be " << list.second << "\n";
	}
}
