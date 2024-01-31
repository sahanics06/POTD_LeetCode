/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is 
the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this 
is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 
Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

  */

// Solution using stack; monotonic stack concept

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        int n=tmp.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>st; // To store the numbers in decreasing order
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && st.top().first<=tmp[i])
            {
                st.pop(); // if numbers are smaller then pop
            }
            if(st.size() && st.top().first>tmp[i])
            {
                ans[i]= st.top().second-i;
            }
            st.push({tmp[i], i}); // push the element and its index
        }
        return ans;
    }
};


// Solution using two loop

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        vector<int>ans;
        int n=tmp.size();
        for(int i=0; i<n; i++)
        {
            int f=0;
            for(int j=i+1; j<n; j++)
            {
                if(tmp[j]>tmp[i])
                {
                    ans.push_back(j-i);
                    f=1;
                    break;
                }
            }
            if(!f)
            {
                ans.push_back(0);
            }
        }
        return ans;
    }
};
