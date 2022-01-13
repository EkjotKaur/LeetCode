class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int n=points.size();
        int x=points[0][0], y=points[0][1], ans=1;
        for(int i=1; i<n; i++)
        {
            if(points[i][0]<=y)
            {
                x = points[i][0];
                y = min(y, points[i][1]);
            }
            else
            {
                ans++;
                x = points[i][0];
                y = points[i][1];
            }
        }
        
        return ans;
    }
};