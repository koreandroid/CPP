#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int getCollisionRiskCount(const pair<int, int> *, int);

int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    int n = points.size();
    int x = routes.size();

    pair<int, int> *currLocationList = new pair<int, int>[x];
    for (int i = 0; i < x; i++) {
        int pi = routes[i][0] - 1;
        currLocationList[i].first = points[pi][0] - 1;      // are initial row indices
        currLocationList[i].second = points[pi][1] - 1;     // are initial column indices
    }

    stack<pair<int, int>> *nextLocationStackList = new stack<pair<int, int>>[x];
    for (int i = 0; i < x; i++) {
        for_each(routes[i].crbegin(), routes[i].crend(), [=](int p) {
            nextLocationStackList[i].push({points[p - 1][0] - 1, points[p - 1][1] - 1});
        });
    }

    int answer = 0;
    while (true)
    {
        answer += getCollisionRiskCount(currLocationList, x);

        unsigned finishedCount = 0;
        for (int i = 0; i < x; i++) {
            if (currLocationList[i].first == -1) {
                finishedCount++;
                continue;
            }

            auto nextLocation = nextLocationStackList[i].top();
            if (currLocationList[i].first == nextLocation.first && currLocationList[i].second == nextLocation.second) {
                nextLocationStackList[i].pop();
                if (nextLocationStackList[i].empty()) {
                    currLocationList[i].first = currLocationList[i].second = -1;

                    finishedCount++;
                    continue;
                }

                nextLocation = nextLocationStackList[i].top();
                if (currLocationList[i].first != nextLocation.first && currLocationList[i].second != nextLocation.second) {
                    nextLocationStackList[i].push({nextLocation.first, currLocationList[i].second});
                }
            }

            nextLocation = nextLocationStackList[i].top();
            int dr = nextLocation.first - currLocationList[i].first;
            int dc = nextLocation.second - currLocationList[i].second;
            if (dr > 0) {
                currLocationList[i].first++;
            } else if (dr < 0) {
                currLocationList[i].first--;
            } else if (dc > 0) {
                currLocationList[i].second++;
            } else if (dc < 0) {
                currLocationList[i].second--;
            }
        }

        if (finishedCount == x) {
            break;
        }
    }

    delete[] currLocationList;
    delete[] nextLocationStackList;

    return answer;
}

int getCollisionRiskCount(const pair<int, int> *currLocationList, int x)
{
    unordered_map<string, int> currLocationStrToCount;
    for (int i = 0; i < x; i++) {
        if (currLocationList[i].first != -1) {
            currLocationStrToCount[to_string(currLocationList[i].first) + "," + to_string(currLocationList[i].second)]++;
        }
    }

    int count = 0;
    for (const auto& [key, value] : currLocationStrToCount) {
        if (value >= 2) {
            count++;
        }
    }

    return count;
}
