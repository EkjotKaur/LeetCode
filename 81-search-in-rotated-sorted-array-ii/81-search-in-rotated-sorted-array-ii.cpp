class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n=nums.size(),l=0,h=n-1;
        
        int x = 0;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            
            if(nums[mid]==target) return 1;
            else if(mid!=n-1 && nums[mid]>nums[mid+1])
            {
                x=mid+1;
                break;
            }
            else if(mid!=0 && nums[mid]<nums[mid-1])
            {
                x=mid;
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
                x=l;
                break;
            }
        }
        
        
        l=x, h=n-1+x;
        // cout<<x<<" ";
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            
            // cout<<mid<<" "<<l<<" "<<h<<"  ";
            if(nums[mid%n]==target) return 1;
            else if(nums[mid%n]>target) h=mid-1;
            else l=mid+1;
        }
        
        return 0;
        
        
    }
    
};