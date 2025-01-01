class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int zeroes = 0;
        int ones = 0;
        for(char ch: s){
            if(ch=='0'){
                zeroes++;
            }
            if(ch=='1'){
                ones++;
            }
        }
        int ans = 0;
        int lzeroes = 0;
        int lones = 0;
        int rones = ones;
        int rzeroes = zeroes;
        for(int i = 0;i < n-1;i++){
            if(s[i]=='0'){
                lzeroes++;
                rzeroes = zeroes-lzeroes;
            }
            if(s[i]=='1'){
                lones++;
                rones = ones-lones;
            }
            ans = max(ans,lzeroes+rones);
        }
        return ans;
    }
};