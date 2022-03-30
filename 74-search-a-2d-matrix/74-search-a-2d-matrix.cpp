class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,h=matrix.size()-1;
        int n=matrix.size();
        int m=matrix[0].size();
        int row=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][m-1])
            {
                row=mid;
                break;
            }
            else if(target>matrix[mid][m-1])
                l=mid+1;
            else
                h=mid-1;
        }
        if(row==-1)
            return 0;
        int L=0,H=m-1;
        while(L<=H)
        {
            int MID=(L+H)/2;
            if(target==matrix[row][MID])
                return true;
            else if(target>matrix[row][MID])
                L=MID+1;
            else
                H=MID-1;
        }
                
        return false;
    }
};