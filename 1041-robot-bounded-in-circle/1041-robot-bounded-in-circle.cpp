class Solution {
public:
    bool isRobotBounded(string in) {
        
        int n=in.size(); int i=0, j=0, x=0;
        for(int k=0; k<n; k++)
        {
            // cout<<k%n<<" ";
            if(in[k]=='R')
                x=(x+1)%4;
            else if(in[k]=='L') x=x-1>=0?(x-1)%4:3;
            else if(x==0) i++;
            else if(x==1) j++;
            else if(x==2) i--;
            else if(x==3) j--;
        }
        
        if(x!=0 || (i==0 && j==0)) return 1;
        
        return 0;
            
    }
};