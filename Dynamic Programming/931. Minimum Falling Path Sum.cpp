/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below 
or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col),
or (row + 1, col + 1).

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown. 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

  */

// Solution using iteration. O(N*N)
// Here we take smallest value possible from upper row from three direction for every node.

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>tmp(n, vector<int>(n,0));
        for(int i=0; i<n; i++)
        {
            tmp[0][i] = mat[0][i];
        }
        for(int row=1; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                int x = INT_MAX, y = INT_MAX;
                if(col-1>=0)
                {
                    x = tmp[row-1][col-1];
                }
                if(col+1<n)
                {
                    y = tmp[row-1][col+1];
                }
                tmp[row][col] = mat[row][col] + min({x,y,tmp[row-1][col]});
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            ans = min(ans, tmp[n-1][i]);
        }
        return ans;
    }
};




// Solution using recursion and memoization. TLE. 3^(N^2))

class Solution {
public:
    int n, ans=INT_MAX;
    int dpx[3] = {-1, 0, 1};
    int dpy[3] = {1, 1, 1};
    bool check(int tx, int ty)
    {  
        if(tx<0 || ty<0 || tx>=n || ty>=n)
        {
            return false;
        }
        return true;
    }
    int solve(vector<vector<int>>&mat, int row, int col, vector<vector<int>>&dp)
    {
        if(dp[row][col]!=-1)
            return dp[row][col];
        if(row==n-1)
        {
            return dp[row][col] = mat[row][col];
        }
        int mx=INT_MAX;
        for(int l=0; l<3; l++)
        {
            int tx = dpx[l]+col;
            int ty = dpy[l]+row;
            if(check(tx, ty))
            {
                mx=min(mx, solve(mat, ty, tx, dp));
            }
        }
        return dp[row][col]=mx+mat[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        int tmp=INT_MAX;
        for(int col=0; col<n; col++)
        {
            tmp = min(tmp, solve(matrix, 0, col, dp));
        }
        return tmp;
    }
};
