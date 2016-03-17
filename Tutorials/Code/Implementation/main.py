def distance(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5

T = int(raw_input())

for t in range(T):
    N, Q = map(int, raw_input().split())
    locations = {}
    for n in range(N):
        L, X, Y = raw_input().split()
        locations[L] = (int(X), int(Y))
    for q in range(Q):
        L1, L2 = raw_input().split()
        print distance(locations[L1], locations[L2])