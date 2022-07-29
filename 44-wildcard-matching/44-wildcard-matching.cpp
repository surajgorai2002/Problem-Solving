class Solution {
public:
    // int dp[2001][2001];
    // bool solve(int i , int j , string &s , string & p)
    // {
    //     if(i<0&&j<0)
    //     {
    //         return true ;
    //     }
    //     if(i<0&& j>=0)
    //     {
    //         for(int k=0;k<=j;k++)
    //         {
    //             if(p[k]!='*')
    //                 return false;
    //         }
    //         return true ;
    //     }
    //     if(j<0&& i>=0)
    //     {
    //         return false ;
    //     }
    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }
    //     if(s[i]==p[j] || p[j]=='?')
    //     {
    //        return dp[i][j]= solve(i-1,j-1,s,p);
    //     }
    //     else if(p[j]=='*')
    //     {
    //      return dp[i][j]=   solve(i-1,j,s,p)||solve(i,j-1,s,p);
    //     }
    //     return 0;
    // }
    bool isMatch(string s, string p) {
      // memset(dp,-1,sizeof(dp));
        int n=s.size();
        int m =p.size();
        // return solve(n-1,m-1,s,p);
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=1;j<=m;j++)
        {
            int flag=true;
            for(int k =0;k<j;k++)
            {
                if(p[k]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1]|| p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[n][m];
        
    }
};