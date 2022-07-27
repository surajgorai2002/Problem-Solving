class Solution {
public:
    int vis[7][7];
   int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    bool check(int i ,int j ,int idx ,vector<vector<char>> &board,string word)
    {
        if(idx>=word.size())
        {
            return true ;
        }
        vis[i][j]=1;
        bool ans =false;
        for(int k =0;k<4;k++)
        {
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x>=0&&y>=0&& x<board.size() && y<board[0].size()&& !vis[x][y] && board[x][y]==word[idx])
            {
               bool tmp= check(x,y,idx+1,board,word);
                 ans=ans|| tmp;
            }
            
        }
        vis[i][j]=0;
        return ans ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        memset(vis,0,sizeof(vis));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                   bool tmp= check(i,j,1,board,word);
                    if(tmp)
                    {
                        return true ;
                    }
                }
            }
        }
        return false;
        
    }
};