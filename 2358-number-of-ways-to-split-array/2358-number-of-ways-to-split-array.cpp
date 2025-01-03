class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }
        int ans = 0;
        long long leftSum = 0;
        for(int i = 0;i < n-1;i++){
            leftSum += nums[i];
            if(leftSum>=sum-leftSum){
                ans++;
            }
        }
        return ans;
    }
};