#include <cstdio>
#include <algorithm>

int main() {
    int n;

    // Get an input for the value N, which is between 1 and 1000000.
    scanf("%d", &n);

    bool *numbersCheck = new bool[2000001];
    for (int i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);

        numbersCheck[number + 1000000] = true;
    }

    for (int num = -1000000; num <= 1000000; num++) {
        if (numbersCheck[num + 1000000]) {
            printf("%d\n", num);
        }
    }

    delete[] numbersCheck;

    return 0;
}
