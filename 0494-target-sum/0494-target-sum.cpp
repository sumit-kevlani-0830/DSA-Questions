class Solution {
public:
    int answer(vector<int>&nums,int tar,int n,int i,int currsum,vector<vector<int>>&dp){
        if(currsum>tar || i>n){
            return 0;
        }
        if(i==n){
            return (currsum==tar);
        }
        if(dp[i][currsum]!=-1){
            return dp[i][currsum];
        }
        int ans1 = answer(nums,tar,n,i+1,currsum+nums[i],dp);
        int ans2 = answer(nums,tar,n,i+1,currsum,dp);
        return dp[i][currsum] = (ans1+ans2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }    
        if((sum+target)%2!=0){
            return 0;
        }
        else{
            int currsum = 0;
            int i = 0;
            int tar = (sum+target)/2;
            if(tar<0){
                return 0;
            }
            vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
            int ans = answer(nums,tar,n,i,currsum,dp);
            return ans;
        }
    }
};