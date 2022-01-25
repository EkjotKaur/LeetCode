class Solution {
public:
    int minSteps(int n) {
        if(n<2) return 0;
        vector<int>A(n+1, INT_MAX);
        A[0]=0;
        A[1]=0;
        A[2]=2;
        
        for(int i=3; i<=n; i++)
        {
           for(int j=2; j*j<=n; j++)
           {
               int x = i/j;
               if(x*j==i)
                   A[i]=min(A[x]+j,A[i]);
            }
            if(A[i]==INT_MAX) 
                A[i]=i;
        }
        
        return A[n];
    }
};