#define pll pair<int,pair<int,int>>
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pll,vector<pll>,greater<pll>>pq;
        pq.push({0,{0,0}});
        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};
        vector<vector<int>>minCost(n,vector<int>(m,(int)(1e9)));
        minCost[0][0] = 0;
        while(!pq.empty()){
            pll p = pq.top();
            pq.pop();
            int cost = p.first;
            int row = p.second.first;
            int col = p.second.second;
            cout<<row<<" "<<col<<endl;
            if(row==n-1 && col==m-1){
                return cost;
            }
            int idx = grid[row][col]-1;
            for(int i = 0;i < 4;i++){
                int nx = row+dx[i];
                int ny = col+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(i==idx && minCost[nx][ny]>cost){
                        minCost[nx][ny] = cost;
                        pq.push({cost,{nx,ny}});
                    }
                    else if(minCost[nx][ny]>cost+1){
                        minCost[nx][ny] = cost+1;
                        pq.push({cost+1,{nx,ny}});
                    }
                }
            }
        }
        return minCost[n-1][m-1];
    }
};