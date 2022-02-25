class Solution {
    vector<int> solve(string version1)
    {
        vector<int>A;
        int x = 0;
        for(int i=0; i<version1.length(); i++)
        {
            if(version1[i]=='.')
            {
               A.push_back(x);
               x=0;
            }
            else
            {
                x+=x*10+version1[i]-'0';
            }
        }
        if(x>0) A.push_back(x);
        return A;
    }
public:
    int compareVersion(string version1, string version2) {
        
        vector<int>A = solve(version1);
        vector<int>B = solve(version2);
        

        int n=A.size(), m=B.size(),i=0;
        while(n<m)
        {
            A.push_back(0);
            n++;
        }
        while(m<n)
        {
            B.push_back(0);
            m++;
        }
        while(i<n && i<m)
        {
            if(A[i]<B[i]) return -1;
            else if(A[i]>B[i]) return +1;
            i++;
        }
        
        if(i==n && i==m) return 0;
        if(i<n) return 1;
        return -1;
    }
};