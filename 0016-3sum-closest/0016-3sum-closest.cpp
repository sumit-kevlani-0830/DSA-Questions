class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int resultSum = -1;
        for(int i = 0;i < n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target){
                    ans = 0;
                    return sum;
                }
                else if(sum<target){
                    // ans = min(ans,target-sum);
                    // j++;
                    if(ans>target-sum){
                        ans = target-sum;
                        resultSum = sum;
                    }
                    j++;
                }
                else{
                    // ans = min(ans,sum-target);
                    // k--;
                    if(ans>sum-target){
                        ans = sum-target;
                        resultSum = sum;
                    }
                    k--;
                }
            }
        }
        return resultSum;
    }
};