#include <cstdio>
#include <algorithm>

#define N_MAX 1000

int main()
{
    int n;
    scanf("%d", &n);

    if (!(2 <= n && n <= N_MAX)) {
        printf("The value of N is invalid. It should be between 2 and %d.\n", N_MAX);
        return -1;
    }

    unsigned * const locations = new unsigned[n];
    for (int i = 0; i < n; i++) {
        scanf("%u", &locations[i]);
    }

    int min = locations[1] - locations[0];
    unsigned count = 1;
    for (int i = 2; i < n; i++) {
        int dist = locations[i] - locations[i - 1];
        if (dist < min) {
            min = dist;
            count = 1;
        } else if (dist == min) {
            count++;
        }
    }

    printf("%u", count);

    delete[] locations;

    return 0;
}
