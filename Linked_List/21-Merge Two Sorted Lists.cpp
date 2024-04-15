// Problem_Link : https://leetcode.com/problems/merge-two-sorted-lists/description/
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
// Solution 1 : Best One
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *l1 = list1;
        ListNode *l2 = list2;
        ListNode *ans = new ListNode();
        ListNode *res = ans;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                ans->next = l1;
                l1 = l1->next;
            }
            else
            {
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        ListNode *c = l1 ? l1 : l2;
        ans->next = c;

        return res->next;
    }
};

// Solution 2 :
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> v;
        ListNode *ans = new ListNode();
        ListNode *res = ans;

        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }
        if (list2 == NULL && list1 == NULL)
        {
            return NULL;
        }
        while (list1 != nullptr)
        {
            v.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            v.push_back(list2->val);
            list2 = list2->next;
        }
        sort(v.begin(), v.end());
        for (auto &x : v)
        {
            ListNode *n = new ListNode(x);
            ans->next = n;
            ans = ans->next;
        }
        return res->next;
    }
};