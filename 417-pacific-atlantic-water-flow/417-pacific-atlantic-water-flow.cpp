class Solution {
public:
    void solve(vector<vector<int>>& heights, int i, int j, vector<vector<int>> &pac,int prev)
    {
        if(i<0||j<0||i>=heights.size()|| j>=heights[0].size()|| pac[i][j]==1||heights[i][j]<prev)
            return ;
       
           pac[i][j]=1;
        solve(heights,i-1,j,pac,heights[i][j]);
        solve(heights,i+1,j,pac,heights[i][j]);
        solve(heights,i,j+1,pac,heights[i][j]);
        solve(heights,i,j-1,pac,heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
      vector<vector<int>> pac(heights.size(),vector<int>(heights[0].size(),0));
      vector<vector<int>> atl(heights.size(),vector<int>(heights[0].size(),0));
        for(int i=0;i<heights[0].size();i++)
        {
            if(pac[0][i]!=1)
            {
                solve(heights, 0,i,pac,INT_MIN);
            }
        }
        for(int i=0;i<heights.size();i++)
        {
            if(pac[i][0]!=1)
            {
                solve(heights, i,0,pac,INT_MIN);
            }
        }
        int n =heights.size();
        int m =heights[0].size();
        for(int i=0;i<heights[0].size();i++)
        {
            if(atl[n-1][i]!=1)
            {
                solve(heights, n-1,i,atl,INT_MIN);
            }
        }
        for(int i=0;i<heights.size();i++)
        {
            if(atl[i][m-1]!=1)
            {
                solve(heights, i, m-1,atl,INT_MIN);
            }
        }
        vector<vector<int>> v;
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pac[i][j]&& atl[i][j])
                {
                    v.push_back({i,j});
                }
            }
        }
        return v ;
    }
};