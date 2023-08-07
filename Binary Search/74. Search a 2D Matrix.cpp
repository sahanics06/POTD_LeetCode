/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

// Solution using Binary Search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int u=0, d=matrix.size()-1;
        int n=matrix[0].size();
        while(u<=d)
        {
            int mid=u+(d-u)/2;
            if(matrix[mid][n-1]>=target && matrix[mid][0]<=target)
            {
                int l=0, r=matrix[mid].size()-1,m;
                while(l<=r)
                {
                    m=l+(r-l)/2;
                    if(matrix[mid][m]==target)
                    {
                        return true;
                    }
                    else if(matrix[mid][m]>target)
                    {
                        r=m-1;
                    }
                    else
                    {
                        l=m+1;
                    }
                }
                return false;
            }
            else if(matrix[mid][n-1]<target)
            {
                u=mid+1;
            }
            else
            {
                d=mid-1;
            }
        }
        return false;
    }
};
