// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
       int isValid(vector<vector<int>> mat){
        // code here
        
        for(int i=0; i<9; i++)
        {
            int A[10], B[10];
            memset(A, 0, sizeof(A));
            memset(B, 0, sizeof(B));
            for(int j=0; j<9; j++)
            {
                if(mat[i][j]>0 && A[mat[i][j]]>0)
                    return 0;
                A[mat[i][j]]++;
                
                if(mat[j][i]>0 && B[mat[j][i]]>0) 
                    return 0;
                B[mat[j][i]]++;
            }
        }
            
        for(int i=0; i<9; i+=3)
        {
            for(int j=0; j<9; j+=3)
            {
                int A[10];
                memset(A, 0, sizeof(A));
                for(int k=i; k<i+3; k++)
                {
                    for(int l=j; l<j+3; l++)
                    {
                        if(mat[k][l]>0 && A[mat[k][l]]>0) 
                            return 0;
                        A[mat[k][l]]++;
                    }
                }
            }
        }

        return 1;
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends