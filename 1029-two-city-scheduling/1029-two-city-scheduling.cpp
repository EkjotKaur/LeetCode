class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<vector<int>>A(n);
        
        for(int i=0; i<n; i++)
        {
            A[i]={costs[i][0]-costs[i][1], costs[i][0], costs[i][1]};
        }
        
        sort(A.begin(), A.end());
        
        int ans=0;
        int i;
        for(i=0; i<n/2; i++)
        {
            ans+=A[i][1];
        }
        for(;i<n; i++)
            ans+=A[i][2];
        
        return ans;
        
    }
};