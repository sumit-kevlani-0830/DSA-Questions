class Solution {
public:
    int answer(int n,vector<int>&nums,int tar){
        vector<int>prev(tar+1,0);
        prev[0] = 1;
        for(int i = 1;i < n+1;i++){
            vector<int>curr(tar+1,0);
            curr[0] = 1;
            for(int j = 1;j < tar+1;j++){
                int ans1 = 0;
                int ans2 = 0;
                if(j-nums[i-1]>=0)
                    ans1 = prev[j-nums[i-1]];
                ans2 = prev[j];
                curr[j] = ans1+ans2;
            }
            prev = curr;
        }
        return prev[tar];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }    
        int tar = (sum+target)/2;
        if(tar<0 || (sum+target)%2!=0){
            return 0;
        }
        else{
            vector<int>arr;
            int zeroes = 0;
            for(int i = 0;i < n;i++){
                if(nums[i]==0){
                    zeroes++;
                }
                else{
                    arr.push_back(nums[i]);
                }
            }
            return (int)(pow(2.0,zeroes))*answer(arr.size(),arr,tar);
        }
    }
};