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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          vector<vector<int>> ans ;
        map<int, map<int,vector<int>>> m ; 
        queue<pair<TreeNode* , pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
               
                TreeNode* frnt= q.front().first;
                int col=q.front().second.first;
                int row=q.front().second.second;
                m[col][row].push_back(frnt->val);
                q.pop();
                if(frnt->left)
                    q.push({frnt->left,{col-1,row+1}});
                if(frnt->right)
                    q.push({frnt->right,{col+1,row+1}});
            }
        }
        vector<int> v1;
        for(auto x:m)
        {
            for(auto y:x.second)
            {
                vector<int> v =y.second;
                sort(v.begin(),v.end());
                v1.insert(v1.end(),v.begin(),v.end());
            }
            ans.push_back(v1);
            v1.clear();
            
        }
        return ans;
    }
};