// Problem_Link : https://leetcode.com/problems/palindrome-linked-list/description/
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
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *h = head;
        if (!head || !head->next)
            return true;
        while (h != NULL)
        {
            v.push_back(h->val);
            h = h->next;
        }
        int i = 0, j = v.size() - 1;
        while (i <= j)
        {
            if (v[i] != v[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};