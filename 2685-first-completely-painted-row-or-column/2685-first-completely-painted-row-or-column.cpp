class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int size = arr.size();
        unordered_set<int>row(n);
        unordered_set<int>col(m);
        unordered_map<int,pair<int,int>>mp;
        for(int i = 0;i < n;i++){
            row.insert(i);
        }
        for(int i = 0;i < m;i++){
            col.insert(i);
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                int num = mat[i][j];
                mp[num] = {i,j};
            }
        }
        int i = size-1;
        while(i>=0){
            pair<int,int>p = mp[arr[i]];
            int r = p.first;
            int c = p.second;
            if(row.find(r)!=row.end()){
                row.erase(r);
            }
            if(col.find(c)!=col.end()){
                col.erase(c);
            }
            if(row.empty() && col.empty()){
                return i;
            }
            i--;
        }
        return i;
    }
};