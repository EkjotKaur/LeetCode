class Solution {
public:
    int divide(int dividend, int divisor) {
        long long dd = dividend;
        if(divisor==1)
            return dd;
        else if(divisor==-1 && dd==INT_MIN){
           return INT_MAX;
        } 
        else if(divisor==-1) return -dd;
        int n=0;
        int p=1;
        if(dd<0 && divisor<0) p=1;
        else if(dd<0 || divisor<0) p=-1;
        dd = abs(dividend);
        divisor=abs(divisor);
        
        while(dd>=divisor){
            long long temp=divisor, m=1;
            while(temp<<1 <=dd){
                temp<<=1;
                m<<=1;
            }
            dd-=temp;
            n+=m;
        }
        
        // return n;
        return p*n;
    }
};