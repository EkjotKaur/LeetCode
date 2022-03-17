class Solution {
public:
    int scoreOfParentheses(string s) {
     
        int left=0,right=0,n=s.length(),side=0;
        stack<int>S;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
               S.push(-1);
            else
            {
                if(S.top()==-1)
                {
                    S.pop();
                    S.push(1);
                }
                else
                {
                    int x = 0;
                    while(!S.empty() && S.top()>=1)
                    {
                        x+=S.top();
                        S.pop();
                    }
                    if(!S.empty()) S.pop();
                    x*=2;
                    S.push(x);
                }
            }
            // if(!S.empty()) cout<<S.top()<<" ";
        }
        int ans=0;
        while(!S.empty())
        {
            ans+=S.top(); 
            S.pop();
        }
        return ans;
    }
};