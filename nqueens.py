def solveNQueens(n):
    col = set()
    posDiag = set()
    negDiag = set()
    res = []
    board = [['.'] * n for i in range(n)]

    