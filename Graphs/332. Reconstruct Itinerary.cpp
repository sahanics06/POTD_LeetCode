/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight.
Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single 
string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Example 1:

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:

Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

Constraints:

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi
*/

// Solution 

class Solution {
public:
    vector<string>result;
    bool dfs(string node, vector<string>&ans, int n, unordered_map<string, vector<string>>&adj)
    {
        ans.push_back(node);
        if(ans.size()==n+1)
        {
            result=ans;
            return true;
        }
        vector<string>&edges = adj[node];
        for(int i=0; i<edges.size(); i++)
        {
            string toAirport=edges[i];
            //remove this edges to remove cycle. Exam  A->B  B->A this will keep looping
            edges.erase(edges.begin()+i);

            if(dfs(toAirport, ans, n, adj)==true)
            {
                return true;
            }
            edges.insert(edges.begin()+i, toAirport); // insert the removed edge
        }
        ans.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>>adj;
        vector<string>ans;
        int n=tickets.size();
        for(auto t:tickets)
        {
            string source=t[0];
            string des=t[1];
            adj[source].push_back(des);
        }
        for(auto &it:adj) // here use "&" before it otherwise the sorting will not get reflected
        {
            sort(begin(it.second), end(it.second));
        }
        dfs("JFK", ans, n, adj);
        return result;
    }
};
