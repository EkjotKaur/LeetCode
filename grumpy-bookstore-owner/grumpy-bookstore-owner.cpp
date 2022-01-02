class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n=grumpy.size();
        int ans=0;
        for(int i=0; i<n; i++)
            if(grumpy[i]==0) ans+=customers[i];
        
        int x=0;
        for(int i=0; i<minutes; i++)
            if(grumpy[i]==1)
                x+=customers[i];

        int y = x;
        
        for(int i=minutes; i<n; i++)
        {
            if(grumpy[i]==1)
                x+=customers[i];
            if(grumpy[i-minutes]==1)
                x-=customers[i-minutes];
            y=max(y,x);
        }
        
        return ans+y;
    }
};