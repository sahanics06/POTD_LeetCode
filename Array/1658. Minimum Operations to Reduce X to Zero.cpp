/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element 
from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1. 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to 
reduce x to zero.

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

//****************************************************************************************************
// Solution
// We use prefix sum, ie we keep continuous sum and their index in map. We find the longest subaary with sum =Total-x=target. 
// We check for every time whether present_sum-target is present in map. If it is present then x sum is present_sum-target sum, 
// i.e we take their indexex to find the length of subarray.

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int>mp;
        int sum=0, n=nums.size();
        mp[0]=-1;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            mp[sum]=i;
        }
        if(sum<x)  // If not possible 
            return -1;
        int ans=INT_MIN;
        int reamining_sum=sum-x;
        sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            int find_sum = sum-reamining_sum;
            if(mp.find(find_sum)!=mp.end())
            {
                ans=max(ans, i-mp[find_sum]);
            }
        }
        if(ans==INT_MIN)
            return -1;
        return n-ans;
    }
};
