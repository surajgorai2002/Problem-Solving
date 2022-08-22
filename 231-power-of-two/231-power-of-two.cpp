class Solution {
public:
    bool isPowerOfTwo(int n) {
     if(n<=0)
         return false;
        long long k =n&(n-1);
        if(n>0 && k==0)
            return true;
        else
            return false;
    }
};