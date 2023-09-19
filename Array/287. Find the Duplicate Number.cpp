/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 
Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 
Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

*/
//*********************************************************************************************************************
/*
Solution
      Slow fast concept, if we modify the array then we can aslo do by, moving to current index's value and then making it negative. 
  If we find the value already as negative that means it is duplicate.
      When we see duplicate and we can traverse using index then we can use Hare and tortoise method(slow and fast) technique 
  which we used to do in cyclic linked list to find the point of start of cycle. Here we can see that size of array is n+1 and 
  values are from 1 to n which implies that there has to be a duplicate value. In slow first tarversal in array, slow goes to 
  position to which the cur value is and fast moves to value of current then again from that to value of next current. 
  When slow and fast meets then there is cycle, So now move slow to start index and now move slow and fast by one 
  move until slow!=fast. return slow  
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
