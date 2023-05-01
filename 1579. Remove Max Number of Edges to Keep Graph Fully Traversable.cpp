/*
Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

Example 1:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
Example 2:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
Example 3:

Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 
Constraints:

1 <= n <= 105
1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
edges[i].length == 3
1 <= typei <= 3
1 <= ui < vi <= n
All tuples (typei, ui, vi) are distinct.
*/

// Two solution. One making class and the other normal way. Solution using Discrete Set Union. I got TLE because of using myCompare while sorting array in 
//descending order which upon replacing by Lambda expression rab fine.

class Solution {
public:
    class DSU
    {
        public:
        vector<int>parent;
        vector<int>rank;  
        int component;
        DSU(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i=0; i<n+1; i++)
            {
                parent[i]=i;
            }
            component=n;
        }
        int find(int x)
        {
            if(x==parent[x])
                return x;
            return parent[x]=find(parent[x]);
        } 
        void Union(int x, int y)
        {
            x=find(x);
            y=find(y);
            if(x==y)
                return;
            if(rank[x]>rank[y])
            {
                parent[y]=x;
            }
            else if(rank[y]>rank[x])
            {
                parent[x]=y;
            }
            else
            {
                parent[x]=y;
                rank[y]++;
            }
            component--;
        }
        bool Single()
        {
            return component==1;
        }
        
    };
    // static bool myCompare(vector<int>a, vector<int>b)
    // {
    //     return a[0]>b[0];
    // }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int e1=0;
        
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
        };
        sort(edges.begin(), edges.end(), lambda);
        DSU Alice(n);
        DSU Bob(n);
        
        for(auto edge:edges)
        {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(type==3)
            {
                bool add = false;
                
                if(Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    add = true;
                }
                
                if(Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    add = true;
                }
                
                if(add)
                    e1++;
                }
            else if(type == 2) 
                {
                if(Bob.find(u) != Bob.find(v)) 
                {
                    Bob.Union(u, v);
                    e1++;
                }
                } 
            else 
                {
                if(Alice.find(u) != Alice.find(v)) 
                {
                    Alice.Union(u, v);
                    e1++;
                }
                }
        }
        if(Alice.Single()==true && Bob.Single()==true)
        {
            return edges.size()-e1;
        }
        return -1;
    }
};

/////////////////////////////////////////////////

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    vector<int>parent1;
    vector<int>rank1;
    int find(int x, vector<int>&p)
    {
        if(x==p[x])
            return x;
        return p[x]=find(p[x], p);
    }
    bool Union(int x, int y, vector<int>&p, vector<int>&r)
    {
        x=find(x, p);
        y=find(y, p);
        if(x!=y)
        {
            if(r[x]>r[y])
            {
                p[y]=x;
            }
            else if(r[y]>r[x])
            {
                p[x]=y;
            }
            else
            {
                p[x]=y;
                r[y]++;
            }
            return true;
        }
        return false;   
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int g1=n, g2=n;
        parent.resize(n+1);
        rank.resize(n+1);
        parent1.resize(n+1);
        rank1.resize(n+1);
        int e1=0;
        sort(edges.begin(), edges.end(), [](auto const &a, auto const &b){return a[0]>b[0];});
        for(int i=0; i<n+1; i++)
        {
            parent[i]=i;
            parent1[i]=i;
        }
        for(auto x:edges)
        {
            if(x[0]==3)
            {
                bool a=Union(x[1], x[2], parent, rank);
                if(a)
                {
                    Union(x[1], x[2], parent1, rank1);
                    g2--;
                    g1--;
                }
                else
                {
                    e1++;
                }
            }
            else if(x[0]==1)
            {
                bool a=Union(x[1], x[2], parent, rank);
                if(a)
                {
                    g1--;
                }
                else
                {
                    e1++;

                }
            }
            else
            {
                bool b=Union(x[1], x[2], parent1, rank1);
                if(b)
                {
                    g2--;
                }
                else
                {
                    e1++;

                }
            }
        }
        if(g1!=1 || g2!=1)
            return -1;
        return e1;
    }
};
