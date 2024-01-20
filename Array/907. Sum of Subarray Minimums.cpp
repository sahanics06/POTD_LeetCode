/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104

  */

// Solution using Stack using Nearest Small element to left and Nearest smallest element to right

class Solution {
public:
    typedef long long ll;
    vector<int> getNSL(vector<int>&arr, int n)
    {
        vector<int> result(n);
        stack<int> st;

        for(int i=0; i<n ; i++)
        {
            if(st.empty())
            {
                result[i]= -1;
            }
            else
            {
                while(!st.empty() && arr[st.top()]>= arr[i]) // here >= because to avoid duplicate subarrays
                {
                    st.pop();
                }
                result[i] = st.empty()==true? -1: st.top();
            }
            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int>&arr, int n)
    {
        vector<int>result(n);
        stack<int>st;

        for(int i=n-1; i>=0; i--)
        {
            if(st.empty())
            {
                result[i] = n;
            }
            else
            {
                while(!st.empty() && arr[st.top()]>arr[i]) // here >= is not taken to avoid duplicate subarrays
                {
                    st.pop();
                }
                result[i]= st.empty()? n:st.top();
            }
            st.push(i);
        }
        return result ;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>NSL = getNSL(arr, n);
        vector<int>NSR = getNSR(arr, n);
        ll sum=0;
        int mod = 1e9+7;

        for(int i=0; i<n; i++)
        {
            ll ls = i-NSL[i]; // elements on left side
            ll rs = NSR[i]-i; //elements on right side

            ll totalWays = ls*rs;
            ll totalSum = arr[i]*totalWays; // sum of minimum of subarrays

            sum = (sum+totalSum)%mod;
        }
        return sum;
    }
};

// Solution Brute Force

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0, mod=1e9+7;
        for(int i=0; i<arr.size(); i++)
        {
            int mn=INT_MAX;
            for(int j=i; j<arr.size(); j++)
            {
                mn = min(mn, arr[j]);
                ans+=mn;
                ans%=mod;
            }
        }
        return ans;
    }
};
