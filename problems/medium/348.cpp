// Number: 348
// Name: Design Tic-Tac-Toe
// Tags: design

// optimized brute force time: O(4*n) space : O(n^2)
class TicTacToe_0 {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        d_n = n;
        for (int i = 0; i < n; ++i) {
            vector<int> init_vector(n, 0);
            rows[i] = init_vector;
            cols[i] = init_vector;
        }
        for (int i = 0; i < 2; ++i) {
            vector<int> init_vector(n, 0);
            diags[i] = init_vector;
        }
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        rows[row][col] = player;
        cols[col][row] = player;
        if (row == col) diags[0][row] = player;
        if (row == d_n - 1 - col) diags[1][row] = player;
        if (check(row, col, player)) return player;
        return 0;
    }
    
    bool check(int row, int col, int player) {
        bool curRowStatus = true;
        bool curColStatus = true;
        bool curLeftDiagStatus = true;
        bool curRightDiagStatus = true;
        for (int i = 0; i < d_n; ++i) {
            if (curRowStatus && rows[row][i] != player) {
                curRowStatus = false;
            }
            if (curColStatus && cols[col][i] != player) {
                curColStatus = false;
            }
            if (curLeftDiagStatus && diags[0][i] != player) {
                curLeftDiagStatus = false;
            }
            if (curRightDiagStatus && diags[1][i] != player) {
                curRightDiagStatus = false;
            }
        }
        if (curRowStatus || curColStatus || curLeftDiagStatus || curRightDiagStatus) return true;
        return false;
    }
    
private:
    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;
    unordered_map<int, vector<int>> diags;
    int d_n;
};

