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
    void findGoodNodes(TreeNode * root, int &good, int value){
        if(root == NULL)
            return;
        if(root->val >= value){
            good++;
            value = max(value, root->val);
        }
        findGoodNodes(root->left, good, value);
        findGoodNodes(root->right, good, value);
    }
	int goodNodes(TreeNode* root) {
        int goodNode =0;
        if (root == NULL)
            return goodNode;
        int rootVal = root->val;
        findGoodNodes(root,goodNode,rootVal);
        return goodNode;
    }
};