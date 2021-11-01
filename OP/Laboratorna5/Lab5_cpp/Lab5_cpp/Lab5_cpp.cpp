
#include <iostream>

using namespace std;

int main()
{
    
    int a = 22200, n;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            n = a + i * 10 + j;
            if (n % 15 == 0) {
                cout << n << ' ';
            }
        }
    }

    return 0;
}

