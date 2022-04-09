class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>h;
        
        for(int i=0; i<nums.size(); i++)
            h[nums[i]]++;
        priority_queue<pair<int, int> > g;
        for(auto c:h)
        {
            g.push({c.second, c.first});
        }
        
        vector<int>A;
        while(k--)
        {
            pair<int,int>a = g.top();
            g.pop();
            A.push_back(a.second);
        }
        
        return A;
    }
    
};