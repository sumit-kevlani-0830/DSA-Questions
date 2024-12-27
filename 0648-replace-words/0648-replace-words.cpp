class TrieNode{
    public:
        TrieNode* links[26];
        bool end;
        TrieNode(){
            for(int i = 0;i < 26;i++){
                links[i] = NULL;
            }
            end = false;
        }
        void setEnd(){
            this->end = true;
        }
        bool getEnd(){
            return this->end;
        }
        void setChild(char ch){
            links[ch-'a'] = new TrieNode();
        }
        TrieNode* getChild(char ch){
            return links[ch-'a'];
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
                if(node->getChild(ch)==NULL){
                    node->setChild(ch);
                }
                node = node->getChild(ch);
            }
            node->setEnd();
        }
        string getSmallestPrefix(string word){
            string ans = "";
            TrieNode* node = root;
            for(char ch: word){
                if(node->getEnd()){
                    return ans;
                }
                else if(node->containsKey(ch)){
                    ans += ch;
                    node = node->getChild(ch);
                }
                else{
                    return word;
                }
            }
            return ans;
        }
};
class Solution {
public:
    vector<string> splitString(string sentence){
        vector<string>ans;
        string temp = "";
        for(char ch: sentence){
            if(ch == ' '){
                ans.push_back(temp);
                temp = "";
            }
            else{
                temp += ch;
            }
        }
        ans.push_back(temp);
        return ans;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        Trie* trie = new Trie();
        for(int i = 0;i < n;i++){
            trie->insert(dictionary[i]);
        }
        TrieNode* root = trie->root;
        vector<string>words = splitString(sentence);
        string ans = "";
        for(string word: words){
            string currans = "";
            if(!root->containsKey(word[0])){
                ans += word;
                ans += ' ';
            }
            else{
                ans += trie->getSmallestPrefix(word);
                ans += ' ';
            }
        }
        return ans.substr(0,ans.length()-1);
    }
};