// Problem_Link : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
#include <bits/stdc++.h>
using namespace std;

// Solution 1 :
class Solution
{
    typedef long long ll;

public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int mx = INT_MIN;
        for (int i : nums)
            mx = max(mx, i);

        ll cnt = 0;
        ll res = 0;
        for (int l = 0, r = 0; r < n; r++)
        {
            if (nums[r] == mx)
            { // increase the window size untill the number of max elements is not equal to k
                cnt++;
            }
            if (cnt == k)
            {
                // res += (n-r);
                while (l <= r && cnt == k)
                {                   // reduce the window untill the number of max elements is equal to k
                    res += (n - r); // number of elements left in the array after the window
                    if (nums[l] == mx)
                    {
                        cnt--;
                    }
                    l++;
                }
            }
        }
        return res;
    }
};