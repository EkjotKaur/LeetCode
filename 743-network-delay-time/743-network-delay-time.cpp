class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>G(n+1);
        for(auto i:times)
            G[i[0]].push_back({i[1],i[2]});
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>P;
        vector<int>dist(n+1, INT_MAX);
        P.push({0, k});
        dist[k]=0;
        
        while(!P.empty())
        {
            int u=P.top().second;
            int wt=P.top().first;
            P.pop();
            
            for(auto v:G[u])
            {
                if(wt+v.second<dist[v.first])
                {
                    dist[v.first]=wt+v.second;
                    P.push({dist[v.first],v.first});
                }
            }
        }
        
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        
        return ans;
        
    }
};