/*
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers 
from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. 
The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. 
You may assume that both players are playing optimally. 

Example 1:

Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.
Example 2:

Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win. 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 107
  */

// Solution using recursion and memoization.

/*
  Overview
Before introducing the following approaches, we need to clarify the requirements of the problem. The problem isn't asking for what the final scores will be, 
but only if Player 1 will have a score greater than or equal to Player 2. Thus, to make the task easier, we can focus only on the score difference.

10 points for Player 1 and 10 points for Player 2
or
100 points for Player 1 and 10 points for Player 2
There is no difference, as long as Player 1's score is greater than or equal to Player 2's, Player 1 has won.

During Player 1's turn, if he scores x points, his score difference to Player 2 will increase by x.

Conversely, if Player 2 scores y points during his turn, it will decrease the score difference between Player 1 and Player 2 by y points.

Approach 1: Recursion
Intuition
We can define a recursive function maxDiff(left, right) that takes the starting and ending indices left and right of the list as input to maximize the current score 
difference between the two players.

At each step, we simulate the current player selecting a number from the list and then call the function recursively to determine the optimal move for the next player. 
We update the score difference based on the player's move, and then return the maximum score difference that the first player can achieve.
  */

class Solution {
public:
    int dp[21][21];
    int solve(vector<int>&nums, int i, int j)
    {
        if(i>j) 
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==j)
            return dp[i][j]=nums[i];
        // We will take the ith and jth element and then subtract it from the solve of rest.
        // Will take the maximum. ANd if the final result is greater then 0 means first>=second
        int take_i=nums[i]-solve(nums, i+1, j);
        int take_j=nums[j]-solve(nums, i, j-1);
        return dp[i][j]=max(take_i, take_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, nums.size()-1)>=0;
    }
};
