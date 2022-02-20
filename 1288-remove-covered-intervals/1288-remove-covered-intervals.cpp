class Solution {
    static bool cmp(vector<int>&A, vector<int>&B)
    {
        if(A[0]==B[0]) return B[1]<A[1]?1:0;
        return A[0]<B[0]?1:0;
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), cmp);
        // for(auto it:in) cout<<it[0]<<" "<<it[1]<<"  ";
        vector<vector<int>>A;
        A.push_back(in[0]);
        int n=in.size();
        for(int i=1; i<n; i++)
        {
            if(A.back()[1]>=in[i][1])
                continue;
            A.push_back(in[i]);
                
        }
        return A.size();
    }
};