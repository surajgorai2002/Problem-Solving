/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
     vector<vector<int>> levelOrder(Node* root) {
        
           vector<vector<int>> fans;
        if(root==NULL)
            return fans;
        queue<Node* >q;
        q.push(root);
     
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> ans;
            while(sz--)
            {
                
                Node* top=q.front();
                ans.push_back(top->val);
                q.pop();
                for(Node* child:top->children)
                {
                    if(child!=NULL)
                    q.push(child);
                }
            }
            fans.push_back(ans);
        }
        return fans;
    }
};