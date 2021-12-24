class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string>A(numRows);
        
        bool plus=1;
        int j=0;
        for(int i=0; i<s.length(); i++)
        {
            // cout<<j<<" ";
            A[j].push_back(s[i]);
            if(j>=numRows-1)
                plus=0;
            if(j<=0)
                plus=1;
            
            if(plus) j++;
            else 
                j--;
            
            
        }
        
        string t="";
        for(auto c:A)
            t+=c;
        return t;
    }
};