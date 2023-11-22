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
    int isBalancedHelper(TreeNode*root)
    {
        if(!root)return 0;
        int leftheight = isBalancedHelper(root->left);
        if(leftheight==-1)return -1;
        int rightheight = isBalancedHelper(root->right);
        if(rightheight==-1)return -1;
        if(abs(rightheight-leftheight)>1)
            return -1;
        return max(leftheight,rightheight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
       int ans= isBalancedHelper(root);
        if(ans==-1)return false;
        return true;
    }
};