// Problem_Link : https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
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
        if (root)
            v.push_back(root->val);
        if (root->left)
            vals(root->left, v);
        if (root->right)
            vals(root->right, v);
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> ans;
        vector<int> v;
        vals(root, v);
        unordered_map<int, int> mp;
        int mx = 0;
        for (auto &x : v)
        {
            mp[x]++;
            if (mp[x] > mx)
                mx = mp[x];
        }
        for (auto &x : mp)
        {
            if (x.second == mx)
                ans.push_back(x.first);
        }

        return ans;
    }
};
