class Solution {
public:
    int kadanes(vector<int> &nums)
    {
        int s=0;
        int n =nums.size();
        int maxi1=INT_MIN;
        for(int i =0;i<n;i++)
        {
        
            s=s+nums[i];    
            if(s<nums[i])
            {
                s=nums[i];
            }
            maxi1=max(maxi1,s);
        }
        return maxi1;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int noncircular=kadanes(nums);
        int total=0;
        for(int i =0;i<nums.size();i++)
        {
            total+=nums[i];
            nums[i]=-nums[i];
        }
       int circular=total+ kadanes(nums);
        if(circular==0)
        {
            return noncircular;
        }
        return max(circular,noncircular);
    }
};