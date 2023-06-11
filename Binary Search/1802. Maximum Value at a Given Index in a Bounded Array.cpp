/*
You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.
Note that abs(x) equals x if x >= 0, and -x otherwise.
Example 1:
Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
Example 2:
Input: n = 6, index = 1,  maxSum = 10
Output: 3
Constraints:
1 <= n <= maxSum <= 109
0 <= index < n
*/

// Solution using Binary Search. Here we are finding the Maximum value from 1 to maxSum at index for which it satisfies all condition.

class Solution {
public:
    typedef long long ll;
    ll formula(ll count, ll x)
    {
        return (count*x)-(count*(count+1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        long long left=1, right=maxSum, mid;
        int result=0;
         while(left<=right)
        {
            mid=left+(right-left)/2;
            ll left_count=min((ll)index, mid-1);//number of element left of mid such that all number are natural number and donot go beyond 0 since 
                                                //we are taking mid-1,mid-2,mid-3,...upto 1 and if it crosses 1 then we have to consider only 1.
            ll left_sum=formula(left_count, mid);

            left_sum+=max((ll)0, index-(mid-1));// to take the only 1's value, here we have taken max because if mid id greater than index then it will give negative value.

            ll right_count=min((ll)n-index-1, mid-1);// here count of elements in right is n-index-1

            ll right_sum=formula(right_count, mid);

            right_sum+=max((ll)0, n-index-1-(mid-1));// extra 1's

            ll total_sum=left_sum+mid+right_sum;

            if(total_sum<=maxSum)
            {
                result=max((ll)result, mid);
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return result;
    }
};
