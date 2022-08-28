class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       int n=mat.size();
        int m =mat[0].size();
        for(int g=0;g<m;g++)
        {
            vector<int> tmp;
            for(int i=0,j=g;i<n&&j<m;i++,j++)
            {
                tmp.push_back(mat[i][j]);
            }
            sort(tmp.begin(),tmp.end());
            int k=0;
            for(int i=0,j=g;i<n&& j<m;i++,j++)
            {
                mat[i][j]=tmp[k];
                k++;
            }
        }
        for(int g=1;g<n;g++)
        {
            vector<int> tmp;
            for(int i=g,j=0;i<n && j<m;i++,j++)
            {
                tmp.push_back(mat[i][j]);
            }
            sort(tmp.begin(),tmp.end());
            int k=0;
            for(int i=g,j=0;i<n &&   j<m;i++,j++)
            {
                mat[i][j]=tmp[k];
                k++;
            }
        }
        return mat;
    }
};