class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=cost.size();
        
        int ans=0, sum=INT_MAX, start=0;
        for(int i=0; i<n; i++)
        {
            ans+=gas[i]-cost[i];
            if(ans<sum)
            {
                sum=ans;
                start=i+1;
            }
            
        }
        
        return ans<0 ? -1 : start%n;
    }
};