/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed
island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
  
  Solution ----------------------Leetcode
  */
  
  class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(), n=grid[0].size();
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, 1, -1};
        vector<vector<int>>vis(m, vector<int>(n));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1|| vis[i][j])
                    continue;
                queue<pair<int,int>>q({{i,j}});
                vis[i][j]=true;
                bool yes=true;
                while(!q.empty())
                {
                    auto ft=q.front();
                    q.pop();
                    for(int k=0; k<4; k++)
                    {
                        int x=ft.first+dx[k];
                        int y=ft.second+dy[k];
                        if(x<0 || x>=m || y<0 || y>=n)
                        {
                            yes=false;
                            continue;
                        }
                        if(grid[x][y]==1)   continue;
                        if(vis[x][y])   continue;
                        vis[x][y]=true;
                        q.push({x,y});
                    }

                }
                if(yes)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
