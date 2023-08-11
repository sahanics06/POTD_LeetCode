/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a 
total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any 
combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer. 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
  */

// Solution recursion memoization

class Solution {
public:
    int dp[301][5001];
    int solve(int sum, vector<int>&coins, int i, int tmp, int n)
    {
        if(i>=n || tmp>=sum)
        {
            if(tmp==sum)
                return dp[i][tmp]= 1;
            return 0;
        }
        int taken=0;
        if(dp[i][tmp]!=-1)
            return dp[i][tmp];
        if(tmp<=sum)
            taken=solve(sum, coins, i, tmp+coins[i], n);
        int not_taken=solve(sum, coins, i+1, tmp, n);
        return dp[i][tmp]=taken+not_taken;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(amount, coins, 0, 0, n);
    }
};
