/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1
 

Constraints:

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.
*/

class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x, int y)
    {
        int x_parent= find(x);
        int y_parent= find(y);
        if(x_parent==y_parent)
        {
            return;
        }
        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent])
        {
            parent[x_parent]=y_parent;
        }
        else
        {
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }      
    }

    bool check(string a, string b)
    {
        int c=0;
        for(int i=0; i<a.length(); i++)
        {
            if(a[i]!=b[i])
                c++;
            if(c>2)
                return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }
        int groups=n;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(check(strs[i], strs[j]) && find(i)!=find(j))
                {
                    groups--;
                    Union(i,j);
                }
            }
        }
        return groups;
    }
};
