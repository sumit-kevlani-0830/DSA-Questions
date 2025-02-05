class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n!=m){
            return false;
        }
        else{
            int idx1 = -1;
            int idx2 = -1;
            for(int i = 0;i < n;i++){
                if(s1[i]!=s2[i]){
                    if(idx1==-1){
                        idx1 = i;
                    }
                    else if(idx2==-1){
                        idx2 = i;
                    }
                    else{
                        return false;
                    }
                }
            }
            if(idx1==-1 && idx2==-1){
                return true;
            }
            else if(idx2==-1){
                return false;
            }
            else{
                return ((s1[idx1]==s2[idx2])&&(s1[idx2]==s2[idx1]));
            }
        }
    }
};