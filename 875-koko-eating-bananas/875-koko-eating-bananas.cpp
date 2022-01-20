class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        sort(piles.begin(), piles.end());
        int n=piles.size();
        int l=1, h=piles[n-1];
        int ans=h;
        int flag=0;
        while(l<=h)
        {
            int sum=0,mid=l+(h-l)/2;
            for(int i=0; i<n; i++)
            {
                sum+=piles[i]/mid;
                sum=piles[i]%mid==0?sum:sum+1;
                if(sum>H)
                    break;
            }
            // cout<<mid<<" "<<sum<<"\n";
            if(sum==H)
            {
                flag=1;
                ans=min(ans, mid);
                h=mid-1;
            }
            else if(sum>H) l=mid+1;
            else if(sum<H)
            {
                if(flag==0) ans=min(ans, mid);
                h=mid-1;
            }
            
        }
        
        return ans;
    }
};