class TrieNode{
    TrieNode child[];
    boolean end;
    TrieNode(){
        child = new TrieNode[26];
        end = false;
    }
    boolean getEnd(){
        return end;
    }
    void setEnd(){
        end = true;
    }
    TrieNode getChild(char ch){
        return child[ch-'a'];
    }
    void setChild(char ch){
        child[ch-'a'] = new TrieNode();
    }
}
class Trie {
    TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode node = root;
        int n = word.length();
        // for(char ch: word){
        // }
        // node.setEnd();
        for(int i = 0;i < n;i++){
            char ch = word.charAt(i);
            if(node.getChild(ch)==null){
                node.setChild(ch);
            }
            node = node.getChild(ch);
        }
        node.setEnd();
    }
    
    public boolean search(String word) {
        TrieNode node = root;
        int n = word.length();
        for(int i = 0;i < n;i++){
            char ch = word.charAt(i);
            if(node.getChild(ch)==null){
                return false;
            }
            node = node.getChild(ch);
        }
        return node.getEnd();
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        int n = prefix.length();
        for(int i = 0;i < n;i++){
            char ch = prefix.charAt(i);
            if(node.getChild(ch)==null){
                return false;
            }
            else{
                node = node.getChild(ch);
            }
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */