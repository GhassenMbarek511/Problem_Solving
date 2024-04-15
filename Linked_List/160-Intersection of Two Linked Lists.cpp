// Problem_Link : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, bool> mp;
        ListNode *L1 = headA;
        while (L1 != NULL)
        {
            mp[L1] = true;
            L1 = L1->next;
        }

        ListNode *L2 = headB;
        while (L2 != NULL)
        {
            if (mp[L2] == true)
            {
                return L2;
            }
            L2 = L2->next;
        }
        return NULL;
    }
};