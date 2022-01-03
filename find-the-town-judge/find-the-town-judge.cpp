class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n == 1)
             return 1;
        vector<int>h(n+1);
        
        for(int i=0; i<trust.size(); i++)
        {
            h[trust[i][0]]--;
            h[trust[i][1]]++;
        }
        for(int i=1; i<h.size(); i++)
            if(h[i]==n-1) return i;
       
        return -1;
    }
};