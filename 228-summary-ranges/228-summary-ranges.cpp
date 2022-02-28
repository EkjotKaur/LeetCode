class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        string s="";
        int n=-1;
        vector<string>A;
        int f=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(s=="") 
            {
                s+=to_string(nums[i]);
                n=nums[i];
            }
            else if(nums[i]==n+1)
            {
                if(f==0)
                {
                    s+="->"; 
                    f=1;
                }
                n=nums[i];
            }
            else
            {
                if(f==1)
                {
                    A.push_back(s+to_string(n));
                }
                else
                    A.push_back(s);
                f=0;
                n=0;
                s="";
                i--;
            }
            
        }
        
        if(f==1)
        {
            A.push_back(s+to_string(n));
        }
        else if(s!="")
            A.push_back(s);
        // f=0;
        // n=0;
        // s="";
        // i--;
        return A;
    }
};