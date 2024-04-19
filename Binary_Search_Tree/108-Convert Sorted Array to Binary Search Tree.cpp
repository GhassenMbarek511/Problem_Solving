// Problem_Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
    TreeNode *balancedBST(vector<int> &nums, int d, int f)
    {
        if (d > f)
            return nullptr;
        int n = (d + f) / 2;
        TreeNode *bst = new TreeNode(nums[n]);
        bst->left = balancedBST(nums, d, n - 1);
        bst->right = balancedBST(nums, n + 1, f);
        return bst;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        int i = 0, j = nums.size() - 1;
        TreeNode *ans = balancedBST(nums, i, j);
        return ans;
    }
};