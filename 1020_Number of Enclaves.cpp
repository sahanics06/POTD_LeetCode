/*
1020. Number of Enclaves
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
Solution---Leeetcode----------------------------
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n));
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0 || vis[i][j])
                    continue;
                int c=0;
                bool yes=true;
                queue<pair<int,int>>q({{i,j}});
                vis[i][j]=true;
                while(!q.empty())
                {
                    auto ft=q.front();
                    q.pop();
                    c++;
                    for(int k=0; k<4; k++)
                    {
                        int y=ft.first+dy[k];
                        int x=ft.second+dx[k];
                        if(x>=n||x<0||y>=m||y<0)
                        {
                            yes=false;
                            continue;
                        }
                        if(vis[y][x]) continue;
                        if(grid[y][x]==0)   continue;
                        vis[y][x]=true;
                        q.push({y,x});
                    }
                    

                }
                if(yes)
                    ans+=c;
            }
        }
        return ans;
    }
};
