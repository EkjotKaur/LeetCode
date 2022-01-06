class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>h;
        
        int n=arr.size();
        for(int i=0; i<n; i++)
            h[arr[i]]++;

        // priority_queue<int, vector<int>, greater<int>>p;
        int c = h.size();
        vector<int>p;
        
        for(auto i:h)
            p.push_back(i.second);
    
        sort(p.begin(), p.end());
        int x=c;
        for(int i=0; i<c && k>=p[i]; i++)
        {
            k-=p[i];
            // cout<<p[i]<<" ";
            x--;
        }
        
        return x;
        
    }
};