// MinimumSizeSubarraySum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <ctime>


using namespace std;

/*
Target = 7, nums = [2, 3, 1, 2, 4, 3]
Ouput = 2 ( [4,3] )

target = 11, nums = [1,1,1,1,1,1,1]
output 0
*/

class Solution
{
public:
	int minSubArrayLen(int target, const vector<int>& vec)
	{
		int left{}, right{};
		int sum = 0;
		auto min = INT_MAX;
		auto n = vec.size();

		while (right < n)
		{
			// add the current element right pointer is pointing to
			sum += vec[right];
			// test condition
			while (sum >= target)
			{
				min = std::min(min, right - left + 1);
				sum -= vec[left];
				left++;
			}
			right++;
		}
		return min == INT_MAX ? 0 : min;
	}
};
int main()
{
	Solution sol;
	{
		vector<int> vec{ 2, 3, 4, 1, 4, 3 };
		int target = 7;
		cout << sol.minSubArrayLen(target, vec) << endl;
	}
	{
		vector<int> vec{ 1,1,1,1,1,1,1 };
		int target = 11;
		cout << sol.minSubArrayLen(target, vec) << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
