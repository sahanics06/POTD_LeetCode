/*
You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. 
Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero. 

Example 1:

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
Example 2:

Input: nums = [4,2,1,2], p = 1
Output: 0
Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= p <= (nums.length)/2
  */

// Solution using Binary Search.

class Solution {
public:
    bool solve(vector<int>&nums, int m, int n, int pair)
    {
        int mx=INT_MAX, p=0, i=0;
        while(i<n-1)
        {
            mx=abs(nums[i]-nums[i+1]);
            if(mx<=m)
            {
                i+=2; // If pair is formed than we go increase by 2
                p++;
            }
            else
            {
                i++;  // If pair is not less than or equal to m than we have to check with the next element to form pair. So increase i by 1
            }
            if(p==pair)
                return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size(), ans=0;
        sort(nums.begin(), nums.end());
        int l=0, r=nums[n-1]-nums[0], m;
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(solve(nums, m, n, p))
            {
                ans=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};
