class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>h;
        
        for(int i=0; i<arr.size(); i++)
            h[arr[i]]++;

        priority_queue<int, vector<int>, greater<int>>p;
        
        for(auto i:h)
            p.push(i.second);
        
        while(k>=p.top() && !p.empty())
        {
            k-=p.top();
            p.pop();
        }
        
        return p.size();
        
    }
};