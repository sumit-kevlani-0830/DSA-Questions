class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj, int start, int n) {
        vector<int> dist(n, -1); 
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) { 
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return dist;
    }

    pair<int, int> findDiameterEndpoints(vector<vector<int>>& adj, int n) {
        vector<int> dist1 = bfs(adj, 0, n);
        for(int i = 0;i < dist1.size();i++){
            cout<<dist1[i]<<" ";
        }
        cout<<endl;
        int farthestNode = max_element(dist1.begin(), dist1.end()) - dist1.begin();
        vector<int> dist2 = bfs(adj, farthestNode, n);
        int diameterEndpoint = max_element(dist2.begin(), dist2.end()) - dist2.begin();

        return {farthestNode, diameterEndpoint};
    }

    vector<int> findMaxDistances(vector<vector<int>>& adj, int n) {
        auto [endpoint1, endpoint2] = findDiameterEndpoints(adj, n);
        vector<int> dist1 = bfs(adj, endpoint1, n);
        vector<int> dist2 = bfs(adj, endpoint2, n);
        vector<int> maxDist(n);
        for (int i = 0; i < n; ++i) {
            maxDist[i] = max(dist1[i], dist2[i]);
        }
        return maxDist;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>>adj1(n+1);
        vector<vector<int>>adj2(m+1);
        for(int i = 0;i < n;i++){
            int u = edges1[i][0];
            int v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(int i = 0;i < m;i++){
            int u = edges2[i][0];
            int v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int>dist1 = findMaxDistances(adj1,n+1);
        vector<int>dist2 = findMaxDistances(adj2,m+1);
        int maxi1 = *max_element(dist1.begin(),dist1.end());
        int maxi2 = *max_element(dist2.begin(),dist2.end());
        int mini1 = *min_element(dist1.begin(),dist1.end());
        int mini2 = *min_element(dist2.begin(),dist2.end());
        return max(mini1+mini2+1,max(maxi1,maxi2));
        // return 0;
    }
};