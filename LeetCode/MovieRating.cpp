#include "stdafx.h"
#include "MovieRating.h"

using namespace std;

int MovieRating::findMaximum(vector<int> nums)
{

	if (nums.empty())return 0;
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return max(nums[0], nums[1]);

	vector<int> dp;
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);

//----------------------------------------------------------

	return 0;
	
}

int MovieRating::deleteAndEarn(vector<int> nums)
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



