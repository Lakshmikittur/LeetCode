/* Question:Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
a <= b
b - a == k */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> count;
        
        for(auto ele:nums)
        {
            count[ele]++;
        }
        
        int ans=0;
        
        for(auto ele:count)
        {
            if(k!=0 && count.find(ele.first+k)!=count.end())
            {
                ans++;
            }
            else if(k==0 && count[ele.first]>=2)
            {
                ans++;
            }
            else{
                continue;
            }
        }
        return ans;
    }
};
