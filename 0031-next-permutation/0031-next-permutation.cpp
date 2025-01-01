class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i>0 && nums[i]<=nums[i-1]){
            i--;
        }
        if(i==0){
            sort(nums.begin(),nums.end());
        }else{
            i--;
            int j = n-1;
            int ans = INT_MAX;
            while(j>i && nums[j]<=nums[i]){
                j--;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            sort(nums.begin()+i+1,nums.end());
        }
    }
};