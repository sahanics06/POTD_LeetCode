/*
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

 

Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
 

Constraints:

1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9
*/

// Solution using recursion TLE

class Solution {
public:
    int solve(int idx, vector<int>& arr1, vector<int>& arr2, int prev)
    {
        if(idx==arr1.size())
            return 0;
        int result1= 1e9+1;
        if(arr1[idx]>prev)
        {
            result1=solve(idx+1, arr1, arr2, arr1[idx]);
        }
        int result2=1e9+1;
        auto it=upper_bound(begin(arr2), end(arr2), prev);
        if(it!=end(arr2))
        {
            int j=it-begin(arr2);
            //arr1[idx]=arr2[j]; we should not change the array because we are taking array as reference and this will reflect in other recursion call of upper recursion.
            prev=arr2[j];
            result2=1+solve(idx+1, arr1, arr2, prev);
        }
        return min(result1, result2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int result=solve(0, arr1, arr2, INT_MIN);
        if(result==1e9+1)
        {
            return -1;
        }
        return result;
        
    }
};

// Solution using DP, recursion and memoization

class Solution {
public:
    map<pair<int,int>, int>mp;
    int solve(int idx, vector<int>& arr1, vector<int>& arr2, int prev)
    {
        if(idx==arr1.size())
            return 0;
        int result1= 1e9+1;
        if(mp.find({idx, prev})!=mp.end())
            return mp[{idx, prev}];
        if(arr1[idx]>prev)
        {
            result1=solve(idx+1, arr1, arr2, arr1[idx]);
        }
        int result2=1e9+1;
        auto it=upper_bound(begin(arr2), end(arr2), prev);
        if(it!=end(arr2))
        {
            int j=it-begin(arr2);
            //arr1[idx]=arr2[j]; we should not change the array because we are taking array as reference and this will reflect in other recursion call of upper recursion.
            //prev=arr2[j];
            result2=1+solve(idx+1, arr1, arr2, arr2[j]);
        }
        return mp[{idx, prev}]=min(result1, result2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        mp.clear();
        sort(arr2.begin(), arr2.end());
        int result=solve(0, arr1, arr2, INT_MIN);
        if(result==1e9+1)
        {
            return -1;
        }
        return result;
        
    }
};
