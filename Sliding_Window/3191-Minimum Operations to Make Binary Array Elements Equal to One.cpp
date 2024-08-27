// Problem_Link : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 :
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int nb1 = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            nb1 += nums[i];
        for (int i = 2; i < nums.size(); i++)
        {
            if (nb1 == nums.size())
                return ans;
            if (!nums[i - 2])
            {
                nums[i - 2] = !nums[i - 2];
                nums[i - 1] = !nums[i - 1];
                nums[i] = !nums[i];
                ans++;
                nb1++;
                if (!nums[i - 1])
                    nb1--;
                else
                    nb1++;
                if (!nums[i])
                    nb1--;
                else
                    nb1++;
            }
        }
        return (nb1 == nums.size()) ? ans : -1;
    }
};
