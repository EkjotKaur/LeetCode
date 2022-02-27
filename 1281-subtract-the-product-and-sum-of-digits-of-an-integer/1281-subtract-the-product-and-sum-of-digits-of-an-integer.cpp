class Solution {
public:
    int subtractProductAndSum(int n) {
        long long sum=0,prod=1;
        
        while(n)
        {
            sum+=n%10;
            prod=prod*(n%10);
            n/=10;
        }
        
        return prod-sum;
    }
};