// Problem_Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
/**
 * Definition for a binary tree node.
 **/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inordertraversal(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        inordertraversal(root->left, v);
        v.push_back(root->val);
        inordertraversal(root->right, v);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> v;
        inordertraversal(root, v);
        int i = 0, j = v.size() - 1;
        while (i < j)
        {
            if (v[i] + v[j] == k)
                return true;
            else if (v[i] + v[j] > k)
                j--;
            else
                i++;
        }
        return false;
    }
};