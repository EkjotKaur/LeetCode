class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>G(n, vector<int>(m));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || j==0)
                {
                    G[i][j]=matrix[i][j];
                }
                else
                {
                    if(matrix[i][j]==1)
                    {
                        G[i][j]=1;
                        if(matrix[i-1][j]==1 && matrix[i][j-1]==1)
                            G[i][j]+=min(G[i-1][j-1], min(G[i-1][j], G[i][j-1]));                         
                    }
                }
            }
        }
        
                                                         
        int ans=0;                                               
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans+=G[i][j];
                // cout<<G[i][j]<<" ";
            }
        }
                             
        return ans;                                                   
                                                         
                                                          
    }
};