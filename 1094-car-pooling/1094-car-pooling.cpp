class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>d;
        
        for(int i=0; i<trips.size(); i++)
        {
            d[trips[i][1]]+=trips[i][0];
            d[trips[i][2]]-=trips[i][0];
        }
        
        int x=0;
        for(auto c:d)
        {
            if((x+=c.second)>capacity) return 0;
        }
        
        return 1;
    }
};