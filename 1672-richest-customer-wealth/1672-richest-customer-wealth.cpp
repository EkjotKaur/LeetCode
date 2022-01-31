class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int y=0;
        for(int i=0; i<accounts.size(); i++)
        {
            int x=0;
            for(int j=0; j<accounts[i].size(); j++)
                x+=accounts[i][j];
            if(x>y)
                y=x;
        }
        return y;
    }
};