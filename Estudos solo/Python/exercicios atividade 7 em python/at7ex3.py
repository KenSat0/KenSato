
def A(m, n):
    if m == 0:
        termo = n + 1
        return termo
    elif m > 0 == n:
        termo = A(m - 1, 1)
        return termo
    elif m > 0 and n > 0:
        termo = A(m - 1, A(m, n - 1))
        return termo
    

print(A(3, 2))