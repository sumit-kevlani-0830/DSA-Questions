class TrieNode{
    public:
        TrieNode* count[2];
        TrieNode(){
            for(int i = 0;i < 2;i++){
                count[i] = NULL;
            }
        }
        TrieNode* getZero(){
            return count[0];
        }  
        TrieNode* getOne(){
            return count[1];
        }
        void setZero(){
            count[0] = new TrieNode();
        }
        void setOne(){
            count[1] = new TrieNode();
        }
        bool containsKey(int x){
            return (count[x]!=NULL);
        }
        TrieNode* getKey(int x){
            return count[x];
        }
        void setKey(int x){
            count[x] = new TrieNode();
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        void insert(int num){
            TrieNode* node = root;
            for(int i = 31;i >= 0;i--){
                int bit = ((num>>i)&1);
                if(!node->containsKey(bit)){
                    node->setKey(bit);
                }
                node = node->getKey(bit);
            }
        }
        int getMaxXOR(int num){
            TrieNode* node = root;
            int ans = 0;
            for(int i = 31;i >= 0;i--){
                int bit = ((num>>i)&1);
                if(node->containsKey(1-bit)){
                    ans += (1<<i);
                    node = node->getKey(1-bit);
                }else{
                    node = node->getKey(bit);
                }
            }
            return ans;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie* trie = new Trie();
        for(int i = 0;i < n;i++){
            trie->insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans = max(ans,trie->getMaxXOR(nums[i]));
        }
        return ans;
    }
};