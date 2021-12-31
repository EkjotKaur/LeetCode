class Solution {
public:
    int twoEggDrop(int n) {
        
        int x = sqrt(2*n);
        int y = sqrt(n);
        
        // cout<<x<<" "<<y<<"  ";
        int i=y;
        for(i=y; i<=x; i++)
        {
            // cout<<i*(i+1)/2<<" ";
            if(i*(i+1)/2==n)
                return i;
            else if(i*(i+1)/2>n)
                return i;
            
        }
        
        return i;
    }
};