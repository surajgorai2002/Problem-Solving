class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        
        string st=to_string(n);
        sort(st.begin(),st.end());
        for(int i =0;i<31;i++)
        {
            int  q=pow(2,i);
            string s=to_string(q);
            sort(s.begin(),s.end());
            if(s==st)
                return true;
        }
        return false;
    }
};