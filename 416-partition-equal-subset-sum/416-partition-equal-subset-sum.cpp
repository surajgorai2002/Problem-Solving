class Solution {
public:
    
    bool partition(vector<int> &nums,int sum,int n,vector<vector<int>>& dp)
    {
        if(sum==0)
            return true;
        if(n<0 || sum<0)
            return false;
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
            if(nums[n]<=sum)
            {
                dp[n][sum] =partition(nums,sum-nums[n],n-1,dp)||partition(nums,sum,n-1,dp);
            }
        else
        {
            dp[n][sum] =partition(nums,sum,n-1,dp);
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
       int s=0;
        int maxi=INT_MIN;
        int n =nums.size();
        for(int x:nums)
        {
            s+=x;
            maxi=max(maxi,x);
        }
        if(s%2!=0)
        {
            return false;
        }
        s=s/2;
        if(s<maxi)
        {
            return false;
        }
        vector<vector<int> >dp(n+1,vector<int>(s+1,-1));
        return partition(nums,s,n-1,dp);
        
    }
};