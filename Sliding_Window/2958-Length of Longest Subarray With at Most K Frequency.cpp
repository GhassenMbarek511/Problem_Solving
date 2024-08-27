// Problem_Link : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 :
class Solution
{
public:
    int maxSubarrayLength(vector<int> &v, int k)
    {
        int n = v.size();
        map<int, int> m;
        int i = 0, j = 0;
        int ans = 1;
        while (i < n && j < n)
        {
            m[v[j]]++;
            while (m[v[j]] > k)
            {
                m[v[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};