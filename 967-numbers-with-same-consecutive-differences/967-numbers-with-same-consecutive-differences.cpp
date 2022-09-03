class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int> v , int n , int k)
    {
        if(n==0)
        {
             ans.insert(v);
            return ;
        }
        for(int i=0;i<=9;i++)
        {
            if(abs(v.back()-i)==k)
            {
                v.push_back(i);
                solve(v,n-1,k);
                v.pop_back();
            }
        }
        return ;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> v ;
        for(int i=1;i<=9;i++)
        {
            v.push_back(i);
            solve(v,n-1,k);
            v.pop_back();
        }
        vector<int> fans;
        for(vector<int> x:ans)
        {
            int r=0;
           for(int i=0;i<x.size();i++)
           {
               r=r*10+x[i];
           }
            fans.push_back(r);
        }
        return fans;
    }
};