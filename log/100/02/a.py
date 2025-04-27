N = int(input())
A = [int(x) for x in input().split()]
sum = 0

for i in range(N):
    if i%2 == 0:
        sum += A[i]
print(sum)

# https://atcoder.jp/contests/abc403/submissions/65243824
