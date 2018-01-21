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

int main()
{
	//test_SortRoyalName();
	test_MovieRating();

    return 0;
}

void test_MovieRating()
{
	vector<int> input{  9,-1, -3, 4, 5 };
	MovieRating mr;
	
}

void test_SortRoyalName()
{
	vector<string> names{ "Albert II", "Polo IV", "Alexander V", "Elizabeth XXV",
		"Albert XL", "Polo XLVI", "William IX", "Edward XXXIX",
		"Elizabeth XIX", "Elizabeth XLVII" };


	RoyalName royalName;
	royalName.printResult(royalName.sortRoyalName(names));

}
