class Solution {
public:
    double average(vector<int>& salary) {
        
        double sum=0;
        int mi=INT_MAX,mx=INT_MIN,n=salary.size();
        if(n==1) return 0;
        for(int i=0; i<n; i++)
        {
            sum+=salary[i];
            mi=min(mi, salary[i]);
            mx=max(mx, salary[i]);
        }
        
        return (sum-mi-mx)/(n-2);
        
    }
};