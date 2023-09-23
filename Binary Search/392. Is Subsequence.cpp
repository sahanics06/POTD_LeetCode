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

//*************************************************************************************************

// Solution linear

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        int n=s.length(), m=t.length();
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
            }
            j++;
        }
        return i==n?true:false;
    }
};

// For the follow up question if number of strings to check are n i.e. s1,s2,s3,s4,.... then to check every string for subsequence will
// take much more time using the above method. So we use Binary Search by using map of vector and keeping index of every alphabets in 
// string t

// Time Complexity O(mlog(n))

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        int n=s.length(), m=t.length();
        unordered_map<char, vector<int>>mp;
        for(int i=0; i<m; i++)
        {
            mp[t[i]].push_back(i);
        }

        int pre=-1;
        while(i<n)
        {
            char ch = s[i];
            vector<int>tmp = mp[ch];
            if(mp.find(ch)==mp.end())
                return false;
            auto itr = upper_bound(tmp.begin(), tmp.end(), pre);
            if(itr==tmp.end())
                return false;           
            pre = *itr;
            i++;
        }
        return true;
    }
};

