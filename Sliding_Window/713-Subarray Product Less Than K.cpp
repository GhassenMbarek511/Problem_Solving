// Problem_Link : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 :
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &v, int k)
    {
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int s = 1;
            for (int j = i; j < n; j++)
            {
                s = s * v[j];
                if (s >= k)
                    break;
                ans++;
            }
        }
        return ans;
    }
};