/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Input: nums = [2,2,3,2]
Output: 3
Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
  */

// Solution using bit manipulation. Most optimal solution T.C- O(N) and Space- O(1).

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0;
        for(int i=0; i<nums.size(); i++)
        {
            // Since we are taking XOR operation so bits will be taken care of
            ones=ones^nums[i]&~twos;//This line is adding element if it is first time so we are checking the "twos" also
            twos=twos^nums[i]&~ones;// This line is for adding element if it has encountered for the second time so we have given "ones" and when adding in "twos" we remove in "ones". XOR with same number makes those bits zero.
        }
        return ones;
    }
};

// Solution using bit manipulation. T.C- 32*N ans Space-O(1).
// In this we have used % 3 concept because every number apperaing for 3 times will have there bits set for 3 times in every same position.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<32; i++)
        {
            int sum=0;
            for(int j=0; j<nums.size(); j++)
            {
                if(((nums[j]>>i)&1)==1)
                {
                    sum++;
                    sum%=3;
                }
            }
            if(sum!=0)
            {
                ans|=sum<<i;
            }
        }
        return ans;
    }
};

// Solution using Sort and then checking the one number presence. T.C- NlogN for sorting ans space O(1).

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=1, n=nums.size();
        while(i<n)
        {
            if(nums[i]!=nums[i-1])
            {
                return nums[i-1];
            }
            i+=3;
        }
        return nums[n-1];
    }
};

// Solution using unordered map for storing frequency count. If frequency ==1 return element. T.C- O(N) ans space- O(N).

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second==1)
            {
                return x.first;
            }
        }
        return 0;
    }
};


