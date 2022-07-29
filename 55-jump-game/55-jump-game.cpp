class Solution {
public:
    
    bool solve(int idx,vector<int>&nums,vector<int> &dp)
    {
        if(idx>=nums.size())
        {
            return false;
        }
        if(idx==nums.size()-1)
        {
            return true ;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        for(int k=1;k<=nums[idx];k++)
        {
            if(solve(idx+k,nums,dp))
                return true ;
        }
        return dp[idx]= false;
    }
    bool canJump(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,-1);
        // return solve(0,nums,dp);
        
        
        int tmp=0;
        int i=0;
        for(;i<nums.size();i++)
        {
            if(tmp<i)
            {
                return false;
            }
            tmp=max(tmp,i+nums[i]);
            
        }
        return i==nums.size() ;
    }
};