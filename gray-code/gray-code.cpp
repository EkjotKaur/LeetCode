class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) return {0};
        if(n==1) return {0,1};
        vector<int>A = {0,1};
        int i=2,k=2;
        int m = pow(2,n);
        while(i<m)
        {
            for(int j=k-1; j>=0 && i<m; j--, i++)
            {
                A.push_back(A[j]+k);
            }
            k*=2;
        }
        
        return A;
    }
};