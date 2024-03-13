//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[], vector<int> &pathVis, vector<int> &vis ){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,pathVis,vis)) return true;
            }
            else if (pathVis[it]) return true;
        }
        pathVis[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // vector<int> vis(V,0);
        // vector<int> pathVis(V,0);
        
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         if(dfs(i,adj,pathVis,vis)) return true;
        //     }
        // }
        // return false;
        
        int inDegree[V]={0};
	   
	   for(int i=0;i<V;i++){
	       for(auto it:adj[i]){
	           inDegree[it]++;
	       }
	   }
	   
	   queue<int>q;
	   
	   for(int i=0;i<V;i++){
	       if(inDegree[i]==0) q.push(i);
	   }
	   
	   int cnt=0;
	   while(!q.empty()){
	       int node = q.front();
	       //ans.push_back(node);
	       q.pop();
	       cnt++;
	       for(auto it:adj[node]){
	           inDegree[it]--;
	           if(inDegree[it]==0) q.push(it);
	       }
	   }
	   if(cnt<V) return true;
	   return false;
    }
};

//{ Driver Code Starts.

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