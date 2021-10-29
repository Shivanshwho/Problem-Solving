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
    TreeNode* build_tree(map<int,int>&mp,vector<int>&in,vector<int>&post,int l,int r, int &p_index)
    {
        if(l>r)return NULL;
        int pivot= mp[post[p_index]];
        p_index--;
        TreeNode* root= new TreeNode(in[pivot]);
        root->right= build_tree(mp,in,post,pivot+1,r,p_index);
        root->left= build_tree(mp,in,post,l,pivot-1,p_index);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int p_index=n-1;
       TreeNode* root=  build_tree(mp,inorder,postorder,0,n-1,p_index);
        return root;
    }
};