/*
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list 
of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times
and you may reuse edges.

 

Example 1:

Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3] 

Constraints:

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.
*/

// Solution Using BFS

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int mask_n = (1<<n)-1;
        set<pair<int,int>>st;
        queue<pair<int, pair<int,int>>>q;
        for(int i=0; i<n; i++)
        {
            int mask=1<<i;
            q.push({0, {i, mask}});
            st.insert({i,mask});
        }
        while(!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            int dist = tmp.first;
            int tmp_node = tmp.second.first;
            int tmp_mask = tmp.second.second;
            for(auto x:graph[tmp_node])
            {
                int mask = tmp_mask | (1<<x);
                if(mask==mask_n)
                    return dist+1;
                else if(st.count({x, mask}))
                    continue;
                else
                    q.push({dist+1, {x, mask}});
                    st.insert({x, mask});
            }            
        }
        return 0;        
    }
};
