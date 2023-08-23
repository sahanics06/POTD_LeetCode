/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
  */

// SOlution using putting character in alternate position.

class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length(), mxCount=0;
        char mx;
        vector<int>count(26,0);

        // mxCount to count frequency of max character
        // mx is highest frequency character
        for(char &ch : s)
        {
            count[ch-'a']++;
            if(count[ch-'a']>mxCount)
            {
                mxCount=count[ch-'a'];
                mx=ch;
            }
            if(count[ch-'a']>(n+1)/2)
                return "";
        }

        string result=s;
        int i=0;

        // Put mx in alternate position
        while(count[mx-'a']>0)
        {
            result[i]=mx;
            count[mx-'a']--;
            i+=2;
        }

        for(int ch='a'; ch<='z'; ch++)
        {
            while(count[ch-'a']>0)
            {   // if i goes beyond n then put i=1 to start putting remaining character
                if(i>=n)
                {
                    i=1;
                }
                result[i]=ch;
                count[ch-'a']--;
                i+=2;
            }
        }
        return result;
    }
};

// Solution using Priority Queue

class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        vector<int>count(26,0);
        for(char &ch : s)
        {
            count[ch-'a']++;
            if(count[ch-'a']>(n+1)/2)
                return "";
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>>pq;

        for(char ch='a'; ch<='z'; ch++)
        {
            if(count[ch-'a']>0)
            {
                pq.push({count[ch-'a'], ch});
            }
        }
        string result="";

        while(pq.size()>=2)
        {
            auto p1=pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();

            result.push_back(p1.second);
            p1.first--;
            result.push_back(p2.second);
            p2.first--;
            if(p1.first>0)
            {
                pq.push(p1);
            }
            if(p2.first>0)
            {
                pq.push(p2);
            }
        }
        if(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
