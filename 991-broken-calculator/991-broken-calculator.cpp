class Solution {
public:
    int brokenCalc(int startvalue, int target) {
        int ans=0;
        while(target>startvalue)
        {
            ans++;
            if(target%2==0)
                target=target/2;
            else
            {
                target=target+1;
            }
        }
        ans=ans+(startvalue-target);
        return ans;
    }
};