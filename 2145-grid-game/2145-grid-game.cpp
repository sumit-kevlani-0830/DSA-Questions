class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int n = grid[0].size();
        //Robot 1 goes down at 0
        long long U=reduce(grid[0].begin()+1, grid[0].end(), 0LL);
        long long D=0LL;
        long long Robot2=U; // Points obtained by Robot 2

        for (int i=1; i < n; i++) {
            U-= grid[0][i]; // Robot 1 goes down at i
            D+= grid[1][i-1]; // Robot 2 takes path in both directions
            
            long long P=max(U, D); // optimized path for Robot 2
            Robot2 = min(Robot2, P);
        }

        return Robot2;
    }
};