/*
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. 
If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. 
Also, any solutions that attempt to circumvent the judge will result in disqualification. 

Example 1:

Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
Example 2:

Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.

Constraints:

3 <= mountain_arr.length() <= 104
0 <= target <= 109
0 <= mountain_arr.get(index) <= 109
*/

// *******************************************************************************************

// Solution

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l=0, n=mountainArr.length();
        cout<<"Length"<<n<<endl;
        int r=n-1;
        int m=0, ans=-1, tmp;
        while(l<=r)
        {
            m=l+(r-l)/2;
// Since it is maountain array so there will be atleast one value at extreme end both starting and ending
// which will be smaller than its adjacent value
            tmp =  mountainArr.get(m); 
            int t2 = mountainArr.get(m+1);
            if(tmp>t2)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        int peak = l;
        cout<<m<<endl;
        l=0, r=peak;

       // Now we have peak value so now we check in left par of boundary and since it is mountain array so every value 
       // will be unique.
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int val = mountainArr.get(mid);
            if(val==target)
            {
                //cout<<mid<<endl;
                return mid;
            }
            if(val<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        l=m+1, r=n-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int val = mountainArr.get(mid);
            if(val==target)
            {
                //cout<<mid<<endl;
                return mid;
            }
            if(val<target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
