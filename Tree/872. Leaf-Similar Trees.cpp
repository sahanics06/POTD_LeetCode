/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value 
sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Example 1:

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:

Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false 

Constraints:

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200]

*/

// Solution

class Solution {
public:
    void solve(TreeNode* root, vector<int>&a1)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            a1.push_back(root->val);
        solve(root->left, a1);
        solve(root->right, a1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a1,a2;
        solve(root1,a1);
        solve(root2,a2);
        if(a1.size()!=a2.size())
            return false;
        for(int i=0; i<a1.size(); i++)
        {
            if(a1[i]!=a2[i])
                return false;
        }
        return true;
    }
};
