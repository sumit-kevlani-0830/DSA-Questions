class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            if(nums[j]-nums[i]<=2*k){
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};