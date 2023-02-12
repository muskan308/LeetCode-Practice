// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool DSFrec(vector<int> adj[], vector<bool> &visited, vector<bool> &recStack, int s){
        recStack[s] = true;
        visited[s] = true;
        for(int i = 0; i < adj[s].size() ; i++){
            if(visited[adj[s][i]] == false && DSFrec(adj, visited, recStack, adj[s][i])) return true;
            else if(recStack[adj[s][i]] == true) return true;
        }
        recStack[s]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        for(int i = 0; i < V ; i++){
            if(visited[i]==false){
                if(DSFrec(adj, visited, recStack, i)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends