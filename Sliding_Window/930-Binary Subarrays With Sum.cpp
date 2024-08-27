// Problem_Link : https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 :
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        map<int, int> mp;
        int n = nums.size(), ans = 0, curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += nums[i];
            if (curr == goal)
                ans++;
            if (curr - goal >= 0)
                ans += mp[curr - goal];
            mp[curr]++;
        }
        return ans;
    }
};