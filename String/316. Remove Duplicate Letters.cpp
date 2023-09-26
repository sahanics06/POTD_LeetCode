/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb" 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

*/

//********************************************************************************************

// Solution

/* Here we make two vector one to mark character taken and one to keep the last index of every character. For current index we check 
whether the last character taken in ans is greater than or is less than the current character. If cur character is less then the last 
character of ans then we check whether the last index of this character is greater than the current index. If the character appears 
later also then we mark it as not taken and pop the character from ans. We do this until this condition satisfies. Then add character 
to answer and mark as taken
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last_index(26,0), taken(26,0);
        int n=s.length(), j=0;
        string ans = "";
        ans+=s[0];
        taken[s[0]-'a']=1; // mark this as taken
        for(int i=0; i<n ; i++)
        {
            last_index[s[i]-'a'] = i;
        }
        for(int i=1 ; i<n ; i++)
        {
            if(s[i]<ans[j] && taken[s[i]-'a']==0)
            {
                while(j>=0 && ans[j]>s[i] && last_index[ans[j]-'a']>i)
                {
                    taken[ans[j]-'a']=0;
                    ans.pop_back();
                    j--;
                }
                j++;
                ans+=s[i];
                taken[s[i]-'a']=1; // mark this as taken
            }
            else
            {
                if(taken[s[i]-'a']==0)
                {
                    taken[s[i]-'a']=1; // mark this as taken
                    ans+=s[i];
                    j++;
                }
            }
        }
        return ans;
    }
};
