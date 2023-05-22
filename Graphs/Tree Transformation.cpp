/*
You are given a tree containing N nodes in the form of an array P where Pi represents the parent of the i-th node and P0 = -1 as the tree is rooted at node 0. In one move, you can merge any two adjacent nodes. Calculate the minimum number of moves required to turn the tree into a star tree.

-> Merging adjacent nodes means deleting the edge between them and considering both the nodes as a single one.
-> A Star tree is a tree with a center node, and all other nodes are connected to the center node only.

Example 1:

Input:
N = 5
p[] = {-1, 0, 0, 1, 1}
Output:
1
Explanation: 
Tree looks like:
            
Merge the edge 0 - 2 in one operation

Our Tree will look like:
            
Example 2:

Input: N = 8
p[] = {-1 0 0 0 0 2 2 5}
Output:
2
Explanation:
Tree looks like:
Merge node 5 to 2, tree will look like
and then 2 to 0, finally the tree will be:
thus tree formed will be a star tree.
 
Your Task:
You don't need to read, input, or print anything. Your task is to complete the function solve( ), which takes integer N, and an array p[ ] as input parameters and returns the minimum number of moves required to turn the tree into a star tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ p[i] < N
p[0] = -1, 0 is the root node.
*/

// Solution - Size of the map with say number of parents from which we can know that map.size() is height. If node 0 has more than 1 node then we have to take node 1 
//            as center so subtract count of node 0 also.
class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        unordered_map<int, int>m;
        for(int i=1; i<N; i++)
        {
            m[p[i]]++;
        }
        if(m.size()==1)
            return 0;
        return m[0]==1?m.size()-2:m.size()-1;
    }
};

// Solution find leaf node or leaf having only one edge. The subtract N-1-Leaf_Node or Node with one edge. If one parent then return 0.
class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        vector<int>vis(N,0);
        int ans=0;
        for(int i=1; i<N; i++)
        {
            vis[p[i]]++;
            vis[i]++;
        }
        for(auto x:vis)
        {
            if(x==1)
                ans++;
        }
        return N==ans?0:N-1-ans;
    }
};
