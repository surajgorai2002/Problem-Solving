class Solution {
public:
    bool possible(vector<int> &nums,int i , int j )
    {
        if(j-i+1<2 || j-i+1>3)
            return false ;
        if(j-i+1==2)
        {
            if(nums[j]==nums[i])
                return true;
            else
                return false ;
        }
        if(nums[i]==nums[i+1] && nums[i+1]==nums[j])
            return true;
        if(nums[i+1]-nums[i]==1 && nums[j]-nums[i+1]==1)
            return true;
        return false;
    }
    bool solve(vector<int> &nums,int i , int j,vector<int> &dp )
    {
        if(i>=nums.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
       
        if(i+1<nums.size() && nums[i+1]==nums[i])
        {
            bool ans1=solve(nums,i+2,j,dp);
            if(nums[i+2]==nums[i+1])
            {
                ans1=ans1|| solve(nums,i+3,j,dp);
                
            }
            return dp[i]=ans1;
        }
        
        else if(i+2<nums.size() && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i]==2)
        {
            return dp[i]=solve(nums,i+3,j,dp);
        }
        
        
     return  dp[i]= 0;
    }
    bool validPartition(vector<int>& nums) {
       int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,n-1,dp);
    }
};