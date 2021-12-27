class Solution {
public:
    int findComplement(int num) {
        
        int n=0, i=0;
        while(num)
        {
            bool x = num%2;
            x=!x;
            num>>=1;
            n+=pow(2,i)*x;
            i++;
        }
        
        return n;
    }
};