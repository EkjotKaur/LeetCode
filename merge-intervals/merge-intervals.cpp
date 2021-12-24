class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& IN) {
        sort(IN.begin(),IN.end());
        
        vector<vector<int>>A;
        A.push_back(IN[0]);
        for(int i=1; i<IN.size(); i++)
        {
            int n=A.size();
            if(A[n-1][1]>=IN[i][0])
            {
                if(A[n-1][1]<IN[i][1])
                    A[n-1][1]=IN[i][1];
            }
            else
                A.push_back(IN[i]);
        }
        
        return A;
    }
};