class Solution {
public:
    bool backtrack(int r, int c, int idx, vector<vector<char>>& board, vector<vector<bool>>& visited, string& word) {
        if (idx == word.size()) return true;   

        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
        if (visited[r][c]) return false;
        if (board[r][c] != word[idx]) return false;

        visited[r][c] = true;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (backtrack(nr, nc, idx + 1, board, visited, word))
                return true;
        }

        visited[r][c] = false; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0]) {
                    if (backtrack(r, c, 0, board, visited, word))
                        return true;
                }
            }
        }
        return false;
    }
};
