/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
You may change 0's to 1's to connect the two islands to form one island.
Return the smallest number of 0's you must flip to connect the two islands.
Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
Constraints:
n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.
*/

// Solution- We have marked same component as 1 and 2 in vis array using DFS. Then in queue we have pushed all the indexes in component 1.
//           Then we use BFS to find index with value 2 and find the minimum distance.
class Solution {
public:
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int i, int j, int c, int n, int m, int dx[], int dy [])
    {
        vis[i][j]=c;
        for(int k=0; k<4; k++)
        {
            int x=dx[k]+j;
            int y=dy[k]+i;
            if(x>=0&&y>=0&&x<m&&y<n&&grid[y][x]==1&&vis[y][x]==-1)
            {
                vis[y][x]=c;
                dfs(grid, vis, y, x, c, n, m, dx, dy);
            }
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), c=1;
        int dx[]={0, 1, 0, -1};
        int dy[]={1, 0, -1, 0};
        vector<vector<int>>vis(n, vector<int>(m, -1));
        int a, b;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==-1 && grid[i][j]==1)
                {
                    a=i, b=j;
                    dfs(grid, vis, i, j, c, n, m, dx, dy);
                    c++;
                }
            }
        }
        queue<pair<pair<int,int>, int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==1)
                {
                    q.push({{i,j}, 0});
                }
            }
        }
        int ans=INT_MAX;
        int ty=q.front().first.first;
        int tx=q.front().first.second;
        vis[ty][tx]=0;
        while(!q.empty())
        {
            pair<pair<int,int>,int>t=q.front();
            int ty=t.first.first;
            int tx=t.first.second;
            int d=t.second;
            q.pop();
            for(int k=0; k<4; k++)
            {
                int x=dx[k]+tx;
                int y=dy[k]+ty;
                if(x>=0&&y>=0&&x<m&&y<n&&vis[y][x]!=0&&vis[y][x]==-1)
                {
                    vis[y][x]=0;
                    q.push({{y, x}, d+1});
                }
                else if(x>=0&&y>=0&&x<m&&y<n&&vis[y][x]==2)
                {
                    ans=min(ans, d);
                    break;
                }
            }
        }

        return ans;
    }
};
