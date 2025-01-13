def solve(col, board, ans, leftrow, upperDiagonal, lowerDiagonal, n):
    if col == n:
        ans.append(board[:])
        return


    for row in range(n):
        if leftrow[row] == 0 and lowerDiagonal[row+col] == 0 and upperDiagonal[n-1+col-row] == 0:
            board[row] = board[row][:col] + 'Q' + board[row][col+1:]
            leftrow[row] = 1
            lowerDiagonal[row+col] = 1
            upperDiagonal[n-1+col-row] = 1
            solve(col+1, board, ans, leftrow,upperDiagonal, lowerDiagonal, n)
            board[row] = board[row][:col] + '.' + board[row][col+1:]
            leftrow[row] = 0
            lowerDiagonal[row+col] = 0
            upperDiagonal[n-1+col-row] = 0


def solveNQueens(n):
    ans = []
    board = ['.' *n for _ in range(n)]
    # print(board)
    leftrow = [0]*n
    upperDiagonal = [0]*(2*n-1)
    lowerDiagonal = [0]*(2*n-1)
    solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n)
    print(ans)

solveNQueens(4)