/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
Example 1:
Input: root = [4,2,6,1,3]
Output: 1
Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
Constraints:
The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
*/

// Solution

class Solution {
public:
    void inOrder(TreeNode *root, TreeNode* &prev, int &ans)
    {
        if(root==NULL)
            return;
        inOrder(root->left, prev, ans);
        if(prev)
        {
            ans=min(abs(root->val-prev->val), ans);
        }
        prev=root;
        inOrder(root->right, prev, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        TreeNode *prev=NULL;
        inOrder(root, prev, ans);
        return ans;
    }
};
