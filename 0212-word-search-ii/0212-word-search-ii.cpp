class TrieNode{
    bool end;
    TrieNode* child[26];
    string word;
    public:
        TrieNode(){
            end = false;
            for(int i = 0;i < 26;i++){
                child[i] = NULL;
            }
            word = "";
        }
        bool getEnd(){
            return end;
        }
        void setEnd(bool end){
            this->end = end;
        }
        TrieNode* getChild(char ch){
            return child[ch-'a'];
        }
        void setChild(char ch){
            this->child[ch-'a'] = new TrieNode();
        }
        string getWord(){
            return word;
        }
        void setWord(string word){
            this->word = word;
        }
        bool containsKey(char ch){
            return (child[ch-'a']!=NULL);
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
            node->setEnd(true);
            node->setWord(word);
        }
};
class Solution {
public:
    void findTrieWords(vector<vector<char>>&board, int i, int j, TrieNode* &root, vector<string>&ans, int n, int m, vector<int>&dx, vector<int>&dy){
        if(root->getEnd()){
            ans.push_back(root->getWord());
            root->setEnd(false);
            root->setWord("");
        }
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        if(board[i][j]=='$' || !root->containsKey(board[i][j])){
            return;
        }
        TrieNode* newRoot = root->getChild(board[i][j]);
        char temp = board[i][j];
        board[i][j] = '$';
        for(int k = 0;k < 4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            findTrieWords(board,nx,ny,newRoot,ans,n,m,dx,dy);
        }
        board[i][j] = temp;   
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        vector<int>dx = {-1,0,0,1};
        vector<int>dy = {0,1,-1,0};
        int n = board.size();
        int m = board[0].size();
        int len = words.size();
        Trie* trie = new Trie();
        for(int i = 0;i < len;i++){
            trie->insert(words[i]);
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                TrieNode* node = trie->root;
                if(node->containsKey(board[i][j])){
                    findTrieWords(board,i,j,node,ans,n,m,dx,dy);
                }
            }
        }
        return ans;
    }
};