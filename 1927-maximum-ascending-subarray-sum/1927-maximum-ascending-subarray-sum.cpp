class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        while(i<n){
            int currans = 0;
            while(i+1<n && nums[i]<nums[i+1]){
                currans += nums[i];
                i++;
            }
            currans += nums[i];
            ans = max(ans,currans);
            i++;
        }
        return ans;
    }
};