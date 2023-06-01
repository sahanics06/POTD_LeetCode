/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)   return -1;
        int n=grid.size();
        vector<vector<int>>vis(n, vector<int>(n, -1));
        int dx[]={0, 1, 1, 1, 0, -1, -1, -1};
        int dy[]={1, 1, 0, -1, -1, -1, 0, 1};
        queue<pair<pair<int, int>, int>>q;
        q.push({{0, 0}, 1});
        vis[0][0]=1;
        while(!q.empty())
        {
            int x=q.front().first.second;
            int y=q.front().first.first;
            int l=q.front().second;
            if(x==n-1&&y==n-1)
            {
                return l;
                break;
            }
            q.pop();
            for(int k=0; k<8; k++)
            {
                int tx=x+dx[k];
                int ty=y+dy[k];
                if(tx>=0&&ty>=0&&tx<n&&ty<n&&vis[ty][tx]==-1&&grid[ty][tx]==0)
                {
                    q.push({{ty,tx}, l+1});
                    vis[ty][tx]=1;
                }
            }
        }
        return -1;
    }
};
