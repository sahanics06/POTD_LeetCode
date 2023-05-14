/*
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
In the ith operation (1-indexed), you will:
Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.
The function gcd(x, y) is the greatest common divisor of x and y.
Example 1:
Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
Example 2:
Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
Example 3:
Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
Constraints:
1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106
*/

// Solution using recursion and memoization. Memoization based on visited array. Since visited and count of operation is increasing.

class Solution {
public:
    int n;
    int solve(vector<int>&nums, vector<bool>&vis, int op, unordered_map<vector<bool>,int>&mp)
    {
        if(mp.find(vis)!=mp.end())
            return mp[vis];
        int maxScore=0;
        for(int i=0; i<=n-2; i++)
        {
            if(vis[i]==true)    
                continue;
            for(int j=i+1; j<n; j++)
            {
                if(vis[j]==true)
                    continue;
                vis[i]=true;
                vis[j]=true;
                int cur=op*__gcd(nums[i], nums[j]);
                int remaining=solve(nums, vis, op+1, mp);
                maxScore=max(maxScore,cur+remaining);
                vis[i]=false;
                vis[j]=false;
            }
        }
        return mp[vis]=maxScore;
    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        unordered_map<vector<bool>,int>mp;
        vector<bool>vis(n, false);
        return solve(nums, vis, 1, mp);
    }
};
