class Solution {
public:
    vector<pair<int,int>> createNumberDigitSumPair(vector<int>&nums, int n){
        vector<pair<int,int>>vec(n);
        for(int i = 0;i < n;i++){
            int currNum = nums[i];
            int currSum = 0;
            while(currNum>0){
                currSum += (currNum%10);
                currNum /= 10;
            }
            vec[i] = {currSum,nums[i]};
        }
        return vec;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>vec = createNumberDigitSumPair(nums,n);
        sort(vec.begin(),vec.end());
        // [18,43,36,13,7]
        // [9,7,9,4,7]
        // [(4,13),(7,13),(7,43),(9,18),(9,36)]
        int ans = -1;
        int i = 0;
        while(i+1<n){
            if(vec[i].first==vec[i+1].first){
                ans = max(ans,vec[i].second+vec[i+1].second);
            }
            i++;
        }
        return ans;
    }
};