#include <cstdio>
#include <algorithm>

bool isTriomino(std::pair<unsigned, unsigned> *);

int main() {
    int n;

    // Get an input for the value N, which is between 1 and 10.
    scanf("%d", &n);

    bool result = true;

    auto triominoGrids = new std::pair<unsigned, unsigned>[((1 << 2 * n) - 1) / 3][3];
    unsigned gridCounts[((1 << 2 * n) - 1) / 3] = {0};

    unsigned zeroCount = 0;
    for (unsigned i = 0; i < 1 << n; i++) {
        unsigned j;
        for (j = 0; j < 1 << n; j++) {
            unsigned c;
            scanf("%u", &c);

            if (c == 0 && ++zeroCount == 2) break;
            else if (c) {
                if (gridCounts[c - 1] == 3) break;

                triominoGrids[c - 1][gridCounts[c - 1]++] = std::make_pair(i, j);
            }
        }

        if (j != 1 << n) {
            result = false;
            break;
        }
    }

    if (result) {
        for (int i = 0; i < ((1 << 2 * n) - 1) / 3; i++) {
            std::sort(triominoGrids[i], triominoGrids[i] + 3);

            if (!isTriomino(triominoGrids[i])) {
                result = false;
                break;
            }
        }
    }

    printf("%d", result);

    delete[] triominoGrids;

    return 0;
}

bool isTriomino(std::pair<unsigned, unsigned> *grids) {
    if ((grids[1].first == grids[0].first && grids[1].second == grids[0].second + 1 &&
        grids[2].first == grids[0].first + 1 && grids[2].second == grids[0].second) ||
        (grids[1].first == grids[0].first && grids[1].second == grids[0].second + 1 &&
        grids[2].first == grids[0].first + 1 && grids[2].second == grids[0].second + 1) ||
        (grids[1].first == grids[0].first + 1 && grids[1].second == grids[0].second &&
        grids[2].first == grids[0].first + 1 && grids[2].second == grids[0].second + 1) ||
        (grids[1].first == grids[0].first + 1 && grids[1].second + 1 == grids[0].second &&
        grids[2].first == grids[0].first + 1 && grids[2].second == grids[0].second)) {
        return true;
    }

    return false;
}
