class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        
        unordered_map<char,int> mp;
        for(char ch:suits)
        {
            mp[ch]++;
        }
        for(auto it:mp)
        {
            if(it.second>=5)
            {
                return "Flush";
            }
        }
        mp.clear();
        for(int x:ranks)
        {
            mp[x]++;
        }
        string ans ="";
        for(auto it:mp)
        {
            if(it.second>=3)
            {
                ans="Three of a Kind";
            }
            else if(it.second==2)
            {
                if(ans!="Three of a Kind")
                ans="Pair";
            }
        
        }
        if(ans.size()==0)
            return "High Card";
        return ans;
        
    }
};