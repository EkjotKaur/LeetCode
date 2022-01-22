class Solution {
    bool bottomUp(int n, vector<int>&dp)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n]=0;
        int x = sqrt(n);
        
        while(x)
        {
            if(!bottomUp(n-x*x, dp))
            {
                dp[n]=1;
                break;
            } 
            else
                x--;
        }
        
        return dp[n];
        
    }
public:
    bool winnerSquareGame(int n) {
        // vector<vector<int>>dp(n+1, vector<int>(n,-1));
        vector<int>dp(n+1, -1);
        
        return bottomUp(n, dp);
        
    }
};