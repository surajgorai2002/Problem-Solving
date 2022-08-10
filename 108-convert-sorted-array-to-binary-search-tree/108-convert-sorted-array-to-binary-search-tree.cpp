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
    TreeNode* solve(vector<int> nums, int start, int end)
    {
       if (start>end)
       {
           return NULL;
       }
        int mid=(start+end)/2;
        TreeNode* new_node=new TreeNode(nums[mid]);
        new_node->left=solve(nums,start, mid-1);
        new_node->right=solve(nums,mid+1, end);
        return new_node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};