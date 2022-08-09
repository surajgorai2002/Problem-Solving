class Solution {
public:
    int dp[301];
    bool solve(string s ,int i,unordered_map<string ,int> mp)
    {
        if(i>=s.size())
        {
            return true;
        }
        if(dp[i]!=-1)
            return dp[i];
        for(int k=i;k<=s.size()-1;k++)
        {
         string w=s.substr(i,k-i+1);
            if(mp.find(w)!=mp.end())
            {
               if(solve(s,k+1,mp))
                  {
                      return true;
                  }
            }
        }
        return dp[i]=false ;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       int n =s.size();
        memset(dp,-1,sizeof(dp));
        unordered_map<string, int>mp;
        for(string s:wordDict)
        {
            mp[s]++;
        }
       return  solve(s,0,mp);
    }
};