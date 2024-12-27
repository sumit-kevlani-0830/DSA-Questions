class TrieNode{
    public:
        bool end;
        TrieNode* child[26];
        TrieNode(){
            for(int i = 0;i < 26;i++){
                child[i] = NULL;
            }
            end = false;
        }
        void setChild(char ch){
            int idx = (ch-'a');
            child[idx] = new TrieNode();
        }
        TrieNode* getChild(char ch){
            int idx = (ch-'a');
            return child[idx];
        }
        void setEnd(){
            end = true;
        }
        bool getEnd(){
            return end;
        }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch: word){
            if(node->getChild(ch)==NULL){
                node->setChild(ch);
            }
            node = node->getChild(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch: word){
            if(node->getChild(ch)==NULL){
                return false;
            }
            node = node->getChild(ch);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch: prefix){
            if(node->getChild(ch)==NULL){
                return false;
            }
            node = node->getChild(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */