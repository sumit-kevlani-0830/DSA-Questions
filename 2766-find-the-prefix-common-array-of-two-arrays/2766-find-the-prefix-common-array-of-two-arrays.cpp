class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        long long num = pow(2.0,n)-1;
        int currans = n;
        for(int i = n-1;i >= 0;i--){
            ans[i] = currans;
            A[i]--;B[i]--;
            long long num1 = pow(2.0,A[i]);
            long long num2 = pow(2.0,B[i]);
            if((num&num1)>0){
                num = (num^num1);
                currans--;
            }
            if((num&num2)>0){
                num = (num^num2);
                currans--;
            }
        }
        return ans;
    }
};