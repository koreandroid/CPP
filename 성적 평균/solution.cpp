#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

void calculateAccumSums(std::vector<unsigned>&, const int);

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    std::vector<unsigned> accumSums;

    calculateAccumSums(accumSums, n);

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        double avg = round(100.0 * (accumSums[b] - accumSums[a - 1]) / (b - a + 1)) / 100;
        printf("%.2lf\n", avg);
    }

    return 0;
}

void calculateAccumSums(std::vector<unsigned>& accumSums, const int n)
{
    accumSums.reserve(n + 1);

    accumSums.push_back(0);
    for (int i = 1; i <= n; i++) {
        unsigned score;
        scanf("%u", &score);

        accumSums.push_back(accumSums[i - 1] + score);
    }
}
