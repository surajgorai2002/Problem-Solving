class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
      sort (v.begin(),v.end(),[](vector<int>& a,vector<int>& b){
          if(a[0]==b[0])
          {
              return a[1]<b[1];
          }
          return a[0]>b[0];
      });  
        int maxi=v[0][1];
        int c=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[i][1]<maxi)
            {
                c++;
            }
            maxi=max(maxi,v[i][1]);
        }
        return c;
        
    }
};