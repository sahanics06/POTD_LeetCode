/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 
Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 
Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t 
has its subsequence. In this scenario, how would you change your code?

  */

// Solution using recursion

class Solution {
public:
    bool solve(string &s, string &t, int i, int j, int n, int m)
    {
        if(i>=n)
            return true;
        if(j>=m)
            return false;
        if(s[i]==t[j])
            return solve(s, t, i+1, j+1, n, m);
        else
            return solve(s, t, i, j+1, n, m);
    }
    bool isSubsequence(string s, string t) {
        int n=s.length(), m=t.length();
        return solve(s, t, 0, 0, n, m);
    }
};

// Solution using recursion and memoization

class Solution {
public:
    int dp[102][10002];
    int solve(string &s, string &t, int i, int j, int n, int m)
    {
        if(i>=n)
            return true;
        if(j>=m)
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool same=false, not_same=false;
        if(s[i]==t[j])
            same = solve(s, t, i+1, j+1, n, m);
        else
             not_same = solve(s, t, i, j+1, n, m);
        return dp[i][j] = same||not_same;
    }
    bool isSubsequence(string s, string t) {
        int n=s.length(), m=t.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0, n, m);
    }
};
