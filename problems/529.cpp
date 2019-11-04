bool checkPosition(const int& xSize, const int& ySize, const int& xPos, const int& yPos) {
    if (xPos >= 0 && xPos < xSize && yPos >= 0 && yPos < ySize) return true;
    return false;
}

void reveal(vector<vector<char>>& board, const int& x, const int& y) {
    if (!checkPosition(board.size(), board[0].size(), x, y)) return;
    if (board[x][y] == 'E') {
        int counter = 0;
        if (checkPosition(board.size(), board[0].size(), x - 1, y - 1) 
            && board[x - 1][y - 1] == 'M') counter++;
        if (checkPosition(board.size(), board[0].size(), x - 1, y) 
            && board[x - 1][y] == 'M') counter++;
        if (checkPosition(board.size(), board[0].size(), x - 1, y + 1) 
            && board[x - 1][y + 1] == 'M') counter++;
        if (checkPosition(board.size(), board[0].size(), x, y - 1) 
            && board[x][y - 1] == 'M') counter++;
        if (checkPosition(board.size(), board[0].size(), x, y + 1) 
            && board[x][y + 1] == 'M') counter++;
        if (checkPosition(board.size(), board[0].size(), x + 1, y - 1) 
            && board[x + 1][y - 1] == 'M') counter++;
        if (checkPosition(board.size(), board[0].size(), x + 1, y) 
            && board[x + 1][y] == 'M') counter++;
        if (checkPosition(board.size(), board[0].size(), x + 1, y + 1) 
            && board[x + 1][y + 1] == 'M') counter++;

        if (counter > 0) {
            board[x][y] = '0' + counter;
        } else {
            board[x][y] = 'B';
            reveal(board, x - 1, y - 1);
            reveal(board, x - 1, y);
            reveal(board, x - 1, y + 1);
            reveal(board, x, y - 1);
            reveal(board, x, y + 1);
            reveal(board, x + 1, y - 1);
            reveal(board, x + 1, y);
            reveal(board, x + 1, y + 1);
        }
    }
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    reveal(board, click[0], click[1]);
    return board;
}
