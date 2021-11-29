from math import sqrt

def calculate_square_triangle(a, b, c):
    p = (a + b + c) / 2
    square = sqrt(p * (p - a) * (p - b) * (p - c))
    return square




def calculate_max_square(square1, square2, square3):
    if((square1 > square2) and (square1 > square3)):
        max = square1
    if((square2 > square3) and (square2 > square1)):
        max = square2
    if((square3 > square2) and (square3 > square1)):
        max = square3
    return max




def inputValues():
    f = True
    while(f):
        f = False
        a = float(input())
        b = float(input())
        c = float(input())
        if((a >= b + c) or (b >= a + c) or (c >= b + a)):           #Перевіряємо, чи існує трикутнник
            print("Такого трикутника не існує")
            f = True
    return a, b, c




def output(square1, square2, square3, answer):
    print("Площа першого трикутника: ", square1, "\nПлоща другого трикутника: ", square2, "\nПлоща третього трикутника: ", square3, "\nНайбільша площа трикутника: ", answer)



print("Введіть сторони першого трикутника:")
a1, b1, c1 = inputValues()

print("Введіть сторони другого трикутника:")
a2, b2, c2 = inputValues()

print("Введіть сторони третього трикутника:")
a3, b3, c3 = inputValues()

#обчислюємо площі трикутників

square1 = calculate_square_triangle(a1, b1, c1)
square2 = calculate_square_triangle(a2, b2, c2)
square3 = calculate_square_triangle(a3, b3, c3)

output(square1, square2, square3, calculate_max_square(square1, square2, square3) )


