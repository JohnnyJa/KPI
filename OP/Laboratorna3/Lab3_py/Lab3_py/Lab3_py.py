from math import *


a = float( input( "Введіть значення а: " ))

result = 0
E = 0.000001
counter = 1
last = 0
flag = 1

while flag > E:
    result += pow(-1 , counter - 1) * pow( (a - 1), counter ) / counter
    counter += 1
    flag = abs(result - last)
    last = result

print("Результат обчислень за формулою: ", format(result, '.6f'))
print("Результат обчислень стандартною функцією: ", format(log(a), '.6f'))