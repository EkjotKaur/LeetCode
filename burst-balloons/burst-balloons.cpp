class Solution {

public:
    int maxCoins(vector<int>& iNums) {
        
//         int n=nums.size();
//         vector<long long>num;
//         num.push_back(1);
//         for(auto c:nums) num.push_back(c);
//         num.push_back(1);
//         n+=num.size();
//         vector<vector<long long>>T(n, vector<long long>(n,0));
        
//         for(int k=2; k<n; ++k)
//         {
//             for(int left=0; left<n-k; ++left)
//             {
//                 int right = left+k;
//                 for(int i=left+1; i<right; ++i)
//                 {
//                     // cout<<left<<" "<<i<<" "<<right<<"  ";
//                     cout<< num[left]*num[i]*num[right]<<" ";
//                     T[left][right]=max(T[left][right], num[left]*num[i]*num[right] + T[left][i] + T[i][right]);
//                     // cout<<T[left][right]<<" ";
//                 }
//             }
//         }
//         return T[0][n-1];
         int nums[iNums.size() + 2];
    int n = 1;
    for (int x : iNums) if (x > 0) nums[n++] = x;
    nums[0] = nums[n++] = 1;


    // int dp[n][n] = {};
        vector<vector<int>>dp(n, vector<int>(n));
    for (int k = 2; k < n; ++k) {
        for (int left = 0; left < n - k; ++left){
            int right = left + k;
        int i = left+1;
            for (; i < right; ++i)
                dp[left][right] = max(dp[left][right],
                     nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
        }
    }

    return dp[0][n - 1];
    }
};