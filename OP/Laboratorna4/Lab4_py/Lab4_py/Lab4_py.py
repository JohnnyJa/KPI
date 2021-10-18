n = int(input( "Введіть значення n: "))
sum = float(0)

for i in range (1, n+1):
    sum += 1/(i*(2*i+1)*(2*i+1))

print(sum)