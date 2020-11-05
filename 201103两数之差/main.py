# -*- encoding: utf-8 -*-

l = [1, 2, 3, 6, 7, 8]

ans = 0

for i in l:
    for j in l:
        if i == j:
            continue
        for k in l:
            if i == k or j == k:
                continue
            for o in l:
                if i == o or j == o or k == o:
                    continue
                a = i * 10 + j
                b = k * 10 + o
                if a - b == 35:
                    ans += 1

print(ans)
