class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int count=0;
        int prenum=0;
        int currnum=0;
        for(int i=0;i<s.size();i++)
        {
          int currnum=mp[s[i]];
            if(currnum>prenum)
            {
                count-=prenum;
            }
            else
            {
                count+=prenum;
            }
            prenum=currnum;
        }
        count+=prenum;
    
    return count;
    }
};