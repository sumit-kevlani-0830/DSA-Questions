class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int>vec1(n,0);
        vector<int>vec2(n,0);
        for(int i = 0;i < n;i++){
            vec1[i] = values[i]+i;
            vec2[i] = values[i]-i;
        }
        for(int i = n-2;i >= 0;i--){
            vec2[i] = max(vec2[i],vec2[i+1]);
        }
        int ans = 0;
        for(int i = 0;i < n-1;i++){
            ans = max(ans,vec1[i]+vec2[i+1]);
        }
        return ans;
    }
};