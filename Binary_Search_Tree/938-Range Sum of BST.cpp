// Problem_Link : https://leetcode.com/problems/range-sum-of-bst/description/
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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        if (!root)
            return ans;
        if (root->val <= low)
            root->left = nullptr;
        if (root->val >= high)
            root->right = nullptr;
        if (root->val >= low && root->val <= high)
            ans += root->val;
        ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        return ans;
    }
};
