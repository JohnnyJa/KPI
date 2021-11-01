
a = 22200;

for i in range(0,10):
    for j in range(0,10):
        n = a + i * 10 + j
        if(n % 15 == 0):
            print(n);
