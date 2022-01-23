class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        int digit = log(low)/log(10)+1;
        int n=0,i=0;
        for(i=1; i<=digit && i<=9; i++)
        {
            n=n*10+i;
        }
        vector<int>A;
        int x = pow(10,digit-1);
        int m=n, j=i;
        // cout<<x<<" ";
        while(m<=high && j<=10)
        {
            while(n<=high && i<=10)
            {
               
                if(n>=low && n<=high)
                    A.push_back(n);
                n%=x;
                n=n*10+i;
                // cout<<n<<" ";
                i++;

            }
            n=m*10+j;
            m=n;
            j++;
            i=j;
            x*=10;
        }
        return A;
    }
};