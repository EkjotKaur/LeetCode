class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>A(n+1);
        
        A[0]=0;
        if(n==0) return A;
        A[1]=1;
        if(n==1) return A;
        
        int x = 1;
        for(int i=2; i<n+1; i+=x)
        {
            x*=2;
            for(int j=0; j<x && i+j<n+1; j++)
            {
                A[i+j]=A[j]+1;
            } 
        }
        
        return A;
    
    }
};