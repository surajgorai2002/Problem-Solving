class Solution {
public:
    int countBinarySubstrings(string s) {
        int  i=0;
        int ans =0;
        int n =s.size();
        while(i<n)
        {
            if(s[i]=='0')
            {
                int c=0;
                while(i<n && s[i]=='0')
                {
                    c++;
                    i++;
                }
                int j =i;
                int c1=0;
                while(j<n && s[j]=='1')
                {
                    c1++;
                    j++;
                }
               ans+=min(c,c1);
                
            }
           else if(s[i]=='1')
            {
                int c=0;
                while(i<n && s[i]=='1')
                {
                    c++;
                    i++;
                }
                int j =i;
                int c1=0;
                while(j<n && s[j]=='0')
                {
                    c1++;
                    j++;
                }
                ans+=min(c,c1);
                
            }
        }
        return ans ;
        
        
    }
};