class Solution {
public:
    string simplifyPath(string path) {
       string s="/";
        stack<string>S;
        bool slash=1;
        path+="/";
        int i=0;
        for(i=0; i<path.length(); i++)
        {
            if(!slash && path[i]=='/')
            {
                // cout<<s<<" ";
                if(s=="/.")
                    s="";
                else if(s=="/..")
                {
                    if(!S.empty()) S.pop();
                    s="";
                }
                else
                {
                    S.push(s);
                    s="";
                }
                s+=path[i];
                slash=1;
            }
            else if(path[i]=='/')
                continue;
            else
            {
                slash=0;
                s+=path[i];
            }
            
        }
        string t="";
        while(!S.empty())
        {
            t=S.top()+t;
            S.pop();
        }
        if(t=="") 
            t="/";
        return t;
    }
};