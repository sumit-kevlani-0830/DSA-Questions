class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxLeft = INT_MIN;
        int maxRight = INT_MIN;
        int ans = 0;
        while(left<=right){
            maxLeft = max(maxLeft,height[left]);
            maxRight = max(maxRight,height[right]);
            if(maxLeft<maxRight){
                ans += (maxLeft-height[left]);
                left++;
            }
            else{
                ans += (maxRight-height[right]);
                right--;
            }
        }
        return ans;
    }
};