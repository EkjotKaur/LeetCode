class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       
        int n=arr.size(), i=1;
        if(n<3) return 0;
        
        for(;i<n-1 && arr[i]>arr[i-1]; i++);
        
        if(i==1) return 0;
        for(;i<n && arr[i]<arr[i-1];i++);
        
        return i==n ? 1 : 0;
    }
    
};