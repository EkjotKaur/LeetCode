class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>A(query_row+1, vector<double>(query_row+1,0));
        if(poured>1) A[0][0]=poured-1;
        else A[0][0]=-poured;
        for(int i=1; i<=query_row; i++)
            for(int j=0; j<=i; j++)
            {
                if(j==0)
                    A[i][j] = A[i-1][0]>0 ? A[i-1][0]/2 : 0;
                else
                {
                    A[i][j] += A[i-1][j]>0 ? A[i-1][j]/2 : 0;
                    A[i][j] += A[i-1][j-1]>0 ? A[i-1][j-1]/2 : 0;
                }
                if(A[i][j]>1) A[i][j]-=1;
                else A[i][j]=-A[i][j];
                
                if(i==query_row && j==query_glass)
                    return A[i][j]>0 ? 1 : abs(A[i][j]);
            }
        return A[query_row][query_glass]>0 ? 1 : -A[query_row][query_glass];

    }
};