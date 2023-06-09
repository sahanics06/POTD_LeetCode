/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        if(n==0)    return word2;
        if(m==0)    return word1;
        int i=0, j=0, k=0;
        string s="";
        while(i<n && i<m)
        {
            s+=word1[i];
            s+=word2[i];
            i++;
        }
        if(n>m)
        {
            s=s+word1.substr(i);
        }
        else if(m>n)
        {
            s=s+word2.substr(i);
        }
        return s; // If we replace the above if else conditions then we can replace it by
                  //return s+word1.substr(i)+word2.substr(i);
    }
};
