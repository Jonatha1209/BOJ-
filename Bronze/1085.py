x, y, w, h = map(int, input().split())

distances = [x, y, w - x, h - y]
min_distance = min(distances)

print(min_distance)
