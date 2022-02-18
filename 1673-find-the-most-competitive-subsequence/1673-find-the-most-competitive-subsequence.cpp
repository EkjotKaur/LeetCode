class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>S;
        // stack<int>S;
        
        S.push_back(nums[0]);
        int c=1, n=nums.size();
        for(int i=1; i<n; i++)
        {
            // cout<<S.back()<<"A ";
            while(n-i+c-1>=k && !S.empty() && S.back()>nums[i])
            {
                c--;
                // cout<<S.back()<<" ";
                S.pop_back();
            }
            if(c<k)
            {
              S.push_back(nums[i]);
                c++;  
            } 
        }
        
        return S;
        
    }
};