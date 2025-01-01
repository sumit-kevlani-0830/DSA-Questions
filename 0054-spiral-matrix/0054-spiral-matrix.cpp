class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int sr = 0;
        int sc = 0;
        int er = n-1;
        int ec = m-1;
        vector<int>ans;
        while(sr<=er && sc<=ec){
            if(sr<=er && sc<=ec){
                for(int i = sc;i <= ec;i++){
                    ans.push_back(matrix[sr][i]);
                }
            }
            sr++;
            if(sr<=er && sc<=ec){
                for(int i = sr;i <= er;i++){
                    ans.push_back(matrix[i][ec]);
                }
            }
            ec--;
            if(sr<=er && sc<=ec){
                for(int i = ec;i >= sc;i--){
                    ans.push_back(matrix[er][i]);
                }
            }
            er--;
            if(sr<=er && sc<=ec){
                for(int i = er;i >= sr;i--){
                    ans.push_back(matrix[i][sc]);
                }
            }
            sc++;
        }
        return ans;
    }
};