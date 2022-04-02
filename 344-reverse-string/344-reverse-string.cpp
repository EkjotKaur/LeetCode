class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        for(;i<j;i++,j--)
        {
            int t=s[i];
            s[i]=s[j];
            s[j]=t;
        }
    }
};