class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int c=0,t=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=' ')
                c++;
            else if(c!=0)
            {
                t=c;
                c=0;
            }
        }
        
        // cout<<t<<" ";
        return c>0?c:t;
    }
};