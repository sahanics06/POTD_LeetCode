/*
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique 
characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order 
of the remaining elements.

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters. 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.

  */

// Using Recursion and bit manipulation

class Solution {
public:
    void solve(int i, int tmp, int &ans, vector<int>&a)
    {
        ans = max(ans, __builtin_popcount(tmp));
        if(i==a.size())
        {
            return;
        }
        if((tmp&a[i])==0)
        {
            int t = tmp|a[i];
            solve(i+1, t, ans, a);
        }
        solve(i+1, tmp, ans, a);
    }
    int maxLength(vector<string>& arr) {
        vector<int>a;
        for(int i=0; i<arr.size(); i++)
        {
          // store the characters in set so that if it has duplicate character then it will not 
          // get inserted and so size of set anf arr[i] will not match
            unordered_set<char>st(arr[i].begin(), arr[i].end());
            if(st.size()!=arr[i].size())
            {
                continue;
            }
            int val=0;
            for(auto it: arr[i])
            {
                val = val | 1<<(it-'a');
            }
            a.push_back(val);
        }
        int ans=0;
        int tmp=0;
        solve(0, tmp, ans, a);
        return ans;
    }
};

// Using recursion and normal iteration to check unique characters in two string.

class Solution {
public:
    bool check(string a, string b)
    {
        vector<int>tmp(26,0);
        for(int i=0; i<a.length(); i++)
        {
            tmp[a[i]-'a']++;
        }
        for(int i=0; i<b.length(); i++)
        {
            if(tmp[b[i]-'a'])
                return false;
        }
        return true;
    }
    void solve(int i, string tmp, int &ans, vector<string>&a)
    {
        ans = max(ans, (int)tmp.length());
        if(i==a.size())
        {
            return;
        }
        if(check(tmp, a[i]))
        {
            string t = tmp+a[i];
            solve(i+1, t, ans, a);
        }
        solve(i+1, tmp, ans, a);
    }
    int maxLength(vector<string>& arr) {
        vector<string>a;
        for(int i=0; i<arr.size(); i++)
        {
            unordered_set<char>st(arr[i].begin(), arr[i].end());
            if(st.size()!=arr[i].size())
            {
                continue;
            }
            a.push_back(arr[i]);
        }
        int ans=0;
        string tmp="";
        solve(0, tmp, ans, a);
        return ans;
    }
};

