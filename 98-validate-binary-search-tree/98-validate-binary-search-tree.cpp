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
   int f=1;
    TreeNode* prev=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return ;
        inorder(root->left);
        if(prev!=NULL && root->val<=prev->val)
            f=0;
        prev=root;
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
    inorder(root);
        return f;
    }
};