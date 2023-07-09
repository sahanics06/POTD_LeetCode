/*
The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aababbb"
Output: 3
Explanation:
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.
Example 2:

Input: s = "abcde"
Output: 0
Explanation:
No letter occurs more than once in s, so the variance of every substring is 0.
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
  */

// Solution optimal, we have take two characters and find the variance in them, in between we can have different characters also because that will not add to answer as we are taking two characters and finding the maximum difference in its frequency.
// It is extension of Kadane's algorithm because we reset the frequency sum to zero when it doesn't satisfies our condition.

class Solution {
public:
    int largestVariance(string s) {
        int result=0, n=s.length();
        vector<int>check(26, 0);
        for(int i=0; i<n; i++)
        {
            check[s[i]-'a']=1;
        }
        for(char first='a'; first<='z'; first++)
        {
            for(char second='a'; second<='z'; second++)
            {
                if(check[first-'a']==0 || check[second-'a']==0)
                    continue;
                bool seen=false;
                int firstCount=0, secondCount=0;
                for(auto x:s)
                {
                    if(first==x)
                        firstCount++;
                    if(second==x)
                        secondCount++;
                    if(secondCount>0)
                    {
                        //cout<<first<<" "<<second<<endl;
                        result=max(result, firstCount-secondCount);
                    }
                    else
                    {
                        if(seen)
                        {
                            result=max(result, firstCount-1);
                        }
                    }
                    if(secondCount>firstCount)
                    {
                        firstCount=0;
                        secondCount=0;
                        seen=true;
                    }
                }
            }
        }
        return result;
    }
};

// Solution using brute force. Here we find all the string and store in map and then we traverse all the string. 
//While traversing string we count the frequency of all characters and store in map of frequency. In frequency map we subtract the highest frequency to lowest frequency.
// T.C- O(all substring *(length of substring + 26(for frequency of characters)))
// TLE

class Solution {
public:
    int largestVariance(string s) {
        unordered_map<string, int>mp;
        int n=s.length(), ans=0;
        for(int i=0; i<n; i++)
        {
            string tmp;
            tmp+=s[i];
            mp[tmp]++;
            for(int j=i+1; j<n; j++)
            {
                tmp+=s[j];
                mp[tmp]++;
            }
        }
        for(auto x:mp)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        for(auto x:mp)
        {
            unordered_map<char,int>f;
            int i=0;
            string tmp=x.first;
            int m=tmp.length(), mx=INT_MIN, mn=INT_MAX;
            while(i<m)
            {
                f[tmp[i]]++;
                i++;
            }
            if(f.size()==1)
                continue;
            for(auto y:f)
            {
                mx=max(mx, y.second);
                mn=min(mn, y.second);
            }
            ans=max(ans, mx-mn);
        }
        return ans;
    }
};
