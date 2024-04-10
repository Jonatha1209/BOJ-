pieces = list(map(int, input().split()))
correct_pieces = [1, 1, 2, 2, 2, 8]
changes = [correct_pieces[i] - pieces[i] for i in range(len(pieces))]
print(*changes)
