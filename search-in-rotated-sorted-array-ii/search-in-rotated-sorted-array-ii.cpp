class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=-1;
        
        int n=nums.size();
        int l=0, h=n-1;
        while(l<=h && l>=0 && h<n)
        {
            // cout<<l<<" "<<h<<" ";
            int mid=l+(h-l)/2;
            // cout<<mid<<" "<<nums[mid]<<"  ";
            if(nums[mid]==target) return 1;
            if(mid!=0 && nums[mid]<nums[mid-1])
            {
                start=mid;
                break;
            }
            else if(mid!=n-1 && nums[mid]>nums[mid+1])
            {
                start=mid+1;
                break;   
            }
            else if(nums[mid]<nums[l])
                h=mid-1;
            else if(nums[mid]==nums[l])
                l++;
            else if(nums[mid]>nums[h])
                l=mid+1;
            else if(nums[mid]==nums[h])
                h--;
            else 
            {
                start=l;
                break;
            }
            
            
        }
        
        if(start==-1) start=0;
        
        // l=start,h=n-1+start;
        // cout<<start<<" ";
        l=0, h=start-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int m=mid;
            // cout<<l<<" "<<h<<" ";
            if(nums[m]==target) return 1;
            else if(nums[m]>target) h=mid-1;
            else l=mid+1;
        }
        
        l=start, h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int m=mid;
            // cout<<l<<" "<<h<<" ";
            if(nums[m]==target) return 1;
            else if(nums[m]>target) h=mid-1;
            else l=mid+1;
        }
        
        return 0;
        
        
    }
};