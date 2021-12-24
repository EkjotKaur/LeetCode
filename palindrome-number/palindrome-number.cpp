class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        string A="";
        while(x)
        {
            A.push_back(x%10);
            x/=10;
        }
        
        int n=A.size();
        for(int i=0; i<n/2; i++)
            if(A[i]!=A[n-i-1])
                return 0;
        return 1;
    }
};