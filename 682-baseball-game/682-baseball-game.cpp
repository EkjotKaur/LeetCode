class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>A;
        
        int ans=0;
        
        for(int i=0; i<ops.size(); i++)
        {
            if(ops[i]=="D")
            {
                ans+=2*A.top();
                A.push(2*A.top());
                
            }
            else if(ops[i]=="C")
            {
                ans-=A.top();
                A.pop();
                
            }
            else if(ops[i]=="+")
            {
                int x=A.top();
                A.pop();
                int y=A.top();
                A.push(x);
                A.push(x+y);
                ans+=x+y;
            }
            else
            {
                ans+=stoi(ops[i]);
                A.push(stoi(ops[i]));
            }
            // cout<<A.top()<<" "<<ans<<"\n";
            
            
        }
        
        return ans;
    }
};