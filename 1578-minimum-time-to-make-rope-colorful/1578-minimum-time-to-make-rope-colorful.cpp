class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
       int ans =0;
        for(int i =0;i<s.size()-1;i++)
        {
            if(s[i]!=s[i+1])
                continue;
            if(neededTime[i+1]<neededTime[i])
            {
                swap(neededTime[i],neededTime[i+1]);
            }
            ans+=min(neededTime[i],neededTime[i+1]);
        }
        return ans ;
    }
};