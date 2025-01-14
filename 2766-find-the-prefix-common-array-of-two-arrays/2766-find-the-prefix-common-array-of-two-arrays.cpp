class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        unordered_set<int>s;
        for(int i = n-1;i >= 0;i--){
            ans[i] = n-s.size();
            s.insert(A[i]);
            s.insert(B[i]);
        }
        return ans;
    }
};