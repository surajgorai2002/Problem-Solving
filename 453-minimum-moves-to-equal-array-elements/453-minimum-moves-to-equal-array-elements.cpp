class Solution {
public:
    int minMoves(vector<int>& nums) {
      int maxi=INT_MAX;
        for(int x:nums)
        {
            maxi=min(maxi,x);
        }
       long long ans=0;
        for(int x:nums)
        {
            ans+=x-maxi;
        }
        return ans;
    }
};