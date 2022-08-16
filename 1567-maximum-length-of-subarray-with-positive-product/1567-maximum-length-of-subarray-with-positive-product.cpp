class Solution {
public:
    int getMaxLen(vector<int>& nums) {
       int i=0;
        int ans=0;
        int n =nums.size();
        while(i<n)
        {
            while(i<n && nums[i]==0)
            {
                i++;
            }
         int start=i;
            int end=i;
            int neg_coun=0;
            int first_neg=-1;
            int last_neg=-1;
            while(end<n&& nums[end]!=0)
            {
                if(nums[end]<0)
                {
                    neg_coun++;
                    if(first_neg==-1)
                        first_neg=end;
                    last_neg=end;
                }
                
                end++;
            }
            if(neg_coun%2!=0)
            {
                if(first_neg!=-1)
                ans=max(ans,end-first_neg-1);
                if(last_neg!=-1)
                ans=max(ans,last_neg-start);
            }
            else if(neg_coun%2==0)
            {
                ans=max(ans,end-start);
            }
            i=end+1;
        }
        return ans;
    }
};