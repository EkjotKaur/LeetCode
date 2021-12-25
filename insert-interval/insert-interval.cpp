class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        
        int i, n=intervals.size();
        vector<vector<int>>A;
        for(i=0; i<n; i++)
        {
            if(newInterval[1]<intervals[i][0])
            {
                A.push_back(newInterval);
                i--;
                break;
            }
            else if(newInterval[0]<intervals[i][0])
            {
                intervals[i][0]=newInterval[0];
                if(newInterval[1]<=intervals[i][1])
                {
                    return intervals;
                }
                else
                {
                    intervals[i][1]=newInterval[1];
                    A.push_back(intervals[i]);
                }
                break;
            }
            else if(newInterval[0]>=intervals[i][0] && newInterval[0]<=intervals[i][1])
            {
                if(newInterval[1]<=intervals[i][1])
                {
                    return intervals;
                }
                else
                {
                    intervals[i][1]=newInterval[1];
                    A.push_back(intervals[i]);
                }
                break;
            }
            A.push_back(intervals[i]);
        }
        
        if(i==n) 
        {
            A.push_back(newInterval);
            return A;
        }
        
        // cout<<i<<" ";
        int k=A.size();
        for(int j=i+1; j<n; j++)
        {
            if(A[k-1][1]>=intervals[j][0])
            {
                A[k-1][1]=max(A[k-1][1],intervals[j][1]);
            }
            else
            {
                A.push_back(intervals[j]);
                k++;
            }
        }
        return A;
    }
};