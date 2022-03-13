class Solution {
public:
    bool isValid(string s) {
        stack<char>T;
        if(s.size()&1)
            return 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='('|| s[i]=='{' || s[i]=='[')
                T.push(s[i]);
            else
            {
                if(T.empty())
                    return 0;
                char t=T.top();
                if(s[i]==')' && t!='(')
                    return false;
                if(s[i]==']' && t!='[')
                    return false;
                if(s[i]=='}' && t!='{')
                    return false;
                T.pop();
            }
        }
        
        return T.empty();
    }
};