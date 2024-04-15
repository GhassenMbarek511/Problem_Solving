// Problem_Link : https://leetcode.com/problems/middle-of-the-linked-list/description/
/**
 * Definition for singly-linked list.
 *
 *  */
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

// Solution1 : Two Pointers Technique

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Solution 2 :

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *res = nullptr; // Initialize res pointer
        int n = 0, m, c = 0;
        ;
        ListNode *headd = head;
        while (headd != nullptr)
        {
            n++;
            headd = headd->next;
        }
        m = (n / 2) + 1;
        bool b = false;
        while (head != nullptr && !b)
        {

            c++;

            if (c == m)
            {

                res = head;
                b = true;
            }
            head = head->next;
        }
        return res;
    }
};