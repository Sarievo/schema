# Sarievo.
# URL: https://atcoder.jp/contests/dp/tasks/dp_h

mod = int(1e9+7)

n, m = map(int, input().split())

g = []
for _ in range(n):
    g.append(input())

# dp = [[0]*m]*n;
dp = [[0 for i in range(m)] for j in range(n)]
dp[0][0] = g[0][0] == '.'

for i in range(0,n):
    for j in range(0,m):
        if g[i][j] == '#':
            continue
        if i > 0:
            dp[i][j] += dp[i-1][j]
        if j > 0:
            dp[i][j] += dp[i][j-1]
        if dp[i][j] > mod:
            dp[i][j] %= mod

print(int(dp[n-1][m-1]))
