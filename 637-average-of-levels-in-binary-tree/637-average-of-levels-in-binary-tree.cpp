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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> v;
        while(!q.empty())
        {
            int sz=q.size();
           double s=0;
            int n=0;
            while(sz--)
            {
                TreeNode* tmp=q.front();
                q.pop();
                s=s+tmp->val;
                n++;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
           double avg=s/n;
             v.push_back(avg);
        }
        return v;
       
    }
};