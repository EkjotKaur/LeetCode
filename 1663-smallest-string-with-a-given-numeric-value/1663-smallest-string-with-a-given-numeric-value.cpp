class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        
        while(n-- && n!=k)
        {
            if(k<=26 || k-n<26)
            {
                char c = ('a'+k-n-1);
                s[n]=c;
                k=n;
            }
            else if(k-n>=26)
            {
                s[n]='z';
                k-=26;
            }
            
        }
        return s;
    }
};