class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string t="";
        int l=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(') l++;
            else if(s[i]==')')
            {
                if(l>0) l--;
                else s[i]='#';
            }
        }
        
        l=0;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]==')') l++;
            else if(s[i]=='(')
            {
                if(l>0) l--;
                else s[i]='#';
            }
        }
        
        for(int i=0; i<s.length(); i++)
                if(s[i]!='#') t+=s[i];
        
        
        return t;
    }
};