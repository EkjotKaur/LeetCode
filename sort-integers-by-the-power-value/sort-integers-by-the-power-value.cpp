class Solution {
public:
    int getKth(int lo, int ho, int k) {
        unordered_map<int,int>h;
        
        
        for(int i=1; i<=ho; i++)
        {
            int n = i;
            int x=0;
            while(n>1)
            {
                if(h.find(n)!=h.end())
                {
                    x+=h[n];
                    break;
                }
                else if(n&1)
                {
                    n=3*n+1;
                    x++;
                }
                else
                {
                    n/=2;
                    x++;
                }
            }
            h[i]=x;
            // cout<<h[i]<<" ";
        }
        
        vector<vector<int>>A;
        for(int i=lo; i<=ho; i++)
        {
            A.push_back({h[i],i});
            // cout<<h[i]<<" ";
        }
        
        sort(A.begin(),A.end());
        
        return A[k-1][1];
    }
};