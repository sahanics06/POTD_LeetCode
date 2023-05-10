/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int bottom=matrix.size()-1, right=matrix[0].size()-1;
        int left=0, top=0;
        vector<int>v;
        while(left<=right && top <=bottom)
        {
            for(int i=left; i<=right; i++)
            {
                v.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<=bottom; i++)
            {
                v.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right; i>=left; i--)
                {
                    v.push_back(matrix[bottom][i]);
                }    
                bottom--;            
            }
            
            if(left<=right)
            {
                for(int i=bottom; i>=top; i--)
                {
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }
        return v;
    }
};
