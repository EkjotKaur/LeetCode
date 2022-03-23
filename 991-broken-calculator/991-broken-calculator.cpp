class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int step=0;
        while(target!=startValue)
        {
            if(target<startValue || target&1) target++;
            else  target/=2;
            step++;
        }
        
        return step;
    }
};