class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int,unordered_set<int>>mp;
        unordered_map<int,int>colorMap;
        vector<int>ans;
        int cnt = 0;
        for(auto it: queries){
            int num = it[0];
            int color = it[1];
            if(colorMap.find(num)==colorMap.end()){
                colorMap[num] = color;
                mp[color].insert(num);
            }
            else{
                int oldColor = colorMap[num];
                unordered_set<int>st = mp[oldColor];
                if(st.size()==1){
                    mp.erase(oldColor);
                }
                else{
                    mp[oldColor].erase(num);
                }
                mp[color].insert(num);
                colorMap[num] = color;
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
};
