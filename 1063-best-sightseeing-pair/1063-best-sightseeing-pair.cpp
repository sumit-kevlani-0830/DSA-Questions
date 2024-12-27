class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int prev1 = values[n-1]+n-1;
        int prev2 = values[n-1]-(n-1);
        for(int i = n-2;i >= 0;i--){
            int curr1 = values[i]+i;
            int curr2 = max(prev2,values[i]-i);
            ans = max(ans,curr1+prev2);
            prev1 = curr1;
            prev2 = curr2;
        }
        return ans;
    }
};