#include <cstdio>
#include <algorithm>
#include <vector>

unsigned long long calculate1dTotalDistance(std::vector<unsigned>&);

int main() {
    int n;
    std::vector<unsigned> streets, avenues;

    // Get an input for the value N, which is between 2 and 200000.
    scanf("%d", &n);

    streets.reserve(n);
    avenues.reserve(n);

    for (int i = 0; i < n; i++) {
        unsigned s, a;
        scanf("%u%u", &s, &a);

        streets.push_back(s);
        avenues.push_back(a);
    }

    unsigned long long totalDistance = 0;

    std::sort(streets.begin(), streets.end());
    totalDistance += calculate1dTotalDistance(streets);

    std::sort(avenues.begin(), avenues.end());
    totalDistance += calculate1dTotalDistance(avenues);

    printf("%llu", totalDistance);

    return 0;
}

unsigned long long calculate1dTotalDistance(std::vector<unsigned>& numbers) {
    unsigned long long totalDistance = 0;       // One-dimensional total distance.

    unsigned long long accumSum = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        totalDistance += (unsigned long long)i * numbers[i] - accumSum;

        accumSum += numbers[i];
    }

    return totalDistance;
}
