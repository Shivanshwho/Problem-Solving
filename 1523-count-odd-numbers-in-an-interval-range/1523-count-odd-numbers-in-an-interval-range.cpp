class Solution {
public:
    int countOdds(int low, int high) {
        int diff= (high-low);
        if(diff%2==0 && low%2==1)
        {
            return diff/2+1;
        }
        else{
            return diff/2+ (low%2==1)+(high%2==1);
        }
        
    }
};