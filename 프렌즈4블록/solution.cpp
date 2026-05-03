#include <algorithm>
#include <string>
#include <vector>

#define M_MAX       30
#define N_MAX       30

using namespace std;

int solution(int m, int n, vector<string> board)
{
    vector<unsigned char> blockCount(n, m);
    while (true)
    {
        bool checks[M_MAX][N_MAX] = {false};
        bool isDeleted = false;

        for (int i = 0; i < n - 1; i++) {
            int row = m - min(blockCount[i], blockCount[i + 1]);
            while (row < m - 1)
            {
                if (board[row][i] == board[row][i + 1] && board[row][i] == board[row + 1][i + 1] && board[row][i] == board[row + 1][i]) {
                    checks[row][i] = checks[row][i + 1] = checks[row + 1][i + 1] = checks[row + 1 ][i] = true;
                    isDeleted = true;
                }

                row++;
            }
        }

        for (int i = 0; i < n; i++) {
            blockCount[i] = 0;
            for (int row = m - 1; row >= 0; row--) {
                if (board[row][i] && !checks[row][i]) {
                    board[m - ++blockCount[i]][i] = board[row][i];
                }
            }
            for (int row = 0; row < m - blockCount[i]; row++) {
                board[row][i] = '\0';
            }
        }

        if (!isDeleted) {
            break;
        }
    }

    int answer = m * n;
    for (int i = 0; i < n; i++) {
        answer -= blockCount[i];
    }

    return answer;
}
