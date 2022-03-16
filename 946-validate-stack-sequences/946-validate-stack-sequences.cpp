class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int>S;
        int i=0,j=0,n=pushed.size();
        for(; i<n && j<n; )
        {
            while(S.empty() && i<n || j<n && i<n && S.top()!=popped[j])
            {
                S.push(pushed[i]);
                i++;
            }
            while(!S.empty() && j<n && S.top()==popped[j])
            {
                S.pop();
                j++;
            }  
        }
        
        while(!S.empty() && j<n && S.top()==popped[j])
        {
            S.pop();
            j++;
        } 
        
        return j==n;
    }
};