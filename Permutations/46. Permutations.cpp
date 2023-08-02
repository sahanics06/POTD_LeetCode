/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 
Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

// Solution using Swapping

class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int start)
    {
        if(start==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=start; i<nums.size(); i++)
        {
            swap(nums[i], nums[start]);
            solve(nums, start+1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};

// Solution using set and temp vector

class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, vector<int>&tmp, set<int>&st)
    {
        if(tmp.size()==nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(st.find(nums[i])==st.end())
            {
                tmp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums, tmp, st);
                tmp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>tmp;
        set<int>st;
        solve(nums, tmp, st);
        return ans;
    }
};
