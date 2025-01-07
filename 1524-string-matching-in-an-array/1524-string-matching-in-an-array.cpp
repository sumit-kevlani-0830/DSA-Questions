class Solution {
public:
    static bool compare(string &s1, string &s2){
        return s1.length()<s2.length();
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        sort(words.begin(),words.end(),compare);
        for(int i = 0;i < n;i++){
            for(int j = n-1;j > i;j--){
                string s1 = words[i];
                string s2 = words[j];
                if(s2.find(s1)!=-1 && find(ans.begin(),ans.end(),s1)==ans.end()){
                    ans.push_back(s1);
                }
            }
        }
        return ans;
    }
};