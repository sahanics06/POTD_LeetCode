/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
  */
// Solution using Brute Force method
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>answer(2);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        for(int i=0; i<nums1.size(); i++)
        {
            bool flag=true;
            for(int j=0; j<nums2.size(); j++)
            {
                if(nums1[i]==nums2[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
            {
                answer[0].push_back(nums1[i]);
            }
        }
        for(int i=0; i<nums2.size(); i++)
        {
            bool flag=true;
            for(int j=0; j<nums1.size(); j++)
            {
                if(nums2[i]==nums1[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
            {
                answer[1].push_back(nums2[i]);
            }
        }
        return answer;
    }
};

// Solution using set

class Solution {
public:
    vector<int> solve(vector<int>&nums1, vector<int>&nums2)
    {
        unordered_set<int>s;
        bool flag=true;
        for(int i=0; i<nums1.size(); i++)
        {
            flag=true;
            for(int j=0; j<nums2.size(); j++)
            {
                if(nums1[i]==nums2[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                s.insert(nums1[i]);
            }
        }
        return vector<int>(s.begin(), s.end());
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {solve(nums1, nums2), solve(nums2, nums1)};
    }
};

// Solution using hashmap so reducing one for loop.
class Solution {
public:
    vector<int> solve(vector<int>&nums1, vector<int>&nums2)
    {
        unordered_set<int>v;
        unordered_map<int, int>m;
        bool flag=true;
        for(int i=0; i<nums2.size(); i++)
        {
            m[nums2[i]]++;
        }
        for(int i=0; i<nums1.size(); i++)
        {
            if(m.find(nums1[i])==m.end())
            {
                v.insert(nums1[i]);
            }
        }
        return vector<int>(v.begin(), v.end());
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {solve(nums1, nums2), solve(nums2, nums1)};
    }
};
