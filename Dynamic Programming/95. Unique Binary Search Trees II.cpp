/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:

Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]

Constraints:

1 <= n <= 8
  */

// Solution using recursion and memoization

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int,int>, vector<TreeNode*>>mp;
    vector<TreeNode*> solve (int start, int end)
    {
        if(start>end)
        {
            return {NULL};
        }
        if(start==end)
        {
            TreeNode *root=new TreeNode(start);
            return {root};
        }
        if(mp.find({start,end})!=mp.end())
        {
            return mp[{start,end}];
        }
        vector<TreeNode*>result;
        for(int i=start; i<=end; i++)// Making all possible root.
        {
            vector<TreeNode*> left_bst=solve(start, i-1); // left BST
            vector<TreeNode*> right_bst=solve(i+1, end); //Right_BST
            for(auto left_b:left_bst)
            {
                for(auto right_b:right_bst)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=left_b;
                    root->right=right_b;
                    result.push_back(root);
                }
            }
        }
        return mp[{start,end}]=result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
