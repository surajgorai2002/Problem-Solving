class Solution {
public:
    int c=0;
    int dp[100][100];
   int  solve(int m , int n , int i , int j , int dp[100][100] )
    {
        if(i>m-1 || j>n-1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==m-1&& j==n-1)
        {
         
            return 1 ;
        }
       
       int ans= solve(m ,n , i+1,j,dp)+
        solve(m, n ,i,j+1,dp);
        return dp[i][j]=ans ;
    }
    int uniquePaths(int m, int n) {
        
//         memset(dp,-1,sizeof(dp));
// return solve(m ,n , 0,0,dp);
        vector<vector<int>> dp(m,vector<int> (n,1));
        dp[0][0]=1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
};