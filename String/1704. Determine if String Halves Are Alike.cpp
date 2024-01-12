/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half 
3and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). 
Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false. 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice. 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.

  */

// Solution

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_map<char,int>mp;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        mp['A']=1;
        mp['E']=1;
        mp['I']=1;
        mp['O']=1;
        mp['U']=1;
        int n=s.length();
        int i=0, j=n/2; 
        int c1=0, c2=0;
        while(i<n/2)
        {
            if(mp.find(s[i])!=mp.end())
            {
                c1++;
            }
            if(mp.find(s[j])!=mp.end())
            {
                c2++;
            }
            i++;
            j++;
        }
        return c1==c2;
    }
};
