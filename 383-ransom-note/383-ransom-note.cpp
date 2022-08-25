class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vis(magazine.size(),-1);
        map<char, int> m ;
        int f=0;
        for(int i=0;i<magazine.size();i++)
        {
            m[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(m.find(ransomNote[i])!=m.end() && m[ransomNote[i]]!=0)
            {
                m[ransomNote[i]]--;
            }
            else
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            return false;
        }
        return true ;
    }
};