class NumArray {
public:
   inline static int n;
    vector<int> tree;
    NumArray(vector<int>& nums) {
       n=nums.size();
        tree=vector<int> (4*n,0);
        build(nums,0,n-1,1);
    }
    void build(vector<int>& nums,int start,int end,int node)
    {
        if(start==end)
        {
            tree[node]=nums[start];
            return ;
        }
        int mid=(start+end)/2;
        build(nums,start,mid,2*node);
        build(nums,mid+1,end,2*node+1);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    void update(int index, int val,int node=1 ,int start=0,int end=n-1) {
       if(start==end)
       {
           tree[node]=val;
           return ;
       }
        else
        {
            int mid=(start+end)/2;
            if(index<=mid)
            {
                update(index,val,2*node,start,mid);
            }
            else
            {
                update(index,val,2*node+1,mid+1,end);
            }
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }
    
    int sumRange(int left, int right,int node=1,int start=0,int end=n-1) {
        if(left>end||right<start)
            return 0;
        if(left<=start&&end<=right)
        {
            return tree[node];
        }
        int mid=(start+end)/2;
       return  sumRange(left,right,2*node,start,mid)+
        sumRange(left,right,2*node+1,mid+1,end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */