class Solution {
public:
    // bool issub(string a , string b )
    // {
    //     int n =a.size();
    //     int m=b.size();
    //     int i =0;
    //     int j=0;
    //     while(i<n)
    //     {
    //         if(j<m &&a[i]==b[j])
    //         {
    //             i++;
    //             j++;
    //         }
    //         else
    //         {
    //             i++;
    //         }
    //     }
    //     if(j==m)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      
        vector<int> max_fr(26,0);
        vector<string>ans;
       for(string x:words2)
      {
            vector<int> fr(26,0);
          for(char ch:x)
          {
              fr[ch-'a']++;
          }
            for(int i =0;i<26;i++)
            {
                max_fr[i]=max(max_fr[i],fr[i]);
            }
      }
        for(string x:words1)
        {
              vector<int> fr(26,0);
          for(char ch:x)
          {
              fr[ch-'a']++;
          }
            int flag=0;
            for(int i =0;i<26;i++)
            {
                if(fr[i]<max_fr[i])
                {
                    flag=1;
                    break;
                }
                
            }
            if(!flag)
            {
                ans.push_back(x);
            }
        }
       return ans;
    }
};