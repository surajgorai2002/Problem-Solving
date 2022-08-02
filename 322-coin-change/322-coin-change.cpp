class Solution {
public:
     int coinchange2(vector<int> coins,int amount)
    {
        int n =coins.size();
        int t[n+1][amount+1];
        for(int i=0;i<n+1;i++)
        {
            t[i][0]=0;
        }
        for(int j=0;j<amount+1;j++)
        {
            t[0][j]=INT_MAX-1;
        }
        for(int j=1;j<amount+1;j++)
        {
            if(j%coins[0]==0)
            {
                t[1][j]=j/coins[0];
            }
            else
            {
                t[1][j]=INT_MAX-1;
            }
        }
         for(int i=2;i<=n ;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        if(t[n][amount]>=INT_MAX-1)
            return -1;
        return t[n][amount];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        return coinchange2(coins,amount);
    }
};