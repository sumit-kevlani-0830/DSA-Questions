class Solution {
public:
    bool findWord(vector<vector<char>>&board,int i,int j,int n,int m,string &word,int len,int k,vector<int>&dx,vector<int>&dy){
        if(k==len){
            return true;
        }
        if(i<0||j<0||i>=n||j>=m){
            return false;
        }
        if(board[i][j]==word[k]){
            char temp = board[i][j];
            board[i][j] = '$';
            for(int p = 0;p < 4;p++){
                int nx = i+dx[p];
                int ny = j+dy[p];
                if(findWord(board,nx,ny,n,m,word,len,k+1,dx,dy)){
                    return true;
                }
            }
            board[i][j] = temp;
            return false;
        }else{
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int len = word.length();
        vector<int>dx = {-1,0,0,1};
        vector<int>dy = {0,1,-1,0};
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j]==word[0]){
                    bool ans = findWord(board,i,j,n,m,word,len,0,dx,dy);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};