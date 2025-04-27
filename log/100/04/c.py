N, M, Q = map(int, input().split())

user1 = set([])
user2 = [0] * (N + 1)

for i in range(Q):
    query = input().split()
    # print(m)
    if query[0] == "1":
        x, y = int(query[1]), int(query[2])
        user1.add((x, y))
    elif query[0] == "2":
        x = int(query[1])
        user2[x] = 1
    elif query[0] == "3":
        x, y = int(query[1]), int(query[2])
        if user2[x] == 1:
            print("Yes")
        elif (x,y) in user1:
            print("Yes")
        else:
            print("No")
    else:
        print("Invalid query type")

# https://atcoder.jp/contests/abc403/submissions/65276530
