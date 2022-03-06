class Solution {
public:
    int countOrders(int n) {
        vector<long long>dp(n);
        dp[0]=1;
        int odd=3, mod=1e9+7;
        for(int i=1; i<n; i++)
        {
            int sum = (odd)*(odd+1)%mod/2;
            dp[i]=dp[i-1]*sum%mod;
            odd+=2;
        }
        
        
        return dp[n-1]%mod;
    }
};