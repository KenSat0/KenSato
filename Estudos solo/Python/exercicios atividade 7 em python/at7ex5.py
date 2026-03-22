
def mdc(a, b):
    if a > b:
        temp = a
        a = b
        b = temp
    if (b%a) == 0:
        return a
    else:
        result = mdc((b%a), a)
        return result
    
x = int(input("X: "))
y = int(input("Y: "))
z = int(input("Z: "))

print(mdc(mdc(x, y), z))