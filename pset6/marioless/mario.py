def main():

 while True:
    altura = int(input("Altura: "))
    if altura > 0 and altura < 9:
        break
    return altura

 for i in range(altura):
    print(" " * (altura - i), end="")
    for j in range(i):
        print("#", end="")
    print()

main()