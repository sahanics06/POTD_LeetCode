/*
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
For chosen indices i0, i1, ..., ik - 1, your score is defined as:
The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.
A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.
Example 1:
Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation: 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.
Example 2:
Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation: 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
Constraints:
n == nums1.length == nums2.length
1 <= n <= 105
0 <= nums1[i], nums2[j] <= 105
1 <= k <= n
*/

// Solution using recursion. TLE. No use of doing memoization, will give TLE.

class Solution {
public:
    int ans=0;
    void solve(int i, int l, int n, vector<int>& nums1, vector<int>& nums2, int k, int sum, int mn)
    {
        if(i==n)
        {
            if(l==k)
                ans=max(ans, sum*mn);
            return;
        }
        if(l==k)
        {
            ans=max(ans, sum*mn);
            return;
        }
        solve(i+1, l+1, n, nums1, nums2, k, sum+nums1[i], min(mn, nums2[i]));
        solve(i+1, l, n, nums1, nums2, k, sum, mn);

    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        solve(0, 0, nums1.size(), nums1, nums2, k, 0, INT_MAX);
        return ans;
    }
};

// Solution using efficient method. We have created a vector of pair and stored (nums2, nums1) then sorted it and reversed it, Since we needed decreasing order.
// The we used min heap to keep track of minimum number.

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>>v;
        for(int i=0; i<nums1.size(); i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        long long ans=0, sum=0;
        int i=0;
        while(i<k)
        {
            sum+=v[i].second;
            pq.push(v[i].second);
            i++;
        }
        ans=sum*v[i-1].first;
        for(i; i<nums1.size(); i++)
        {
            sum=sum-pq.top();
            pq.pop();
            pq.push(v[i].second);
            sum+=v[i].second;
            ans=max(sum*v[i].first, ans);
        }
        return ans;
    }
};
