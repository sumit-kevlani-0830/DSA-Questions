class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        vector<int>cnt(26,0);
        for(int i = 0;i < n;i++){
            cnt[s[i]-'a']++;
        }
        int odds = 0;
        for(int i = 0;i < 26;i++){
            if(cnt[i]%2!=0){
                odds++;
            }
        }
        return (n>=k)&&(odds<=k);
    }
};