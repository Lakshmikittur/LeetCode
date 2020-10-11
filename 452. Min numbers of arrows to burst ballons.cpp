class Solution {
public:  
    int findMinArrowShots(vector<vector<int>>& points) {
        
         int n = points.size();
         if(n==0) return 0;
        
        if(n==1) return 1;
        
        sort(points.begin(),points.end());  //sorting by start times
        
        int end = points[0][1];
        int count=1;       
       
        
        for(int i=1;i<n;i++)
        {
            if(points[i][0]>end) //if current ending is greater than the minimum ending then update the end and increment the count
            {
                count++;
                end = points[i][1];
            }
            else
            {
                end = min(end,points[i][1]); //we have to keep end value as minimum because that will be deciding point to choose the bursting position
            }
        }
        
        return count;
        
        
    }
};
