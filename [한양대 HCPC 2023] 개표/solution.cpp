#include <cstdio>

#define T_MAX 100

int main()
{
    int t;
    scanf("%d", &t);

    if (!(1 <= t && t <= T_MAX)) {
        printf("The value of T is invalid. It should be between 1 and %d.\n", T_MAX);
        return -1;
    }

    for (int i = 0; i < t; i++) {
        unsigned n;
        scanf("%u", &n);

        unsigned count = 0;

        while (5 <= n - count)
        {
            printf("++++ ");
            count += 5;
        }

        for (; count < n; count++) {
            printf("|");
        }

        printf("\n");
    }

    return 0;
}
