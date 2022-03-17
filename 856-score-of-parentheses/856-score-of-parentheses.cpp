class Solution {
public:
    int scoreOfParentheses(string s) {
     
        int n=s.length(), ans=0;
        stack<int>S;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(') S.push(-1);
            else
            {
                int x = 0;
                while(!S.empty() && S.top()>=1)
                {
                    x+=S.top();
                    S.pop();
                }
                S.pop();
                x=x>0?x*2:1;
                S.push(x);
            }
        }
        while(!S.empty())
        {
            ans+=S.top(); 
            S.pop();
        }
        return ans;
    }
};