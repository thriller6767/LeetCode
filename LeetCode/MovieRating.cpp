#include "stdafx.h"
#include "MovieRating.h"

using namespace std;

int DynamicProgramming::movieRating(vector<int> nums)
{

	if (nums.empty())return 0;
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return *max_element(nums.begin(),nums.end());

	vector<int> dp;
	nums.push_back(0);//to determine whether to take the last element

	dp.push_back(nums[0]);
	dp.push_back(max(dp[0] + nums[1], nums[1]));

	//determine whether to jump the i-1 or i-2 elements
	for (int i = 2; i < nums.size(); ++i) {
		dp.push_back(max(dp[i - 1] + nums[i], dp[i - 2] + nums[i]));

	}
	return dp.back();
	
}

int DynamicProgramming::deleteAndEarn(vector<int> nums)
{
	std::map<int, int> valueMap;
	for (auto& c : nums) {valueMap[c] += c;}

	int taken = 0, notTaken = 0;
	int prev = -1;
	for (auto& kv : valueMap) {
		bool continuous = (kv.first == prev + 1);
		if (continuous) {
			int newNotTaken = max(taken, notTaken);
			taken = notTaken + kv.second;
			notTaken = newNotTaken;
		}
		else {
			notTaken = max(notTaken, taken);
			taken = notTaken + kv.second;
		}
		prev = kv.first;
	}

	printf("taken is %d, notTaken is %d\n", taken, notTaken);
	return max(taken, notTaken);
	
}

//Given two sequences, find the length of longest subsequence present in both of them.
//A subsequence is a sequence that appears in the same relative order,
//but not necessarily contiguous.For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, ..etc are 
//subsequences of “abcdefg”.So a string of length n has 2 ^ n different possible subsequences.
int DynamicProgramming::longestCommonSequence(vector<int> s1, vector<int> s2)
{
	return 0;
}

//We are given an array consisting of n elements.At each operation you can select any one element 
//and increase rest of n - 1 elements by 1. You have to make all elements equal performing such 
//operation as many times you wish.Find the minimum number of operations needed for this.
int DynamicProgramming::minIncrementToEqual(vector<int> nums)
{
	return accumulate(begin(nums), end(nums), 0L) - nums.size() * *min_element(begin(nums), end(nums));
}



