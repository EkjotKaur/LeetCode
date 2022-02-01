class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int sell=INT_MIN;
        int p=0;
        
        for(int i=0; i<prices.size()-1; i++)
        {
            if(buy>prices[i])
            {
                buy=prices[i];
                sell=prices[i+1];
            }
            else 
                sell=prices[i+1]>sell ? prices[i+1] : sell;
            p=p<sell-buy ? sell-buy : p;
        }
        
        return p;
        
        
    }
};