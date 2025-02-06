class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<long long,int>mp;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                long long curr = nums[i]*nums[j];
                mp[curr]++;
            }
        }
        int ans = 0;
        for(auto it: mp){
            int freq = it.second;
            ans += (4*freq*(freq-1));
        }
        return ans;
    }
};