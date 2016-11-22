S = raw_input()
W = raw_input()

# Build failure function in O(|W|)
# F[i] = length of longest proper prefix that is also a suffix of W[:i]
# F[F[i]] = length of second longest ...
# etc.

F = [0]*(len(W)+1)
for i in range(2, len(W) + 1):
    j = F[i-1]
    while True:
        if W[j] == W[i-1]:
            F[i] = j + 1
            break
        if j == 0:
            F[i] = 0
            break
        j = F[j]

print "Failure function:"
print F

# Run KMP

i = 0
j = 0
while j < len(S):
    if S[j] == W[i]:
        i += 1
        j += 1
        if i == len(W):
            # Found a match
            print "Found a match at index %d" % j
            i = F[i]
    elif i > 0:
        i = F[i]
    else:
        j += 1
