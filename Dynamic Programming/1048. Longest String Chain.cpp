/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the 
other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a 
predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 
Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
*/

//***********************************************************************************************

// Solution
// We first sort the words in vector
// We make a function to check whether two strings are predecessor or not
// We take the string if either its previous=-1 or it's isPredecessor(s1,s2)==true
// If taken then previous_index=cur_index and cur_index=cur_index+1

class Solution {
public:
    int dp[1002][1002];
    bool isPredecessor(string &s, string &t)
    {
        int n=s.length(), m=t.length();
        if(m-n!=1)
            return false;
        int count=0;
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
            }
            else
            {
                count++;
            }
            j++;
            if(count>1)
                return false;
        }
        return true;
    }
    int solve(vector<string>& words, int i, int j, int n)
    {
        if(j>=n)
            return 0;
        if(i!=-1 && dp[i][j]!=-1)
            return dp[i][j];
        int taken=0, not_taken=0;
        if(i==-1 || isPredecessor(words[i], words[j]))
        {
            taken = 1+solve(words, j, j+1, n);
        }
        not_taken= solve(words, i, j+1, n);
        if(i!=-1)        
            dp[i][j] = max(taken, not_taken);
        return max(taken, not_taken);
    }
    static bool comp(string &s, string &t)
    {
        return s.length()<t.length();
    }
    int longestStrChain(vector<string>& words) {
        int ans=1;
        sort(words.begin(), words.end(), comp);
        memset(dp, -1, sizeof(dp));
        ans= solve(words, -1, 0, words.size());
        return ans;
    }
};
