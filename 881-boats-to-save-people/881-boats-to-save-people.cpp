class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int ans=0,n=people.size(),i,j;
        for(i=0,j=n-1; i<n && j>i; j--)
        {
            if(people[j]+people[i]<=limit)
                i++;
            ans++;
        }
        if(i==j) ans++;
        
        return ans;
    }
};