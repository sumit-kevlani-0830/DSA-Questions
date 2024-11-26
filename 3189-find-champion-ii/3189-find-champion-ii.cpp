class Solution {
public:
    int topo_sort(vector<vector<int>>&graph,int n){
        int ans = -1;
        int size = 0;
        vector<int>indegree(n);
        for(int i = 0;i < n;i++){
            for(int u: graph[i]){
                indegree[u]++;
            }
        }
        int cnt = 0;
        queue<int>q;
        for(int i = 0;i < n;i++){
            if(indegree[i]==0){
                q.push(i);
                ans = i;
                cnt++;
            }
        }
        if(cnt>1){
            return -1;
        }
        while(!q.empty()){
            int node = q.front();size++;
            q.pop();
            for(auto it: graph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ((size==n)?ans:-1);
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        int len = edges.size();
        for(int i = 0;i < len;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
        }
        int ans = topo_sort(graph,n);
        return ans;
    }
};