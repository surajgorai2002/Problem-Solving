class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
       unordered_map<int,long long > mp;
        long long  ans=0;
        long long mod=1e9+7;
        for(int x:arr)
        {
            mp[x]=1;
            ans++;
        }
       
        sort(arr.begin(),arr.end());
        for(int i =1;i<arr.size();i++)
        {
           long long  c=0;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    if(mp.find(arr[i]/arr[j])!=mp.end())
                    {
                        c+=mp[arr[j]]*mp[arr[i]/arr[j]];
                       
                    }
                }
            }
            mp[arr[i]]=mp[arr[i]]+c;
            ans=(ans+c)%mod;
        }
        return ans;
    }
};