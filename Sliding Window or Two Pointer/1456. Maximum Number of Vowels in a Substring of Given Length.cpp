/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0, j=0, ans=0, result=INT_MIN;
        map<char,int>mp;
        mp['a']=0;mp['e']=0;mp['i']=0; mp['o']=0; mp['u']=0;
        while(i<s.length())
        {
            if(i-j+1<=k)
            {
                if(mp.find(s[i])!=mp.end())
                {
                    ans++;
                }
            }
            else
            {
                if(mp.find(s[j])!=mp.end())
                {
                    ans--;
                }
                if(mp.find(s[i])!=mp.end())
                {
                    ans++;
                }
                j++;
            }
            result=max(ans,result);
            i++;
        }
        return result;
    }
};
