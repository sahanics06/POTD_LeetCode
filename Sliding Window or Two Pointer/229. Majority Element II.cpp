/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?

*/

//**********************************************************************************************************

// Solution
/*
  There can be atmost two numbers whose frequency can be greater than N/3. So we keep two variable as n1 and n2 which 
  are assumed to be those two numbers. We decrease its count everytime we see different numbers. If any of those becomes 0 
  then keep the new number in that variable. At end loop again to find the count of these two numbers in the array. 
  If its count are greater than N/3 than thats the answer
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int i=1, n=nums.size();
        int n1=nums[0], n2, c1=1, c2=0;
        while(i<n)
        {
            if(nums[i]!=n1)
            {
                n2=nums[i];
                c2=1;
                i++;
                break;
            }
            c1++;
            i++;
        }
        while(i<n)
        {
            if(n1==nums[i])
            {
                c1++;
            }
            else if(n2==nums[i])
            {
                c2++;
            }
            else if(c1==0)
            {
                n1=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                n2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
            i++;
        }
        i=0; c1=0; c2=0;
        while(i<n)
        {
            if(nums[i]==n1)
            {
                c1++;
            }
            else if(nums[i]==n2)
            {
                c2++;
            }
            i++;
        }
        if(c1>n/3 && c2>n/3)
        {
            return {n1,n2};
        }
        else if(c1>n/3)
        {
            return {n1};
        }
        else if(c2>n/3)
        {
            return {n2};
        }
        return {};
    }
};
