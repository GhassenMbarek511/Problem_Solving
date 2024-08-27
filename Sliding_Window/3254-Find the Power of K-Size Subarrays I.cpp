// Problem_Link : https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 :
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            bool b = true;
            int mx = nums[i];
            for (int j = i + 1; j < k + i; j++)
            {
                if (nums[j] - nums[j - 1] != 1)
                    b = false;
                if (nums[j] >= mx)
                    mx = nums[j];
            }
            if (!b)
                ans.push_back(-1);
            else
                ans.push_back(mx);
        }
        return ans;
    }
};