class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k=k%n;
        vector<int>A;
        A=nums;
        for(int i=0; i<n; i++)
        {
            nums[(i+k)%n]=A[i];
        }
    
    }
};