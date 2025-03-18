#include <cstdio>

void processAttack(unsigned * const);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    unsigned * const criminalCounts = new unsigned[n]();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gridValue;
            scanf("%d", &gridValue);

            criminalCounts[i] += gridValue;
        }
    }

    processAttack(criminalCounts);
    processAttack(criminalCounts);

    unsigned answer = 0;
    for (int i = 0; i < n; i++) {
        answer += criminalCounts[i];
    }

    printf("%u", answer);

    delete[] criminalCounts;

    return 0;
}

void processAttack(unsigned * const criminalCounts)
{
    unsigned l, r;
    scanf("%u%u", &l, &r);

    for (unsigned row = l; row <= r; row++) {
        if (criminalCounts[row - 1]) {
            criminalCounts[row - 1]--;
        }
    }
}
