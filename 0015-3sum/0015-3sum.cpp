class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i<n-2){
            int j = i+1;
            int k = n-1;
            int a = nums[i];
            while(j<k){
                int b = nums[j];
                int c = nums[k];
                if(a+b+c==0){
                    vector<int>currans = {nums[i],nums[j],nums[k]};
                    ans.push_back(currans);
                    while(j<k && nums[j]==b){
                        j++;
                    }
                    while(j<k && nums[k]==c){
                        k--;
                    }
                }
                else if(a+b+c>0){
                    while(j<k && nums[k]==c){
                        k--;
                    }
                }
                else{
                    while(j<k && nums[j]==b){
                        j++;
                    }
                }
            }
            while(i<n-2 && nums[i]==a){
                i++;
            }
        }
        return ans;
    }
};