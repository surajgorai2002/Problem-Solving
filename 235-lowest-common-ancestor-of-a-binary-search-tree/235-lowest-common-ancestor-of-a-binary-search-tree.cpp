/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root==NULL)
          return NULL;
        if(root==p|| root==q)
          return root;
        TreeNode * k1=  lowestCommonAncestor(root->left,p,q);
       TreeNode* k2= lowestCommonAncestor(root->right,p,q);
        if(k1==NULL && k2!=NULL)
        {
            return k2;
            
        }
        else if(k1!=NULL && k2==NULL)
            return k1;
        else if(k1!=NULL && k2!=NULL)
        {
            return root;
        }
        return NULL;
    }
};