class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<double,double>>>G(n);
        int m=edges.size();
        for(int i=0; i<m; i++)
        {
            G[edges[i][0]].push_back({edges[i][1], succProb[i]});
            G[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double>prob(n, -1);
        
        priority_queue<pair<double,double>>P;
        P.push({1,start});
        prob[start]=1;
        
        while(!P.empty())
        {
            double wt=P.top().first;
            double u = P.top().second;
            P.pop();
            
            for(auto it:G[u])
            {
                if(prob[it.first]==-1 || prob[it.first]<wt*it.second)
                {
                    prob[it.first]=wt*it.second;
                    // cout<<prob[it.first]<<" "<<it.first<<"  ";
                    P.push({prob[it.first], it.first});
                }
            }
        }
        return max(0.0,prob[end]);
    }
};