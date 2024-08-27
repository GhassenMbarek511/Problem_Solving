// Problem_Link : https://leetcode.com/problems/get-equal-substrings-within-budget/description/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 :
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        int start = 0;
        int current_cost = 0;
        int max_length = 0;

        for (int end = 0; end < n; ++end)
        {
            current_cost += abs(s[end] - t[end]);

            while (current_cost > maxCost)
            {
                current_cost -= abs(s[start] - t[start]);
                ++start;
            }

            max_length = max(max_length, end - start + 1);
        }

        return max_length;
    }
};