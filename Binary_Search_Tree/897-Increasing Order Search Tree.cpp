// Problem_Link : https://leetcode.com/problems/increasing-order-search-tree/description/
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
    void vals(TreeNode *root, vector<int> &v)
    {

        if (!root)
            return;
        vals(root->left, v);
        v.push_back(root->val);
        vals(root->right, v);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root)
            return root;
        vector<int> v;
        vals(root, v);

        TreeNode *ans = new TreeNode();
        TreeNode *res = ans;
        for (auto &x : v)
        {
            TreeNode *t = new TreeNode(x);
            ans->right = t;
            ans = ans->right;
        }
        return res->right;
    }
};
