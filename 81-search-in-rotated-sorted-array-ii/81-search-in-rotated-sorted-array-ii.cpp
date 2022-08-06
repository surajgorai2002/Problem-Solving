class Solution {
public:
    int pivot(vector<int>&nums)
    {
        int l =0;
        int h=nums.size()-1;
        if(nums[l]<nums[h])
            return nums[l];
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==nums[0])
                h=mid;
            else if(nums[mid]>nums[0])
            {
                l=mid+1;
            }
            else
            {
                h=mid;
            }
        }
        return h;
        
    }
    bool bs(int l,int h, vector<int> &nums,int target)
    {
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            if(nums[mid]>target)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                return true;
                
            }
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
           else if(nums[mid]>=nums[l])
            {
                if(target<nums[mid] && target>=nums[l])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(target>nums[mid] && target<=nums[r])
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
        }
        return false;
    }
};