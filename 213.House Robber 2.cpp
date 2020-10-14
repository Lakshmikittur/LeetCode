/*Question: You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0) return 0;
        
        if(n==1) return nums[0];
        
        if(n==2) return max(nums[0],nums[1]);
        
        vector<int> dp_first(n,0), dp_last(n-1,0);
        
        dp_first[0] = nums[0];
        dp_first[1] = max(nums[0],nums[1]);
        
        dp_last[0] = nums[1];
        dp_last[1] = max(nums[1],nums[2]);
        
        for(int i=2;i<n-1;i++) //from house 0 to n-2
        {
            dp_first[i] = max(dp_first[i-1], nums[i]+dp_first[i-2]);
        }
        
        for(int i=2;i<n-1;i++) //from house 1 to n-1
        {
            dp_last[i] = max(dp_last[i-1], nums[i+1]+dp_last[i-2]);
        }
                   
        
        return max(dp_first[n-2],dp_last[n-2]);
        
    }
};
