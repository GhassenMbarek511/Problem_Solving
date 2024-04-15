// Problem_Link : https://leetcode.com/problems/remove-linked-list-elements/description/
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *h = new ListNode(0);
        h->next = head;
        ListNode *c = h;
        while (c->next != NULL)
        {
            if (c->next->val == val)
            {
                c->next = c->next->next;
            }
            else
                c = c->next;
        }
        return h->next;
    }
};