class Solution {
public:
    long long dfs(int n, vector<vector<int>>&adj, vector<int>&values, int node, int parent, int k, int &ans){
        long long sum = values[node];
        for(auto it: adj[node]){
            if(it!=parent){
                sum += dfs(n,adj,values,it,node,k,ans);
            }
        }
        if(sum%k==0){
            ans++;
            return 0;
        }
        else{
            return sum;
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }   
        int ans = 0;
        dfs(n,adj,values,0,-1,k,ans);
        return ans;
    }
};