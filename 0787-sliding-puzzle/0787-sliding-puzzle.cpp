
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<vector<vector<int>>,int>>q;
        set<vector<vector<int>>>s;
        vector<vector<int>>vec = {{1,2,3},{4,5,0}};
        vector<int>dx = {-1,0,0,1};
        vector<int>dy = {0,1,-1,0};
        q.push({vec,0});
        s.insert(vec);
        while(!q.empty()){
            pair<vector<vector<int>>,int> curr = q.front();
            vector<vector<int>> v = curr.first;
            int ops = curr.second;
            if(v==board)
                return ops;
            q.pop();
            int x = -1;
            int y = -1;
            for(int i = 0;i < 2;i++){
                for(int j = 0;j < 3;j++){
                    if(v[i][j]==0){
                        x = i;y = j;
                    }
                }
            }
            for(int i = 0;i < 4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<2 && ny>=0 && ny<3){
                    vector<vector<int>>nvec(2,vector<int>(3));
                    int num = v[nx][ny];
                    for(int j = 0;j < 2;j++){
                        for(int k = 0;k < 3;k++){
                            if(j==x && k==y){
                                nvec[j][k] = num;
                            }
                            else if(j==nx && k==ny){
                                nvec[j][k] = 0;
                            }
                            else{
                                nvec[j][k] = v[j][k];
                            }
                        }
                    }
                    if(s.find(nvec)==s.end()){
                        q.push({nvec,ops+1});
                        s.insert(nvec);
                    }
                }
            }
        }
        return -1;
    }
};