/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, 
return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted 
without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

  */


// Solution using DP tabular format

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};


// Solution recursion and memoization. TLE

class Solution {
public:
    int dp[1001][1001];
    int solve(string a, string b, int i, int j, int n, int m)
    {
        if(i>=n || j>=m)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int taken=0, not_taken=0;
        if(a[i]==b[j])
        {
            taken= 1+ solve(a, b, i+1, j+1, n, m);
        }
        not_taken = max(solve(a, b, i, j+1, n, m), solve(a, b, i+1, j, n, m));
        return dp[i][j] = max(taken, not_taken);
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int n=text1.length(), m=text2.length();
        return solve(text1, text2, 0, 0, n, m);
    }
};
