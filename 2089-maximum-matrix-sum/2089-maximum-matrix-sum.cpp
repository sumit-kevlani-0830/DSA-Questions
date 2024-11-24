class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long sum = 0;
        int negatives = 0;
        int mini = abs(matrix[0][0]);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                sum += abs(matrix[i][j]);
                mini = min(mini,abs(matrix[i][j]));
                if(matrix[i][j]<0)negatives++;
            }
        }
        if(negatives%2==0){
            return sum;
        }
        else{
            return (sum-2*mini);
        }
    }
};