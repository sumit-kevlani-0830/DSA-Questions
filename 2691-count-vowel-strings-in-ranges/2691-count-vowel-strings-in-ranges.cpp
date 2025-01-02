class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>count(n,0);
        for(int i = 0;i < n;i++){
            int len = words[i].length();
            if(isVowel(words[i][0]) && isVowel(words[i][len-1])){
                count[i] = (i==0?1:count[i-1]+1);
            }
            else{
                count[i] = (i==0?0:count[i-1]);
            }
        }
        int len = queries.size();
        vector<int>ans(len);
        for(int i = 0;i < len;i++){
            int low = queries[i][0];
            int high = queries[i][1];
            ans[i] = count[high];
            if(low>0){
                ans[i] -= count[low-1];
            }
        }
        return ans;
    }
};