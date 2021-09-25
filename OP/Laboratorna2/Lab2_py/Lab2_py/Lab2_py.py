a=float(input("Введiть розмiри сторiн цеглини: а = "))
b=float(input("b = "))
c=float(input("c = "))
x=float(input("Введiть розмiри отвору: x = "))
y=float(input("y = "))


if (a <= x and b <= y) or (b <= x and a <= y) or (b <= x and c <= y) or (c <= x and b <= y) or (a <= x and c <= y) or (c <= x) and (a <= y):
    print("Цеглина з заданими розмiрами пройде в отвiр")
else:
    print("Цеглина з заданими розмiрами не пройде в отвiр")