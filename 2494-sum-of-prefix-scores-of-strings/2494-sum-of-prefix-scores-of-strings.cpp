class TrieNode{
    public:
        TrieNode* links[26];
        int count;
        TrieNode(){
            for(int i = 0;i < 26;i++){
                links[i] = NULL;
            }
            count = 0;
        }
        void setChild(char ch){
            links[ch-'a'] = new TrieNode();
        }
        TrieNode* getChild(char ch){
            return links[ch-'a'];
        }
        void incrCount(){
            count = count+1;
        }
        int getCount(){
            return count;
        }
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        void insert(string word){
            TrieNode* node = root;
            for(char ch: word){
                if(node->containsKey(ch)==NULL){
                    node->setChild(ch);
                }
                node = node->getChild(ch);
                node->incrCount();
            }
        }
        int prefixScore(string word){
            TrieNode* node = root;
            int ans = 0;
            for(char ch: word){
                node = node->getChild(ch);
                ans += node->getCount();
            }
            return ans;
        }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int>ans(n);
        Trie* trie = new Trie();
        for(string word: words){
            trie->insert(word);
        }
        int i = 0;
        for(string word: words){
            ans[i] = trie->prefixScore(word);
            i++;
        }
        return ans;
    }
};