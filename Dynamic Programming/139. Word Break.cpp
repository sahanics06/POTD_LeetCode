/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
  */

// Solution using recursion. T.C- O(2^n)

class Solution {
public:
    int n;
    bool solve(unordered_map<string,int>mp, string s, vector<string>& wordDict, int start)
    {
        if(start>=n)
        {
            return true;
        }
        for(int i=start; i<n; i++)
        {
            string st=s.substr(start, i-start+1);
            //cout<<st<<"  "<<start<<endl;
            if(mp.find(st)!=mp.end() && solve(mp,s,wordDict,i+1))
            {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(int i=0; i<wordDict.size(); i++)
        {
            mp[wordDict[i]]++;
        }
        n=s.length();
        return solve(mp,s,wordDict,0);
    }
};


// Solution using recursion and memoization

class Solution {
public:
    int n;
    int dp[301];
    int solve(unordered_map<string,int>mp, string s, vector<string>& wordDict, int start)
    {
        if(start>=n)
        {
            return true;
        }
        if(dp[start]!=-1)
            return dp[start];
        for(int i=start; i<n; i++)
        {
            string st=s.substr(start, i-start+1);
            if(mp.find(st)!=mp.end() && solve(mp,s,wordDict,i+1))
            {
                return dp[start]=1;
            }
        }
        return dp[start]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<wordDict.size(); i++)
        {
            mp[wordDict[i]]++;
        }
        n=s.length();
        return solve(mp,s,wordDict,0);
    }
};
