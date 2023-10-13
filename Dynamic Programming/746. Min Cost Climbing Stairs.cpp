/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can 
either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
  */

//************************************************************************

// Solution

// Tabular top down approach

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n);
        if(n==2)
            return min(cost[0], cost[1]);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2; i<n; i++)
        {
            dp[i]=cost[i]+min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};

// Recursion and memoization

class Solution {
public:
    int dp[1001];
    int solve(vector<int>&cost, int i)
    {
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int x = cost[i]+solve(cost, i+1);
        int y = cost[i]+solve(cost, i+2);
        return dp[i] = min(x,y);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(solve(cost, 0), solve(cost, 1));
    }
};
