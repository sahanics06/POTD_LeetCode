/*
You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
Repeat the process until you form the string target.
Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
Example 2:

Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 1000
All strings in words have the same length.
1 <= target.length <= 1000
words[i] and target contain only lowercase English letters.

*/

//Recursion plus memoization

class Solution {
public:
    int m;// length of target
    int k;// length of every word
    int t[1001][1001];
    int mod=1e9+7;
    int solve(int i, int j, vector<vector<long long>>&freq , string &target)
    {
        if(i==m)
            return 1;
        if(j==k)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        int not_taken=solve(i, j+1, freq, target)%mod;
        int taken=(freq[target[i]-'a'][j]*solve(i+1, j+1, freq, target))%mod;
        return t[i][j]=(not_taken+taken)%mod;
    }
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        k=words[0].size();
        m=target.length();
        vector<vector<long long>> freq(26,vector<long long>(k));
        memset(t,-1, sizeof(t));
        for(int i=0; i<k; i++)
        {
            for(int j=0;j<n; j++)
            {
                char ch=words[j][i];
                freq[ch-'a'][i]++;
            }
        }
        return solve(0,0,freq, target)%mod;
    }
};

// Dynamic programming top down

class Solution {
public:
    int m;// length of target
    int k;// length of every word
    int mod=1e9+7;
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        k=words[0].size();
        m=target.length();
        vector<vector<long long>> freq(26,vector<long long>(k));
        vector<vector<int>>t(m+1, vector<int>(k+1,0));
        //memset(t,-1, sizeof(t));
        t[0][0]=1;
        for(int i=0; i<k; i++)
        {
            for(int j=0;j<n; j++)
            {
                char ch=words[j][i];
                freq[ch-'a'][i]++;
            }
        }
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=k; j++)
            {
                if(j<k)
                    t[i][j+1]=(t[i][j+1]+t[i][j])%mod;
                if(j<k && i<m)
                    t[i+1][j+1]=(t[i+1][j+1]+t[i][j]*freq[target[i]-'a'][j])%mod;
            }
        }
        return t[m][k];
    }
};
