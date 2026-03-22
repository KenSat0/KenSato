
def rev_str(str, lenght):
    letra = str[lenght - 1]
    if (lenght == 0):
        str_rev = ""
        return str_rev
    else:
        str_rev = letra + rev_str(str, lenght - 1)
        return str_rev


string = input("String: ")

lenght = len(string)

print(rev_str(string, lenght))