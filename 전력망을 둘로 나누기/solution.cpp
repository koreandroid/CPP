#include <cmath>
#include <functional>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    vector<int> *neighborLists = new vector<int>[n];
    for (const auto& wire : wires) {
        neighborLists[wire[0] - 1].push_back(wire[1] - 1);
        neighborLists[wire[1] - 1].push_back(wire[0] - 1);
    }

    int answer = n - 2;

    function<int(int, int)> dive;
    dive = [&](int ni, int pi)
    {
        int count = 1;
        for (int neighbor : neighborLists[ni]) {
            if (neighbor != pi) {
                count += dive(neighbor, ni);
            }
        }

        int diff = abs(2 * count - n);
        if (diff < answer) {
            answer = diff;
        }

        return count;
    };

    // Treat node 0 as the root and calculate the size of each subtree connected to it.
    for (int neighbor : neighborLists[0]) {
        dive(neighbor, 0);
    }

    delete[] neighborLists;

    return answer;
}
