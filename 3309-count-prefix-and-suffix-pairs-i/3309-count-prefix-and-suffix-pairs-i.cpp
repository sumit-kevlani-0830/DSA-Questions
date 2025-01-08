class Solution {
public:
    bool isPrefixAndSuffix(string &str1,string &str2){
        int n = str1.length();
        int m = str2.length();
        if(n>m){
            return false;
        }
        else{
            bool ans1 = (str2.find(str1)==0);
            reverse(str1.begin(),str1.end());
            reverse(str2.begin(),str2.end());
            bool ans2 = (str2.find(str1)==0);
            reverse(str1.begin(),str1.end());
            reverse(str2.begin(),str2.end());
            return (ans1&&ans2);
        }
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};