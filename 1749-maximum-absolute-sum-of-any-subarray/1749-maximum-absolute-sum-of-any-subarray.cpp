class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int s=0;
        for(int i =0;i<nums.size();i++)
        {
            s=s+nums[i];
            if(s<nums[i])
            {
                s=nums[i];
            }
            maxi=max(maxi,s);
          
        }
        s=0;
        
        for(int i=0;i<nums.size();i++)
        {
            s=s+nums[i];
           if(s>nums[i])
               s=nums[i];
            mini=min(mini,s);
           
        }
        return max(maxi,abs(mini));
    }
};