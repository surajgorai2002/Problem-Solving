class Solution {
public:
   int solve(string& s , int k , int idx, int prev , vector<vector<int>>& dp)
   {
       if (idx>=s.size())
       {
           return 0;
       }
          int ans=INT_MIN;
       if(dp[idx][prev]!=-1)
           return dp[idx][prev];
       if(prev==0||abs(s[idx]-prev)<=k)
       {
           ans=1+solve(s,k,idx+1,s[idx],dp);
       }
       ans=max(ans,solve(s,k,idx+1,prev,dp));
       return dp[idx][prev]=ans;
   }
    int longestIdealString(string s, int k) {
        int n =s.size();
     
        vector<vector<int>> dp(n+1,vector<int>(150,-1));
        int ans=solve(s,k,0,0,dp);
        return ans ;
    }
};