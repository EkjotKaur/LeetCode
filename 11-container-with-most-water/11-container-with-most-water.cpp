class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        for(;i<j;)
        {
            int x = (j-i)*min(height[i],height[j]);
            if(ans<x) ans=x;
            if(height[i]<height[j]) i++;
            else j--;
        }
       
        return ans;
    }
};