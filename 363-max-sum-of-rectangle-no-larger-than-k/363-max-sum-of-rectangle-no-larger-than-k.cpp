class Solution {
public:
    int kadanes(vector<int> nums)
    {
        int s=0;
        int maxi=INT_MIN;
        for(int i =0;i<nums.size();i++)
        {
            s=s+nums[i];
            if(s<nums[i])
            {
                s=nums[i];
            }
            maxi=max(maxi,s);
        }
        return maxi;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//         for(int i=0;i<matrix.size();i++)
//         {
//             vector<int> v(matrix[0].size(),0);
//             for(int j=0;j<matrix.size();i++)
//             {
//                 for(int k=0;k<matrix[0].size();k++)
//                 {
//                     v[k]=v[k]+matrix[j][k];
//                 }
//                 kadanes()
                
//             }
//         }
         if(matrix.empty())
            return 0;
        int sol = INT_MIN;
        int row= matrix.size(), column = matrix[0].size();
        for(int l=0;l<column;l++){
            vector<int> temp(row,0);
            for(int r=l; r<column;r++){
                for(int i=0;i<row;i++){
                    temp[i] += matrix[i][r];
                }
            set<int> accuSet;
            accuSet.insert(0);
            int sums = 0, max_sum = INT_MIN;
            for (int sum : temp) {
                sums += sum;
                set<int>::iterator it = accuSet.lower_bound(sums - k);
                if (it != accuSet.end()) max_sum = max(max_sum, sums - *it);
                accuSet.insert(sums);
            }
            sol = max(sol, max_sum);
            }
        }
        return sol;
    }
};