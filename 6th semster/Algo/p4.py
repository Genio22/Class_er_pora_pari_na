def lcs(x,y):
    m, n = len(x), len(y)
    l = [[o for i in range(m)] for i in range(n)]
    arrow = [[o for i in range(m)] for i in range(n)]

    for i in range(m):
        for j in range(n):
            if x[i-1] == y[j-1]:
                l[i][j] = l[i-1][j-1]+1
                arrow
            else
                if l[i-1][j] >= 

