class Solution {
public:
    int myAtoi(string s) {
        
        int p=1,d=0, g=1;
        
        long long r=0;
       
        int i=0, n=s.length();
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='+' || s[i]=='-')
        {
            if(s[i]=='-')
                p=0;
            i++;
        }
        
        while(s[i]>='0' && s[i]<='9')
        {
            if(p)
                r=r*10+(s[i]-'0');
            else if(!p)
                r=r*10-(s[i]-'0');
            if(p && r>INT_MAX) return INT_MAX;
            else if(!p && r<INT_MIN) return INT_MIN;
            i++;
            
        }
        
        return r;
            
    }
};