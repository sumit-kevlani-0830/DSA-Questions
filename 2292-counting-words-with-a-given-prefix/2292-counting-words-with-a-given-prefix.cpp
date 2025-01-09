class TrieNode{
    int count;
    TrieNode* links[26];
    public:
        TrieNode(){
            count = 0;
            for(int i = 0;i < 26;i++){
                links[i] = NULL;
            }
        }
        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        void setChild(char ch){
            links[ch-'a'] = new TrieNode();
        }
        TrieNode* getChild(char ch){
            return links[ch-'a'];
        }
        void setCount(){
            count = count+1;
        }
        int getCount(){
            return count;
        }
};
class Trie{
    TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        void insert(string word){
            TrieNode* node = root;
            for(char ch: word){
                if(!node->containsKey(ch)){
                    node->setChild(ch);
                }
                node = node->getChild(ch);
                node->setCount();
            }
        }
        int getWordCount(string prefix){
            TrieNode* node = root;
            for(char ch: prefix){
                if(!node->containsKey(ch)){
                    return 0;
                }
                node = node->getChild(ch);
            }
            return node->getCount();
        }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        Trie* trie = new Trie();
        for(string &word: words){
            trie->insert(word);
        }
        return trie->getWordCount(pref);
    }
};