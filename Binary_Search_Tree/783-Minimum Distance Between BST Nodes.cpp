// Problem_Link : https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
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

// Solution 1 :
class Solution
{
public:
    void vals(TreeNode *root, vector<int> &v)
    {
        if (root)
            v.push_back(root->val);
        if (root->left)
            vals(root->left, v);
        if (root->right)
            vals(root->right, v);
    }
    int minDiffInBST(TreeNode *root)
    {
        vector<int> v;
        vals(root, v);
        sort(v.begin(), v.end());
        int ans = v[1] - v[0];
        for (int i = 1; i < v.size() - 1; i++)
        {
            int min = v[i + 1] - v[i];
            if (min < ans)
                ans = min;
        }
        return ans;
    }
};

// Solution 2 :

class Solution
{
public:
    void dfs(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    int minDiffInBST(TreeNode *root)
    {
        vector<int> v;
        dfs(root, v);
        int ans = v[1] - v[0];
        for (int i = 1; i < v.size() - 1; i++)
        {
            int min = v[i + 1] - v[i];
            if (min < ans)
                ans = min;
        }
        return ans;
    }
};