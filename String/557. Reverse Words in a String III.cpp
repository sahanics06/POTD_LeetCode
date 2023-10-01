/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 
Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.

*/

// Solution using stringstream

class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);
        string word;
        string ans="";
        while(st>>word)
        {
            int i=word.length()-1;
            while(i>=0)
            {
                ans.push_back(word[i]);
                i--;
            }
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
