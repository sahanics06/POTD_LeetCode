/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

// Solution using memoization and recursion

class Solution {
public:
    int m[501][501];
    int palindromicSubsequence(string s, string r)
    {
        if(s.length()==0 || r.length()==0)
        {
            return 0;
        }
        int t;
        if(m[s.length()][r.length()]!=-1)
            return m[s.length()][r.length()];
        if(s[0]==r[0])
        {
            return m[s.length()][r.length()]= 1+palindromicSubsequence(s.substr(1), r.substr(1));
        }
        else
        {
            return m[s.length()][r.length()]= max(palindromicSubsequence(s, r.substr(1)), palindromicSubsequence(s.substr(1), r));
        }
    }
    int minInsertions(string s) {
        string r=s;
        memset(m, -1, sizeof(m));
        reverse(r.begin(), r.end());
        return s.length()-palindromicSubsequence(s,r);
    }
};

// Solution using Dynamic programming

class Solution {
public:
    int minInsertions(string s) {
        string r=s;
        int n=s.length();
        int dp[n+1][n+1];
        reverse(r.begin(), r.end());
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==r[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return s.length()-dp[n][n];
    }
};
