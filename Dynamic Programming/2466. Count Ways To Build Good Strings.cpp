/*
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.
A good string is a string constructed by the above process having a length between low and high (inclusive).
Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.
Example 1:
Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.
Example 2:
Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
Constraints:
1 <= low <= high <= 105
1 <= zero, one <= low
*/

// Only recursion. TLE
class Solution {
public:
    int mod=1e9+7;
    int count=0;
    void solve(int low, int high, int zero, int one, int s, int t)
    {
        if(s+t>high)
        {
            return ;
        }
        if(s+t>=low)
        {
            count=(count+1)%mod;
        }
        solve(low, high, zero, one, s+zero, t);
        solve(low, high, zero, one, s, t+one);
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        solve(low, high, zero, one, 0, 0);
        return count;
    }
};

// Solution optimised code , recursion plus memoization

class Solution {
public:
    int mod=1e9+7;
    int dp[100001];
    int solve(int low, int high, int zero, int one, int len)
    {
        if(len>high)
        {
            return 0;
        }
        if(dp[len]!=-1) return dp[len];
        bool add=false;
        if(len>=low)
        {
            add=true;
        }
        int left=solve(low, high, zero, one, len+zero);
        int right=solve(low, high, zero, one, len+one);
        return dp[len]=(add+left+right)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return solve(low, high, zero, one, 0);
    }
};
