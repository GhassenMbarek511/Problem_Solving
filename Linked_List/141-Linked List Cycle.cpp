// Problem_Link : https://leetcode.com/problems/linked-list-cycle/description/
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
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;

        unordered_set<ListNode *> visited;
        ListNode *current = head;

        while (current != NULL)
        {
            if (visited.find(current) != visited.end())
            {
                return true;
            }
            visited.insert(current);
            current = current->next;
        }

        return false;
    }
};

// Solution 2 :

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *h = head, *t = head;
        while (t != NULL && t->next != NULL)
        {
            h = h->next;
            t = t->next->next;
            if (h == t)
                return true;
        }
        return false;
    }
};

// Solution 3 :
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        int n = 1e4 + 5;
        while (n-- && head != nullptr)
            head = head->next;
        return head != nullptr;
    }
};
