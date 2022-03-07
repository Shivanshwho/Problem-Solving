class Solution {
public:
    double average(vector<int>& salary) {
        double avg=0;
        
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<salary.size();i++)
        {
            maxi=max(salary[i],maxi);
            mini=min(salary[i],mini);
            avg+=salary[i];
            
        }
        avg-=(mini+maxi);
        avg/=(salary.size()-2);
        return avg;
        
        
    }
};