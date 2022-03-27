class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>>A;
        int n=mat.size(),m=mat[0].size();
        for(int i=0; i<n; i++)
        {
            int x=0;
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==1) x++;
                else break;
            }
            
            A.push_back({x,i});
        }
        
        sort(A.begin(), A.end());
        vector<int>ans;
        for(int i=0; i<k && i<n; i++)
            ans.push_back(A[i].second);
        
        return ans;
    }
};