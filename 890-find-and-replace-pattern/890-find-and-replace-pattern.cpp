class Solution {
public:
    string helper(string w)
    {
        char c='a';
        string res="";
        unordered_map<char,char> mp;
        for(char ch:w)
        {
            if(!mp.count(ch))
            mp[ch]=c++;
        }
        for(char ch:w)
        {
            ch=mp[ch];
            res=res+ch;
        }
        return res;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       string p=helper(pattern);
        int c=0;
        vector<string> ans;
        for(string word:words)
        {
            if(helper(word)==p)
            {
              ans.push_back(word);
            }
        }
        return ans;
        
    }
};