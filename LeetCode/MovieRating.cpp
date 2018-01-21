#include "stdafx.h"
#include "MovieRating.h"

using namespace std;

int DynamicProgramming::movieRating(vector<int> nums)
{

	if (nums.empty())return 0;
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return *max_element(nums.begin(),nums.end());

	vector<int> dp;
	dp.push_back(nums[0]);
	dp.push_back(max(dp[0] + nums[1], nums[1]));

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

int DynamicProgramming::longestCommonSequence(string input1, string input2)
{
	if (input1.empty() || input2.empty()) return 0;
	return 0;
}



