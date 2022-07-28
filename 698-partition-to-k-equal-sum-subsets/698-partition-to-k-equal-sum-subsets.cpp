class Solution {
public:
    int vis[17];
    bool check(vector<int>&nums,int bn,int k ,int currsum,int reqsum,int idx)
    {
        if(bn==k-1)
        {
            return true ;
        }
        if(currsum==reqsum)
        {
            return check(nums,bn+1,k,0,reqsum,0);
        }
        if(currsum>reqsum)
        {
            return false ;
        }
        if(idx>=nums.size())
        {
            
            return false;
        }
        if(!vis[idx])
        {
            vis[idx]=1;
           bool k1= check(nums,bn,k,currsum+nums[idx],reqsum,idx+1);
            if(k1)
                return true ;
            vis[idx]=0;
           bool k2=check(nums,bn,k,currsum,reqsum,idx+1);
            return k1|k2;
        }
        else
        {
           return check(nums,bn,k,currsum,reqsum,idx+1);
        }
        return false;
    }
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      int s=0;
        int maxi=INT_MIN;
        for(int x:nums)
        {
            s+=x;
            maxi=max(maxi,x);
        }
        if(s%k!=0)
        {
            return false;
        }
        int reqsum=s/k;
        if(maxi>reqsum)
        {
            return false;
        }
       memset(vis,0,sizeof(vis));
        return check(nums,0,k,0,reqsum,0);
    }
};