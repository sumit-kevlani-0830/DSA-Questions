class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        unordered_set<int>s;
        for(int num: arr1){
            int temp = num;
            while(s.find(temp)==s.end() && temp>0){
                s.insert(temp);
                temp /= 10;
            }
        }
        int ans = 0;
        for(int num: arr2){
            int temp = num;
            while(s.find(temp)==s.end() && temp>0){
                temp /= 10;
            }
            if(temp>0){
                ans = max(ans,(int)(log10(temp)+1));
            }
        }
        return ans;
    }
};