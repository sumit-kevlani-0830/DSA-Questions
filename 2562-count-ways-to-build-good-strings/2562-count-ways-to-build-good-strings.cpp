class Solution {
public:
    
    int countGoodStrings(int low, int high, int zero, int one) {
       vector<long long>dp(high+1,0);
       dp[0] = 1;
       long long mod = (1e9+7)*1ll;
       for(int i = 1;i < high+1;i++){
        if(i>=zero){
            dp[i] =(dp[i]+dp[i-zero])%mod;
        }
        if(i>=one){
            dp[i] =(dp[i]+dp[i-one])%mod;
        }
       }
       long long ans = 0;
       for(int i = low;i <= high;i++){
        ans = (ans+dp[i])%mod;
       }
       return (int)(ans);
    }
};