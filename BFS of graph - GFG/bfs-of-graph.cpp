//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bsf(vector<int> adj[], int source, vector<int> &ans, unordered_set<int> &visited){
        queue<int> q;
        q.push(source);
        visited.insert(source);
        
        while(!q.empty()){
            for(int i = 0; i < adj[source].size() ; i++){
                if(visited.count(adj[source][i]) == false){
                    q.push(adj[source][i]);
                    visited.insert(adj[source][i]);
                }
            }
            ans.push_back(source);
            q.pop();
            source = q.front();
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_set<int> visited;
        vector<int> ans;
        // for(int i = 0; i < V ; i++){
        //     if(visited.count(i) == false){
        //         bsf(adj, i, ans, visited);
        //     }
        // }
        bsf(adj, 0, ans, visited);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends