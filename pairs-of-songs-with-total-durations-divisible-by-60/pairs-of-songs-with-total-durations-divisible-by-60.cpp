class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>A(60, 0);
        
        
        for(int i=0; i<time.size(); i++)
        {
            A[time[i]%60]++;
        }
        
        int ans=0;
        for(int i=1; i<30; i++)
        {
            ans+=A[i]*A[60-i];
        }
        
        if(A[0]>1)
            ans+=A[0]*(A[0]-1)/2;
        if(A[30]>1)
            ans+=A[30]*(A[30]-1)/2;
        
        return ans;
    }
};