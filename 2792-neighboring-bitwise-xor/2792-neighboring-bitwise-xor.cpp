class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int curr_xor = 0;
        for(int num: derived){
            curr_xor = curr_xor^num;
        }
        return (curr_xor==0);
    }
};
