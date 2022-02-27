class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x=0;
        for(;n;n>>=1)
            if(n&1) x++;
        return x;
                
    }
};