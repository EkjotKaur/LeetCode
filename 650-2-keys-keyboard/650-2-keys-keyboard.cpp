class Solution {
public:
    int minSteps(int n) {
        int ans=0, i=2;
        for(i=2;n>1;i++)
        {
            while(n%i==0)
            {
                ans+=i;
                n/=i;
            } 
        }
        return ans;
    }
};