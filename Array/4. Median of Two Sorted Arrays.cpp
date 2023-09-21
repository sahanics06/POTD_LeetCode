/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
  */

//*************************************************************************************************

// Solution
// Brute force, store in new vector and then sort it. Then find the median

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>tmp;
        for(int i=0; i<n; i++)
        {
            tmp.push_back(nums1[i]);
        }
        for(int i=0; i<m; i++)
        {
            tmp.push_back(nums2[i]);
        }
        sort(tmp.begin(), tmp.end());
        if((n+m)%2)
            return tmp[(n+m)/2];
        else
            return double(tmp[(n+m)/2]+tmp[(n+m)/2-1])/2;

    }
};

// Solution, Here we insert the smallest from both array directly in new vector.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>tmp(n+m);
        int i=0, j=0, k=0;
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                tmp[k]=nums1[i];
                i++;
            }
            else
            {
                tmp[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<n)
        {
            tmp[k]=nums1[i];
            i++;
            k++;
        }
        while(j<m)
        {
            tmp[k]=nums2[j];
            j++;
            k++;
        }
        if((n+m)%2)
            return tmp[(n+m)/2];
        else
            return double(tmp[(n+m)/2]+tmp[(n+m)/2-1])/2;
    }
};

// Solution, Here instead of creating we just keep the value in e1 and e2 for the median index.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int idx1=(n+m-1)/2;
        int idx2=(n+m)/2;
        int i=0, j=0, k=0;
        int e1=0, e2=0;
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                if(k==idx1)
                {
                    e1=nums1[i];
                }
                if(k==idx2)
                {
                    e2=nums1[i];
                }
                i++;
            }
            else
            {
                if(k==idx1)
                {
                    e1=nums2[j];
                }
                if(k==idx2)
                {
                    e2=nums2[j];
                }
                j++;
            }
            k++;
        }
        while(i<n)
        {
            if(k==idx1)
            {
                e1=nums1[i];
            }
            if(k==idx2)
            {
                e2=nums1[i];
            }
            i++;
            k++;
        }
        while(j<m)
        {
            if(k==idx1)
            {
                e1=nums2[j];
            }
            if(k==idx2)
            {
                e2=nums2[j];
            }
            j++;
            k++;
        }
        if((n+m)%2)
            return e1;
        else
            return double(e1+e2)/2;
    }
};

// Solution using Binary Search

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m=nums1.size(); // Smaller array among both
        int n=nums2.size();
        int l=0, r=m; // l and r depicts number of elements taken from nums1
        while(l<=r)
        {
            int ele_nums1 = l+(r-l)/2; // number of elements taken from nums1
            int ele_nums2 = (n+m+1)/2 - ele_nums1; // remaining elements taken from nums2;

            int ele_left_nums1 = ele_nums1 == 0 ? INT_MIN : nums1[ele_nums1-1]; 
            int ele_left_nums2 = ele_nums2 == 0 ? INT_MIN : nums2[ele_nums2-1];
            int ele_right_nums1 = ele_nums1 == m ? INT_MAX : nums1[ele_nums1];
            int ele_right_nums2 = ele_nums2 == n ? INT_MAX : nums2[ele_nums2];

            if(ele_left_nums1<=ele_right_nums2 && ele_left_nums2<=ele_right_nums1)
            {
                if((n+m)%2) return (max(ele_left_nums1, ele_left_nums2));
                else    return (max(ele_left_nums1, ele_left_nums2)+min(ele_right_nums1,ele_right_nums2))/2.0;
            }
            if(ele_left_nums1>ele_right_nums2)
            {
                r = ele_nums1;
            }
            else
            {
                l = ele_nums1+1;
            }
        }
        return -1;
    }
};
