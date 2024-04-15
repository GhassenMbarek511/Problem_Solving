// Problem_Link : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
/**
 * Definition for singly-linked list.

 **/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int ans = 0;
        while (head)
        {
            ans = (ans << 1) + head->val;
            head = head->next;
        }
        return ans;
    }
};