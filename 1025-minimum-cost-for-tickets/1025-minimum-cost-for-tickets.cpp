class Solution {
public:
    int getIndex(vector<int>&days,int num,int n){
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(days[mid]<=num){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
    int answer(vector<int>&days,vector<int>&costs,int i,int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans1 = answer(days,costs,i+1,n,dp)+costs[0];
        int idx1 = getIndex(days,days[i]+6,n);
        int idx2 = getIndex(days,days[i]+29,n);
        int ans2 = answer(days,costs,idx1,n,dp)+costs[1];
        int ans3 = answer(days,costs,idx2,n,dp)+costs[2];
        return dp[i] = min(ans1,min(ans2,ans3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,-1);
        int ans = answer(days,costs,0,n,dp);
        return ans;
    }
};