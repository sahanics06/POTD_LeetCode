/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order. 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8]. 

Constraints:

n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000
*/

// Solution using recursion and memoization

class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<vector<int>>&pairs, int i, int p_idx)
    {
        if(i==n)
            return 0;
        if(p_idx!=-1 && dp[p_idx][i]!=-1)
            return dp[p_idx][i];
        int taken=0, not_taken=0;
        if(p_idx==-1 || pairs[i][0]>pairs[p_idx][1])
        {
            taken=1+solve(pairs, i+1, i);
        }
        not_taken=solve(pairs, i+1, p_idx);
        if(p_idx!=-1)
            dp[p_idx][i]=max(taken, not_taken);
        return max(taken, not_taken);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        memset(dp, -1, sizeof(dp));
        sort(pairs.begin(), pairs.end());
        return solve(pairs, 0, -1);
    }
};
