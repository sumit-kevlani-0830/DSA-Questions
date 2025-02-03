class Solution {
public:
    int answer(vector<int>&nums,int n){
        if(n==1)return 1;
        int ans = 0;
        int i = 0;
        while(i<n){
            int j = i;
            if(i+1<n && nums[i]<nums[i+1]){
                while(i+1<n && nums[i]<nums[i+1]){
                    i++;
                }
            }
            ans = max(ans,i-j+1);
            i++;
        }
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = answer(nums,n);
        reverse(nums.begin(),nums.end());
        ans = max(ans,answer(nums,n));
        return ans;
    }
};