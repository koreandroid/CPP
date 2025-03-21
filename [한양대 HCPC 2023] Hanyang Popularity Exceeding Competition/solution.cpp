#include <cstdio>
#include <iostream>
#include <cmath>

#define N_MAX 200000

int main()
{
    int n;
    scanf("%d", &n);

    if (!(1 <= n && n <= N_MAX)) {
        printf("The value of N is invalid. It should be between 1 and %d.\n", N_MAX);
        return -1;
    }

    int popularity = 0;
    for (int i = 0; i < n; i++) {
        int p, c;
        scanf("%d%d", &p, &c);

        if (abs(p - popularity) <= c) {
            popularity++;
        }
    }

    printf("%d", popularity);

    return 0;
}
