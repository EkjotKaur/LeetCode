class Solution {
    int solve(vector<int>& tops, vector<int>& bottoms, int x, int n)
    {
        int t=0,b=0;
        for(int i=0; i<n; i++)
        {
            if(tops[i]!=x && bottoms[i]!=x) return -1;
            if(tops[i]==x) t++;
            if(bottoms[i]==x) b++;
        }
        
        return min(n-t,n-b);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int x = tops[0];
        int y = bottoms[0];
        int n=tops.size();
        int ans1 = solve(tops, bottoms, x, n);
        int ans2 = solve(tops, bottoms, y, n);
        // cout<<ans1<<" "<<ans2<<" ";
        return ans1==-1&&ans2==-1?-1:ans1!=-1&&ans2!=-1?min(ans1,ans2):ans1==-1?ans2:ans1;
    }
};