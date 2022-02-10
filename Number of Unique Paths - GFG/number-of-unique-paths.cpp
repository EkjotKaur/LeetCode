// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        int s=max(a,b);
        vector<vector<int>>A(s+1, vector<int>(s+1,1));
        for(int i=2; i<s+1; i++)
        {
            for(int j=2; j<s+1; j++)
            {
                A[i][j]=A[i-1][j]+A[i][j-1];
            }
        }
        return A[a][b];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends