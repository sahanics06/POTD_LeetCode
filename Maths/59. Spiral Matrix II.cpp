/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:
Input: n = 1
Output: [[1]]
Constraints:
1 <= n <= 20
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n));
        int left=0, right=n-1, bottom=n-1, top=0, c=1;
        while(left<=right && top<=bottom)
        {
            for(int i=left; i<=right; i++)
            {
                ans[top][i]=c;
                c++;
            }
            top++;
            for(int i=top; i<=bottom; i++)
            {
                ans[i][right]=c;
                c++;
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right; i>=left; i--)
                {
                    ans[bottom][i]=c;
                    c++;
                }  
                bottom--;              
            }            
            if(left<=right)
            {
                for(int i=bottom; i>=top; i--)
                {
                    ans[i][left]=c;
                    c++;
                }
                left++;
            }
        }
        return ans;
    }
};
