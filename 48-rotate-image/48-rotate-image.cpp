class Solution {
public:
      void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>i)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            int x=0;
            int y=n-1;
            while(x<y)
            {
                swap(matrix[i][x],matrix[i][y]);
                x++;
                y--;
            }
        }
        return ;
        
    }
};