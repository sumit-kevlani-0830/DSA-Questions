class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int>bits(31,0);
        for(int i = 0; i < 31;i++){
            int num = (1<<i);
            if(num1&num){
                bits[i] = 1;
            }
        }
        reverse(bits.begin(),bits.end());
        int set_bits = 0;
        while(num2>0){
            num2 = (num2&(num2-1));
            set_bits++;
        }
        int ans = 0;
        int cnt = 0;
        for(int i = 0;i < 31;i++){
            if(bits[i]==1){
                ans += (1<<(30-i));
                cnt++;
            }
            if(cnt==set_bits)return ans;
        }
        if(cnt<set_bits){
            for(int i = 0;i < 31;i++){
                int num = (1<<i);
                if((ans&num)==0){
                    ans += (1<<i);
                    cnt++;
                }
                if(cnt==set_bits)return ans;
            }
        }
        return ans;
    }
};