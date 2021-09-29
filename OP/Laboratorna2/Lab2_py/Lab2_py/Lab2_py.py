a = float(input("Введiть розмiри сторiн цеглини: а = "))
b = float(input("b = "))
c = float(input("c = "))
x = float(input("Введiть розмiри отвору: x = "))
y = float(input("y = "))

res = False

if (a <= x and b <= y): 
    res = True
if (b <= x and a <= y): 
    res = True
if (b <= x and c <= y): 
    res = True
if (c <= x and b <= y): 
    res = True
if (a <= x and c <= y): 
    res = True
if (c <= x and a <= y):
    res = True
    
if res:
    print("Цеглина з заданими розмiрами пройде в отвiр")
else:
     print("Цеглина з заданими розмiрами не пройде в отвiр")