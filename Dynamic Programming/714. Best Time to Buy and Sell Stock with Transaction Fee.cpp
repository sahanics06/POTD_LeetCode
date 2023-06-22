/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
  */

// Solution 

class Solution {
public:
    int solve(vector<int>&prices, int n, bool buy, int index, vector<vector<int>>&dp, int fee)
    {
        if(index>=n)
        {
            return 0;
        }
        int profit=0;
        if(dp[index][buy]!=-1)  return dp[index][buy];
        if(buy)
        {
            int taken=solve(prices, n, 0, index+1, dp, fee)-prices[index]-fee;
            int not_taken=solve(prices, n, 1, index+1, dp, fee);
            profit=max({profit, taken, not_taken});
        }
        else
        {
            int taken=prices[index]+solve(prices, n, 1, index+1, dp, fee);
            int not_taken=solve(prices, n, 0, index+1, dp, fee);
            profit=max({profit, taken, not_taken});
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        bool buy=true;
        vector<vector<int>>dp(50001, vector<int>(2,-1));
        return solve(prices, n, buy, 0, dp, fee);
    }
};
