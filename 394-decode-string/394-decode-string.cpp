class Solution {
public:
    string decodeString(string s) {
        string t = "";
        
        int x = 0, n=s.length();
        for(int i=0; i<n; i++)
        {
            // cout<<i<<" ";
            if(s[i]<='9' && s[i]>='0')
                x=x*10+s[i]-'0';
            else if(s[i]=='[')
            {
                i++;
                string y = "";
                int l=0;
                while(s[i]!=']' || l!=0)
                {
                    if(s[i]=='[') l++;
                    else if(s[i]==']') l--;
                    y+=s[i];
                    i++;
                }
                // cout<<y<<" "<<x<<" ";
                // i++;
                y = decodeString(y);
                // cout<<y<<" ";
                for(int j=0; j<x; j++)
                    t+=y;
                x=0;
            }
            else
                t+=s[i];
        }
        
        return t;
    }
};