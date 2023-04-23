/*
There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

 

Example 1:


Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
Example 2:

Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.
 

Constraints:

n == piles.length
1 <= n <= 1000
1 <= piles[i][j] <= 105
1 <= k <= sum(piles[i].length) <= 2000
*/
// Solution using recursion and memoization

class Solution {
public:
    int n;
    //int t[1001][2001];
    int solve(vector<vector<int>>& piles, int k,int i, vector<vector<int>>&t)
    {
        if(i>=n)
            return 0;
        if(t[i][k]!=-1)
            return t[i][k];
        int not_taken=solve(piles, k, i+1, t);
        int sum=0, taken=0, mx=0;
        for(int j=0; j<min((int)piles[i].size(), k); j++)
        {
            sum+=piles[i][j];
            mx=sum+solve(piles, k-j-1, i+1, t);
            taken=max(mx, taken);
        }
        return t[i][k]=max(taken, not_taken);
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        vector<vector<int>>t(n+1, vector<int>(k+1, -1));
        //memset(t, -1, sizeof(t));
        return solve(piles, k, 0, t);
    }
};

//  Solution using Dynamic programming

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>t(n+1, vector<int>(k+1, 0));
        for(int i=1; i<=n; i++)
        {
            for(int coins=0; coins<=k; coins++)
            {
                int sum=0;
                for(int cur=0; cur<=min((int)piles[i-1].size(), coins); cur++)
                {
                    if(cur>0)
                        sum+=piles[i-1][cur-1];
                    
                    t[i][coins]=max(t[i][coins], sum+t[i-1][coins-cur]);

                }                
            }
        }
        return t[n][k];
    }
};
