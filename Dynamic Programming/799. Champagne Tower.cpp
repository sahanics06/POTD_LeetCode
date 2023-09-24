/*
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  
Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall 
equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally 
to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two 
glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full 
glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses 
are a quarter full, as pictured below.

Now after pouring some non-negative integer cups of champagne, return how full the jth glass in the ith row is 
(both i and j are 0-indexed.) 

Example 1:

Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess 
liquid so all the glasses under the top glass will remain empty.
Example 2:

Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess 
liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup 
of champange.
Example 3:

Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000 

Constraints:

0 <= poured <= 109
0 <= query_glass <= query_row < 100
*/

// Solution

class Solution {
public:
    double dp[101][101];
    double solve(int poured, int i, int j)
    {
        if(i<0 || j<0 || i<j) // here we have taken i<j because for a particular row for the extreme point will have only 
            return 0.0;       // left_up(i.e i-1, j-1) and will not have (i-1, j)
                              // example- for 2nd row the upper row has two glasses with coordinates as- (1,0) , (1,1) and 
                              // it does not have (1,2)
            
        if(i==0 && j==0) // Reached the top glass
            return poured;
        if(dp[i][j]!=-1)
            return dp[i][j];
        double left_up = (solve(poured, i-1, j-1)-1)/2.0; // here we have done the calculation, since this glass will get half of 
                                                          // whats remaining in above glass i.e. the above glass will take 1 and then 
                                                          // the liquid will get divided into two i.e. left side and right side.
        double right_up = (solve(poured, i-1, j)-1)/2.0;

        if(left_up<0) // we added this line because when (i<j) we are still returning 0. So for this case we will get for solve() 
                      // value as 0. So (0-1)/2.0 will give -0.5000 which is not valid
            left_up = 0.0;
        if(right_up<0)
            right_up = 0.0;
        return dp[i][j] = left_up + right_up;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0; i<101; i++)
        {
            for(int j=0; j<101; j++)
            {
                dp[i][j]=-1;
            }
        }
        // Here we have used min() because if the query point is the last extreme point then the extra liquid should fall on the 
        // floor but it is still in our answer because we are starting recursion call from our query and not going down of it so 
        // the total remaing liquid is present in the answer but the glass can hold only 1.
        return min(1.0, solve(poured, query_row, query_glass));
    }
};
