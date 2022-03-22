class Solution {
public:
    string kthLargestNumber(vector<string>& A, int k) {
        unordered_map<string,int>h;
        int n=A.size();
        int x=0;
        for(int i=0; i<n; i++)
        {
            int y=A[i].length();
            x=max(x,y);
        }
        
        for(int i=0; i<n; i++)
        {
            string s(x-A[i].size(),'0');
            A[i]=s+A[i];
        }

        sort(A.rbegin(), A.rend());
        string ans="";
        int i=0;
        while(i<A[k-1].size() && A[k-1][i]=='0') i++;
        for(; i<A[k-1].size(); i++)
            ans+=A[k-1][i];
        return ans==""?"0":ans;
    }
};