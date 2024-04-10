chess_board = [input() for _ in range(8)]
count = sum(chess_board[i][j] == 'F' for i in range(8) for j in range(8) if (i + j) % 2 == 0)
print(count)
