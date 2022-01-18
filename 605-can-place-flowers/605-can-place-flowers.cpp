class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int>a;
        int m=flowerbed.size();
        int c=n;
        a=flowerbed;
        
        
        if(flowerbed.size()==1)
        {
            if(n>1)
                return false;
            else if(n==1 && flowerbed[0]==1)
                return false;
            return true;
        }
        
        if(flowerbed[0]==0 && flowerbed[1]==0)
        {
            n--;
            flowerbed[0]=1;
        }
        
        // cout<<n;
        for(int i=1; i<flowerbed.size()-2; i++)
        {
            if(n<=0)
                return true;
            if(flowerbed[i]==0)
            {
                
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0)
                {
                    n--;
                    flowerbed[i]=1;
                }
            }
            
        }
        
        // cout<<n;
        if(flowerbed[m-1]==0 && flowerbed[m-2]==0)
        {
            n--;
            flowerbed[m-1]=1;
        }
        // cout<<n;
        if(n<=0)
            return true;
        
        if(a[m-1]==0 && a[m-2]==0)
        {
            n--;
            a[m-1]=1;
        }
        
         for(int i=a.size()-2; i>0; i--)
        {
             if(c<=0){
                return true;
             }
             
             if(a[i]==0){
                if(a[i-1]==0 && a[i+1]==0)
                {
                    c--;
                    a[i]=1;
                }
             }
             
        }
        
        if(a[0]==0 && a[1]==0)
        {
            n--;
            a[0]=1;
        }
        
        if(c<=0){
            return true;
        }
        
        return false;
    }
    
};