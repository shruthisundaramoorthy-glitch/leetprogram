bool dfs(char** board,
         int boardSize,
         int* boardColSize,
         int row,
         int col,
         char* word,
         int index) {

   
    if(word[index] == '\0')
        return true;

    
    if(row < 0 || col < 0 ||
       row >= boardSize ||
       col >= boardColSize[0] ||
       board[row][col] != word[index])
        return false;

    char temp = board[row][col];

    board[row][col] = '#';

    
    bool found =
        dfs(board, boardSize, boardColSize,
            row + 1, col, word, index + 1) ||

        dfs(board, boardSize, boardColSize,
            row - 1, col, word, index + 1) ||

        dfs(board, boardSize, boardColSize,
            row, col + 1, word, index + 1) ||

        dfs(board, boardSize, boardColSize,
            row, col - 1, word, index + 1);

   
    board[row][col] = temp;

    return found;
}

bool exist(char** board,
           int boardSize,
           int* boardColSize,
           char* word) {

    for(int i = 0; i < boardSize; i++) {

        for(int j = 0; j < boardColSize[0]; j++) {

            if(dfs(board,
                   boardSize,
                   boardColSize,
                   i,
                   j,
                   word,
                   0))
                return true;
        }
    }

    return false;
}