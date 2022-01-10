class Solution {
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int c=0;
        int i;
        for(i=0; i<a.size() && i<b.size(); i++)
        {
            int x = a[i]-'0';
            int y = b[i]-'0';
            int z = x+y+c;
            if(z==0 || z==1)
            {
                c=0;
                b[i]=z+'0';
            }
            else if(z==2)
            {
                c=1;
                b[i]='0';
            }
            else
            {
                c=1;
                b[i]='1';
            }
            // cout<<b[i]<<" ";
            // i++;
        }
        // cout<<i<<" ";
        while(i<a.size())
        {
            int x = a[i]-'0';
            int z = x+c;
            if(z==0 || z==1)
            {
                c=0;
                b+=(z+'0');
            }
            else if(z==2)
            {
                c=1;
                b+='0';
            }
            i++;
        }
        
        while(i<b.size())
        {
            int x = b[i]-'0';
            int z = x+c;
            if(z==0 || z==1)
            {
                c=0;
                b[i]=(z+'0');
            }
            else if(z==2)
            {
                c=1;
                b[i]='0';
            }
            i++;
        }
        if(c!=0)
            b+="1";
        reverse(b.begin(), b.end());
        return b;
    }
};