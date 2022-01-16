class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int x=0, n=seats.size();
        int ans=0, flag=-1, p=-1;
        for(int i=0; i<n; i++)
        {
            if(seats[i]==1)
            {
                ans=max(ans, x);
                x=0;
                if(flag==-1) flag=i;
                p=i;
            }
            else
                x++;
        }
        ans=max(ans, x);
        ans = (ans+1)/2;
        
        if(seats[0]==0)
            ans=max(ans, flag);
        if(seats[n-1]==0)
            ans=max(ans, n-1-p);
        return ans;
    }
};