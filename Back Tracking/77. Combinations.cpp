/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order. 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination. 

Constraints:

1 <= n <= 20
1 <= k <= n
  */

// Solution using loop and recursion

class Solution {
public:
    vector<vector<int>>ans;
    int m;
    void solve(int start, int k, vector<int>&tmp)
    {
        if(k==0)
        {
            ans.push_back(tmp);
            return;
        }
        if(start>m)
        {
            return;
        }
        for(int i=start; i<=m; i++)
        {
            tmp.push_back(i);
            solve(i+1, k-1, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>tmp;
        m=n;
        solve(1,k,tmp);
        return ans;
    }
};

// Solution using recursion

class Solution {
public:
    vector<vector<int>>ans;
    int m;
    void solve(int i, int k, vector<int>&tmp)
    {
        if(k==0)
        {
            ans.push_back(tmp);
            return;
        }
        if(i>m)
        {
            return;
        }
        tmp.push_back(i);
        solve(i+1, k-1, tmp);
        tmp.pop_back();
        solve(i+1, k, tmp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>tmp;
        m=n;
        solve(1,k,tmp);
        return ans;
    }
};
