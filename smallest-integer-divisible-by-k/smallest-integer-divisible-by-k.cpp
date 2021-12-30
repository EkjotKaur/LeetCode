class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
        
        long long m=1,r=0;
        while(m<=k)
        {
            r=(r*10+1)%k;
            if(r==0)
                return m;
            m++;
        }
        return -1;
    }
};