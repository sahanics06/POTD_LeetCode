/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k 
and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false. 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109

*/

//*****************************************************************************************************

// Solution using Stack. O(N)

class Solution {
public:
/* Test Cases:
    [1,2,3,4] - false
    [3,1,4,2] - true
    [-1,3,2,0] - true
    [1,0,1,-4,-3] - false
*/
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int>st; // monotonic stack i.e. either increasing or decreasing
        int num3=INT_MIN;
        // we are taking numbers like num1<num2<num3
        // we are pushing into stack and when we see that we have nums[i] value greater than st.top(), then
        // we keep the largest from the stack in num3 and than later we push nums[i] in stack which is the largest among all 
        // which is considered as num2
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i]<num3)
                return true; 
            // We need stack because when we se nums[i] greater than st.top() we got candidate for num2 and keep updating num3 
            // and largest is nums[i] i.e num2 which is then pushed in stack for fututre candidate of num3 if we get larger value 
            // nums[i] to keep as num2 and st.top() to num3
            while(!st.empty() && st.top()<nums[i]) // If we see nums[i] is greater than st.top(). It means
            // we have num2=nums[i] and so we keep assigning the largest within the stack to num3
            {
                num3=st.top(); // store the second largest candidate in num3
                st.pop();
            }
            // if elements smaller than st.top() then push it. 
            st.push(nums[i]); // This has to be the largest

            // ordering is maintain because num3 is having index greater than num2 because the values are push from back which 
            // means index of num3 is greater.
        }
        return false;
    }
};

//**************************************************************************************************

// Solution using O(N^2). TLE

lass Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int nums_i = nums[0];
        for(int j=1; j<n-1; j++)
        {
            // here we are tracking the minimum value in nums_i
            nums_i=min(nums_i,nums[j]); // here if the minimum itself is nums[j] then it will not satisfy the condition below
            for(int k=j+1; k<n; k++)
            {
                if(nums_i<nums[k] && nums[k]<nums[j])
                    return true;
            }
        }
        return false;
    }
};

//**********************************************************************************************************

// Solution using O(N^3). TLE

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    if(nums[i]<nums[k] && nums[k]<nums[j])
                        return true;
                }
            }
        }
        return false;
    }
};
