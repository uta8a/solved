S = input()
T = input()

chance = False

def check(S, T):
    for i in range(len(S)):
        if S[i] == '?':
            continue
        if S[i] != T[i]:
            return False
    return True

for i in range(len(S) - len(T) + 1):
    if check(S[i:i+len(T)],T):
        chance = True
        break

if chance:
    print("Yes")
else:
    print("No")

# https://atcoder.jp/contests/abc403/submissions/65248293
