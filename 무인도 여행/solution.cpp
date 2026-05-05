#include <algorithm>
#include <string>
#include <functional>
#include <vector>

#define M_MAX       100
#define N_MAX       100

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<int> solution(vector<string> maps)
{
    int m = maps.size();
    int n = maps[0].length();

    bool check[M_MAX][N_MAX] = {false};

    function<unsigned(int, int)> explore;
    explore = [=, &explore, &check](int i, int j)
    {
        check[i][j] = true;

        unsigned amount = maps[i][j] - '0';
        for (int di = 0; di < 4; di++) {
            if (0 <= i + dr[di] && i + dr[di] < m
               && 0 <= j + dc[di] && j + dc[di] < n
               && maps[i + dr[di]][j + dc[di]] != 'X'
               && !check[i + dr[di]][j + dc[di]]) {
                   amount += explore(i + dr[di], j + dc[di]);
               }
        }

        return amount;
    };

    vector<int> answer;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            if (maps[i][j] != 'X' && !check[i][j]) {
                auto maxNumberOfStay = explore(i, j);
                answer.push_back(static_cast<int>(maxNumberOfStay));
            }
        }
    }

    if (answer.empty()) {
        return {-1};
    } else {
        sort(answer.begin(), answer.end());
        return answer;
    }
}
