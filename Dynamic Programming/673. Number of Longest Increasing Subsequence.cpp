/*
Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.
Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
Constraints:
1 <= nums.length <= 2000
-106 <= nums[i] <= 106
  */

// Solution using Dynamic Programming.

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n, 1), count(n, 1);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i])
                {
                    if(t[j]+1==t[i])
                    {
                        count[i]+=count[j];
                    }
                    else if(t[j]+1>t[i])
                    {
                        t[i]=t[j]+1;
                        count[i]=count[j];
                    }
                }
            }
        }
        int maxi=*max_element(t.begin(), t.end());
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(t[i]==maxi)
            {
                ans+=count[i];
            }
        }
        return ans;
    }
};
