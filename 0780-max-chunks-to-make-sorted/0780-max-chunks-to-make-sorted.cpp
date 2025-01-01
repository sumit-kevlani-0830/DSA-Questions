class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>preMax(n,0);
        vector<int>sufMin(n,0);
        for(int i = 0;i < n;i++){
            preMax[i] = ((i==0)?arr[i]:max(preMax[i-1],arr[i]));
        }
        for(int i = n-1;i >= 0;i--){
            sufMin[i] = ((i==n-1)?arr[i]:min(sufMin[i+1],arr[i]));
        }
        int ans = 1;
        for(int i = 0;i < n-1;i++){
            if(preMax[i]<=sufMin[i+1]){
                ans++;
            }
        }
        return ans;
    }
};