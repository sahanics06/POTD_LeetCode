/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
Constraints:
The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
*/

// Solution

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 1});
        while(!q.empty())
        {
            TreeNode* tmp=q.front().first;
            int data=q.front().second;
            q.pop();
            if(tmp->left==NULL && tmp->right==NULL)
            {
                return data;
            }
            if(tmp->left)
            {
                q.push({tmp->left, data+1});
            }
            if(tmp->right)
            {
                q.push({tmp->right, data+1});
            }
        }
        return 0;
    }
};
