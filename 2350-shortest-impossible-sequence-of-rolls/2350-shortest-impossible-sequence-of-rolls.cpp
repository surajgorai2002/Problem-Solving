class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        set<int> s;
        int ans =0;
        for(int x:rolls)
        {
            s.insert(x);
            if(s.size()==k)
            {
                ans++;
                s.clear();
            }
        }
        return ans+1;
        
        
    }
};