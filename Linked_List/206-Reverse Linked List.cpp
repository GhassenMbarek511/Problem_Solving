// Problem_Link : https://leetcode.com/problems/reverse-linked-list/description/
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

// Solution 1 :

class Solution
{
public:
    ListNode *rev(ListNode *current, ListNode *parent)
    {
        ListNode *old_next = current->next;
        current->next = parent;
        if (old_next)
            return rev(old_next, current);
        return current;
    }
    ListNode *reverseList(ListNode *h)
    {
        if (!h || !h->next)
            return h;
        return rev(h, nullptr);
    }
};

// Solution 2 :

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // if list is empty
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *forward = nullptr;

        while (curr != nullptr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};